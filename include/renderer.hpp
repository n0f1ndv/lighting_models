#pragma once

#include "shader.hpp"
#include "primitives.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer(Shader* shader);
    ~Renderer();

    void Draw();

private:
    Shader* shader;

    GLuint vao;
    GLuint vbo;
    GLuint ebo;
};