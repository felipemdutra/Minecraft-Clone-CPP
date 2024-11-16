#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"

class Chunk
{
public:
    unsigned int chunk_x, chunk_y, chunk_z;
    unsigned int vao_, vbo_, ebo_;

    std::vector<float> vertices_;
    std::vector<unsigned int> indices_; 

    Chunk();
    ~Chunk();

    void InitializeChunk();

    void RenderChunk();
};

#endif
