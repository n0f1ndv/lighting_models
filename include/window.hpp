#pragma once

#include "camera.hpp"
#include "renderer.hpp"
#include "clock.hpp"
#include "gui.hpp"

#include <imgui.h>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Window {
public:
    int height;
    int width;

    Window(int width, int height);
    ~Window();

    void Loop();
    void Terminate();

private:
    GLFWwindow* window;

    Gui* gui;
    Shader* shader;
    Shader* lambert;
    Shader* phong;
    Camera* camera;
    Renderer* renderer;
    Clock* clock;

    void Init();
};
