#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "../include/shader.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

int main() 
{
    if (!glfwInit()) 
    {
        std::cerr << "Error! Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Scuffed Minecraft", nullptr, nullptr);
    if (!window) 
    {
        std::cerr << "Error! Failed to create window!" << std::endl;
        glfwTerminate();
        return -1;  
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);

    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Error! Failed to initialize GLEW!" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // shader
    Shader shader_program("shaders/vShader.txt", "shaders/fShader.txt");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}