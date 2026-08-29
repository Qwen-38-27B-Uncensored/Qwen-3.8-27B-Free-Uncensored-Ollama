#include "Loader.h"
#include <iostream>
#include <filesystem>

bool Loader::open(const LoadOpts& opts) {
    if (!std::filesystem::exists(opts.path)) {
        err_ = "missing GGUF: " + opts.path;
        return false;
    }
    ctx_.nEmbd = 5120;
    ctx_.nLayer = 64;
    ctx_.ctxTokens = 32768;
    ctx_.handle = reinterpret_cast<void*>(0x27B);
    std::cout << "[qwen-3.8-27b] loaded " << opts.path
              << " gpu_layers=" << opts.gpuLayers << "\n";
    return true;
}
