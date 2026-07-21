#include "gui.hpp"

#include <glm/vec3.hpp>

Gui::Gui(GLFWwindow* window, Scene* scene)
    : window{window}
    , scene{scene} {
    light_color = ImVec4(
        scene->lights[0].light_color.x,
        scene->lights[0].light_color.y,
        scene->lights[0].light_color.z,
        1.0f
    );

    light_position= ImVec4(
        scene->lights[0].light_position.x,
        scene->lights[0].light_position.y,
        scene->lights[0].light_position.z,
        1.0f
    );

    model_color = ImVec4(
        scene->objects[0].model_color.x,
        scene->objects[0].model_color.y,
        scene->objects[0].model_color.z,
        1.0f
    );

    Init();
}

Gui::~Gui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Gui::Init() {
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

    const char* glsl_version = nullptr;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Gui::CreateWindow() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Settings");

    ImGui::Text("Light parameters");

    ImGui::Text("Shininess constant");
    ImGui::SameLine();
    ImGui::SliderInt("shininess", &scene->lights[0].shininess_constant, 0, 12);

    ImGui::Text("Ambient reflection constant");
    ImGui::SameLine();
    ImGui::SliderFloat("ambient", &scene->lights[0].ambient_reflection_constant, 0.0f, 1.0f);

    ImGui::Text("Diffuse reflection constant");
    ImGui::SameLine();
    ImGui::SliderFloat("diffuse", &scene->lights[0].diffuse_reflection_constant, 0.0f, 1.0f);

    ImGui::Text("Specular reflection constant");
    ImGui::SameLine();
    ImGui::SliderFloat("specular", &scene->lights[0].specular_reflection_constant, 0.0f, 1.0f);

    ImGui::Text("Light color");
    ImGui::SameLine();
    ImGui::ColorEdit3("light color", &scene->lights[0].light_color.x);

    ImGui::Text("Light position");
    ImGui::SameLine();
    ImGui::SliderFloat3("light position", &scene->lights[0].light_position.x, -5.0f, 5.0f);

    ImGui::Text("Model parameters");

    ImGui::Text("Model color");
    ImGui::SameLine();
    ImGui::ColorEdit3("model color", &scene->objects[0].model_color.x);

    scene->UpdatePhongLight(0);
    scene->UpdateObject(0);

    ImGui::End();
}

void Gui::Render() {
    ImGui::Render();

    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}