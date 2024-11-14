#include "../include/chunk.h"

Chunk::Chunk(unsigned int x, unsigned int z, unsigned int y)  
: chunk_x_(x), chunk_z_(z), chunk_y_(y)
{
    chunk_size_ = x * y * z;

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &ebo_);

    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);

    InitializeChunk();
} 

void Chunk::InitializeChunk()
{
    for (unsigned int x = 0; x < chunk_x_; ++x)
    {
        for (unsigned int y = 0; y < chunk_y_; ++y)
        {
            for (unsigned int z = 0; z < chunk_z_; ++z) 
            {
                blocks_.emplace_back(glm::vec3(x, y, z));
            }
        }
    }
}

void Chunk::Render() 
{
    
}