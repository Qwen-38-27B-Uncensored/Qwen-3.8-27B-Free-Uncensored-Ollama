#!/usr/bin/env python3
"""Boot Ollama with qwen 3.8 27b for this desktop client."""
import subprocess
import sys

MODEL = "qwen3.8:27b"


def main():
    print("[qwen-3.8-27b] ensuring ollama is up")
    r = subprocess.run(["ollama", "list"], capture_output=True, text=True)
    if r.returncode != 0:
        sys.exit("install ollama first: https://ollama.com")
    if MODEL not in r.stdout:
        print(f"[qwen-3.8-27b] pulling {MODEL}")
        subprocess.check_call(["ollama", "pull", MODEL])
    print("[qwen-3.8-27b] ready — pick Ollama in Settings")


if __name__ == "__main__":
    main()
