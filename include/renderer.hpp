#pragma once

#include "shader.hpp"
#include "primitives.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    void Draw();

private:
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    Shader* shader;
};