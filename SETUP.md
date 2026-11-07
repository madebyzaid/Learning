# Setup Guide

How to set up a laptop to work on this repo. Follow this on any new machine (or after reinstalling WSL).

## 1. Install the basics (in WSL)

Editor: VS Code with the **WSL** extension.

All programming work happens inside WSL, not in Windows directly.

```bash
sudo apt update
sudo apt install -y git build-essential python3 python3-venv python3-pip
```

`build-essential` provides `gcc` and `g++` for the `.c` and `.cpp` files.

## 2. Git setup

### Git alias: `git upload`

Stages everything, commits with the given message, and pushes. Errors out if no message is given.

```bash
git config --global alias.upload '!f() { [ "$1" = "-m" ] && [ -n "$2" ] || { echo "Usage: git upload -m \"message\""; return 1; }; git add . && git commit -m "$2" && git push; }; f'
```

Usage:

```bash
git upload -m "Added linked list programs"
```

It only pushes. When switching devices, run `git pull` first.

## 3. Clone the repo

```bash
cd ~
git clone https://github.com/madebyzaid/Learning
cd Learning
```
## 4. Python virtual environment

`myenv/` is git-ignored, so each laptop builds its own.

```bash
cd ~/Learning
python3 -m venv myenv
source ~/Learning/myenv/bin/activate
pip install -r requirements.txt   # if a requirements.txt exists
```

After installing new packages, update the list so the other laptop can match:

```bash
pip freeze > requirements.txt
```

## 5. The `run` command

A custom WSL command: `run filename.extension` compiles (if needed) and then runs the file.
Allowed extensions: `.py`, `.c`, `.cpp`.

Example:

```bash
run hello.c
run script.py
```

The script itself lives on each machine, not in this repo. To keep both laptops identical, paste its contents below (or commit it under `dotfiles/`):

```bash
run() {
  if [ -z "$1" ]; then
    echo "Usage: run <file.py|file.c|file.cpp>"
    return 1
  fi

  local file="$1"
  local name="${file%.*}"
  local ext="${file##*.}"
  if [ ! -f "$file" ]; then
    echo "run: '$file' not found"
    return 1
  fi

  case "$ext" in
    py)  python3 "$file" ;;
    cpp) g++ "$file" -o "$name" && "./$name" ;;
    c)   gcc "$file" -o "$name" && "./$name" ;;
    *)   echo "run: unsupported file type '.$ext'"; return 1 ;;
  esac
}
```

## 6. VS Code settings

Open `Ctrl+Shift+P` -> "Preferences: Open User Settings (JSON)" and add:

```json
{
    "files.autoSave": "afterDelay",
    "editor.cursorStyle": "line",
    "editor.overtypeCursorStyle": "line",
    "terminal.integrated.cursorStyle": "line"
}
```

- Auto save keeps `run` from compiling a stale, unsaved version of a file.
- Cursor settings keep the vertical bar cursor in the editor and the terminal.
- If a setting doesn't apply inside the WSL window, also set it under the **Remote [WSL]** tab.

## 7. Working from two laptops

1. Before you start: `git pull`
2. Work, then: `git upload -m "message"`
3. Don't leave work uncommitted or unpushed on the laptop you're leaving.
4. If a push is rejected, run `git pull`, resolve any conflicts, then push again.
5. `git status` shows uncommitted changes and whether you're ahead or behind.

## 8. About the `.gitignore`

The repo ignores things that shouldn't be shared between machines:

- Compiled output: extensionless binaries, `*.exe`, `*.out`, `*.o`, etc.
- Media: images and videos
- ML models and exported model folders
- Datasets (`*.csv`)
- Python/environment junk: `__pycache__/`, `*.pyc`, `myenv/`, `venv/`, `.venv/`, `.ipynb_checkpoints/`
- Windows `Zone.Identifier` download markers

Extensionless files like `README`, `LICENSE`, `Makefile` and `Dockerfile` are explicitly allowed.
To force-add an ignored file, use `git add -f path/to/file`.

## Checklist for a new laptop

- [ ] Install WSL and VS Code (with the WSL extension)
- [ ] `apt install` the basics
- [ ] Set git name/email and add an SSH key to GitHub
- [ ] Add the `git upload` alias
- [ ] Clone the repo to `~/Learning`
- [ ] Create `myenv` and install requirements
- [ ] Recreate the `run` command
- [ ] Add the VS Code settings
