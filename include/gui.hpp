#pragma once

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Gui {
public:
    float main_scale;

    Gui(GLFWwindow* window);
    ~Gui();

    void Init();
    void CreateWindow();
    void Render();

private:
    ImGuiIO io;

    GLFWwindow* window;
};