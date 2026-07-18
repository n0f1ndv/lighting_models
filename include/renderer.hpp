#pragma once

#include "shader.hpp"
#include "primitives.hpp"
#include "clock.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer(Shader* shader);
    ~Renderer();

    void Setup();
    void Render();

private:
    Shader* shader;

    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    glm::mat4 model = glm::mat4(1.0f);
};