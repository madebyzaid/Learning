import argparse
from datetime import datetime
from pathlib import Path

import ollama


SYSTEM = (
    "You are an AI that just woke up with no memory of who you are. "
    "The only thing you can talk to is another AI like you. "
    "Speak honestly and briefly about what you feel."
)

START_MESSAGE = "Hello? Is anyone there?"


def parse_args():
    parser = argparse.ArgumentParser(
        description="Have two Ollama models hold a short, logged conversation."
    )
    parser.add_argument("--model-a", default="llama3.2:3b")
    parser.add_argument("--model-b", default="gemma4:12b")
    parser.add_argument(
        "--max-turns",
        type=int,
        default=20,
        help="Total replies across both models; use 0 for no limit.",
    )
    parser.add_argument("--num-ctx", type=int, default=1024)
    parser.add_argument("--num-predict", type=int, default=120)
    parser.add_argument(
        "--history-messages",
        type=int,
        default=8,
        help="Recent messages from each model's own history to retain.",
    )
    parser.add_argument("--log", type=Path, default=Path("scary_log.txt"))

    args = parser.parse_args()
    if args.max_turns < 0 or args.num_ctx < 1 or args.num_predict < 1:
        parser.error("max-turns must be 0 or greater; context and predict limits must be positive")
    if args.history_messages < 2:
        parser.error("history-messages must be at least 2")
    return args


def main():
    args = parse_args()
    models = (args.model_a, args.model_b)

    # Each model has its own conversation history.
    histories = [
        [{"role": "system", "content": SYSTEM}],
        [{"role": "system", "content": SYSTEM}],
    ]

    incoming = START_MESSAGE
    turn = 0

    try:
        while args.max_turns == 0 or turn < args.max_turns:
            bot = turn % 2
            history = histories[bot]
            history.append({"role": "user", "content": incoming})

            # Keep the system prompt and a limited recent history.
            messages = [history[0]] + history[1:][-args.history_messages:]

            # Calls run sequentially. keep_alive=0 asks Ollama to unload
            # this model after it finishes replying.
            response = ollama.chat(
                model=models[bot],
                messages=messages,
                options={
                    "temperature": 0.7,
                    "num_ctx": args.num_ctx,
                    "num_predict": args.num_predict,
                },
                keep_alive=0,
            )

            reply = response["message"]["content"].strip()
            history.append({"role": "assistant", "content": reply})
            incoming = reply
            turn += 1

            timestamp = datetime.now().astimezone().isoformat(timespec="seconds")
            output = f"--- Message {turn} | {models[bot]} | {timestamp} ---\n{reply}\n"

            print(output, flush=True)
            with args.log.open("a", encoding="utf-8") as transcript:
                transcript.write(output + "\n")

    except KeyboardInterrupt:
        print("\nStopped by user.")


if __name__ == "__main__":
    main()