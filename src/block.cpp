#include "../include/block.h"

std::vector<float> SolidBlock::GetTransformedVertices() const 
{
    std::vector<float> tranformed_vertices;
    for (int i = 0; i < 120; i++) {
        tranformed_vertices.push_back(block_vertices_[i] + position_.x);
        tranformed_vertices.push_back(block_vertices_[i + 1] + position_.y);
        tranformed_vertices.push_back(block_vertices_[i + 2] + position_.z);
        // Texture coordinates
        tranformed_vertices.push_back(block_vertices_[i + 3]);
        tranformed_vertices.push_back(block_vertices_[i + 4]);
    }
    return tranformed_vertices;
}

std::vector<unsigned int> SolidBlock::GetIndices(unsigned int offset) const
{
    std::vector<unsigned int> transformed_indices;
    for (int i = 0; i < 36; i++) {
        transformed_indices.push_back(block_indices_[i] + offset);
    }
    return transformed_indices;
}

