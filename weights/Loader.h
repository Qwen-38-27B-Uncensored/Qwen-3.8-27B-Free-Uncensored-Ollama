#pragma once
#include <string>
#include <vector>

struct LoadOpts {
    std::string path;
    int gpuLayers = 40;
    int threads = 8;
};

struct ModelContext {
    void* handle = nullptr;
    int nEmbd = 0;
    int nLayer = 0;
    size_t ctxTokens = 32768;
};

class Loader {
public:
    bool open(const LoadOpts& opts);
    ModelContext* ctx() { return &ctx_; }
    std::string lastError() const { return err_; }

private:
    ModelContext ctx_;
    std::string err_;
};
