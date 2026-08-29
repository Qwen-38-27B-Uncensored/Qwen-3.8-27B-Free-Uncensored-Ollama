#include "../weights/Loader.h"
#include <iostream>
#include <string>

// Qwen 3.8 27B Uncensored Chat - local loop.

extern void runSession(Loader& loader);

int main(int argc, char** argv) {
    LoadOpts opts;
    opts.path = (argc > 1) ? argv[1] : "models/qwen3.8-27b-Q4_K_M.gguf";
    opts.gpuLayers = 40;

    Loader loader;
    if (!loader.open(opts)) {
        std::cerr << loader.lastError() << "\n";
        std::cerr << "run ollama/fetch_weights.py or ollama pull qwen3.8:27b\n";
        return 1;
    }

    std::cout << "Qwen 3.8 27B Uncensored Chat — local, no API\n";
    runSession(loader);
    return 0;
}
