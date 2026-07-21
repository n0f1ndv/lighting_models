#pragma once

#include "shader.hpp"
#include "primitives.hpp"
#include "clock.hpp"
#include "scene.hpp"
#include "gui.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer(GLFWwindow* window, Shader* shader);
    ~Renderer();

    void Setup();
    void Render();

private:
    GLFWwindow* window;

    Shader* shader;
    Scene* scene;
    Gui* gui;

    GLuint vao;
    GLuint vbo;
    // ebo is used for indices drawing
    // GLuint ebo;

    glm::mat4 model = glm::mat4(1.0f);
};