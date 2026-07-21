#include "gui.hpp"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>

Gui::Gui(GLFWwindow* window)
    : window{window} {
    Init();
}

Gui::~Gui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Gui::Init() {
    const char* glsl_version = nullptr;

    main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor());

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    style.ScaleAllSizes(main_scale);
    style.FontScaleDpi = main_scale;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Gui::CreateWindow() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static int i = 0;
    static float f0 = 0;
    static float f1 = 0;
    static float f2 = 0;
    static int counter = 0;

    ImVec4 col = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    glm::vec3 color = glm::vec3(col.x, col.y, col.z);

    ImGui::Begin("Settings");

    ImGui::Text("Light parameters");

    ImGui::Text("Shininess constant");
    ImGui::SameLine();
    ImGui::SliderInt("shininess", &i, 0, 12);

    ImGui::Text("Ambient reflection constant");
    ImGui::SameLine();
    ImGui::SliderFloat("ambient", &f0, 0.0f, 1.0f);

    ImGui::Text("Diffuse reflection constant");
    ImGui::SameLine();
    ImGui::SliderFloat("diffuse", &f1, 0.0f, 1.0f);

    ImGui::Text("Specular reflection constant");
    ImGui::SameLine();
    ImGui::SliderFloat("specular", &f2, 0.0f, 1.0f);

    ImGui::Text("Light color");
    ImGui::SameLine();
    ImGui::ColorEdit3("light color", (float*)&col);

    ImGui::Text("Light position");
    ImGui::SameLine();
    ImGui::ColorEdit3("light position", (float*)&col);

    ImGui::Text("Model parameters");

    ImGui::Text("Model color");
    ImGui::SameLine();
    ImGui::ColorEdit3("model color", (float*)&col);

    ImGui::End();
}

void Gui::Render() {
    ImGui::Render();

    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}