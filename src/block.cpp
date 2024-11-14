#include "../include/block.h"

std::vector<float> SolidBlock::GetTransformedVertices() const 
{
    std::vector<float> tranformed_vertices;
    for (int i = 0; i < 120; i += 5) {
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
    for (int i = 0; i < 36; ++i) {
        transformed_indices.push_back(block_indices_[i] + offset);
    }
    return transformed_indices;
}

void SolidBlock::Render(unsigned int &VAO, unsigned int &VBO, unsigned int &EBO) 
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(block_vertices_), block_vertices_, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(block_indices_), block_indices_, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
}