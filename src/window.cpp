#include "window.hpp"

#include <iostream>

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

Window::Window(int width, int height)
    : width{width}
    , height{height} {
    Init();
}

Window::~Window() {
    delete clock;
    delete renderer;
    delete shader;
    delete lambert;
    delete phong;
    delete gui;

    glfwTerminate();
}

void Window::Init() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // I removed main_scale from here when something will break I will put it back here
    window = glfwCreateWindow((int)(width), (int)(height), "app", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD.\n";
        glfwTerminate();
    }
    
    gui = new Gui(window);
    shader = new Shader("src/shaders/vertex_shader.glsl", "src/shaders/fragment_shader.glsl");
    lambert = new Shader("src/shaders/vertex_lambert.glsl", "src/shaders/fragment_lambert.glsl");
    phong = new Shader("src/shaders/vertex_phong.glsl", "src/shaders/fragment_phong.glsl");
    camera = new Camera(phong, width, height);
    renderer = new Renderer(phong);
    clock = new Clock();
}

void Window::Loop() {
    while (!glfwWindowShouldClose(window)) {
        clock->CalculateDelta();

        gui->CreateWindow();

        renderer->Render();

        gui->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
