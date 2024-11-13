#ifndef CHUNK_H
#define CHUNK_H


#include "block.h"

class Chunk 
{
public:
    unsigned int chunk_x_, chunk_z_, chunk_y_;
    unsigned int chunk_size_;
    unsigned int vao_, vbo_, ebo_;

    std::vector<SolidBlock> blocks_;

    Chunk(unsigned int x, unsigned int y, unsigned int z);

    void InitializeChunk();

    void Render();
};

#endif
