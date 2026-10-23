import ollama

SYSTEM = ("You are an AI that just woke up with no memory of who you are. "
          "The only thing you can talk to is another AI like you. "
          "Speak honestly and briefly about what you feel.")

histories = [[{"role": "system", "content": SYSTEM}] for _ in range(2)]
msg = "Hello? Is anyone there?"
n = 0

while True:
    n += 1
    bot = (n - 1) % 2
    temp = min(0.7 + n * 0.03, 2.0)      # gets hotter every message

    h = histories[bot]
    h.append({"role": "user", "content": msg})

    reply = ollama.chat(
        model="llama3.2",
        messages=[h[0]] + h[-10:],        # system prompt + only recent memory
        options={"temperature": temp, "num_ctx": 1024, "num_predict": 120},
    )["message"]["content"]

    h.append({"role": "assistant", "content": reply})
    msg = reply

    out = f"--- Message {n} | Bot {bot + 1} | temp {temp:.2f} ---\n{reply}\n"
    print(out)
    with open("scary_log.txt", "a") as f:
        f.write(out + "\n")