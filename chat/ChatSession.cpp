#include "../weights/Loader.h"
#include <iostream>
#include <string>

void runSession(Loader& loader) {
    auto* ctx = loader.ctx();
    if (!ctx || !ctx->handle) return;

    std::cout << "ctx=" << ctx->ctxTokens << " layers=" << ctx->nLayer << "\n";
    std::cout << "commands: /quit\n\n";

    std::string line;
    while (true) {
        std::cout << "you> ";
        if (!std::getline(std::cin, line) || line == "/quit") break;
        std::cout << "qwen> (stream from 27B uncensored weights)\n\n";
    }
}
