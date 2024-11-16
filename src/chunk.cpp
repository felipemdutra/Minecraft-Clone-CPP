#include "../include/chunk.h"

enum BlockTypes
{
    GRASS_BLOCK,
    STONE_BLOCK
};

Chunk::Chunk()
{
    chunk_x = 5; 
    chunk_y = 5;
    chunk_z = 5;

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &ebo_);

    glBindVertexArray(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);

    InitializeChunk();

    glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(float), vertices_.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(unsigned int), indices_.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

Chunk::~Chunk()
{
    glDeleteVertexArrays(1, &vao_);
    glDeleteBuffers(1, &vbo_);
    glDeleteBuffers(1, &ebo_);
}

void Chunk::InitializeChunk()
{
    SolidBlock block(true);
    block.LoadTexture("assets/stone.png");
    int index = 0;

    for (unsigned int x = 0; x < chunk_x; x++)    
    {
        for (unsigned int y = 0; y < chunk_y; y++)
        {
            for (unsigned int z = 0; z < chunk_z; z++)
            {
                for (int i = 0; i < 120; i += 5)
                {
                    vertices_.push_back(block.block_vertices_[i] + x);
                    vertices_.push_back(block.block_vertices_[i + 1] + y);
                    vertices_.push_back(block.block_vertices_[i + 2] + z);
                    vertices_.push_back(block.block_vertices_[i + 3]);
                    vertices_.push_back(block.block_vertices_[i + 4]);
                }

                for (int i = 0; i < 36; i++)
                {
                    indices_.push_back(block.block_indices_[i] + index);
                }
                
                // 24 vertices per block.
                index += 24;
            }
        }
    }
}

void Chunk::RenderChunk()
{
    glBindVertexArray(vao_);
    glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}