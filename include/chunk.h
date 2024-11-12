#ifndef CHUNK_H
#define CHUNK_H


#include "block.h"

class Chunk 
{
    unsigned int chunk_size_ = chunk_x_ * chunk_y_;
    unsigned int chunk_x_;
    unsigned int chunk_y_;

};

#endif
