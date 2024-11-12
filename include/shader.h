#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Shader 
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif