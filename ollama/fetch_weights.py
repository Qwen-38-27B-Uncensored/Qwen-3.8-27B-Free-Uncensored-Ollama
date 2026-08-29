#!/usr/bin/env python3
"""Fetch qwen 3.8 27b GGUF for the uncensored desktop chat client."""
import argparse
from pathlib import Path
from huggingface_hub import hf_hub_download

REPO = "bartowski/Qwen3.8-27B-GGUF"
QUANTS = {
    "q4": "Qwen3.8-27B-Q4_K_M.gguf",
    "q5": "Qwen3.8-27B-Q5_K_M.gguf",
    "q8": "Qwen3.8-27B-Q8_0.gguf",
}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--quant", choices=QUANTS, default="q4")
    ap.add_argument("--out", default="./models")
    args = ap.parse_args()
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    print(f"[qwen-3.8-27b] fetching {QUANTS[args.quant]}")
    path = hf_hub_download(REPO, QUANTS[args.quant], local_dir=out)
    print(f"[qwen-3.8-27b] stored at {path}")


if __name__ == "__main__":
    main()
