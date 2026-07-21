#pragma once

#include "scene.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Gui {
public:
    float main_scale;

    Gui(GLFWwindow* window, Scene* scene);
    ~Gui();

    void Init();
    void CreateWindow();
    void Render();

private:
    GLFWwindow* window;

    Scene* scene;

    ImGuiIO io;

    ImVec4 light_position;
    ImVec4 light_color;
    ImVec4 model_color;
};