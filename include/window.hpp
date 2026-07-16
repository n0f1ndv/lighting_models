#pragma once

#include "clock.hpp"

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

    Clock* clock;

    void Init();
};
