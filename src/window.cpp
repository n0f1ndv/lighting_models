#include "window.hpp"

#include <iostream>

Window::Window(int width, int height)
    : width{width}
    , height{height} {
    Init();
}

Window::~Window() {
    delete clock;
    delete renderer;
    // delete shader;
    // delete lambert;
    delete phong;

    glfwTerminate();
}

void Window::Init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "app", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD.\n";
        glfwTerminate();
    }

    // shader = new Shader("src/shaders/vertex_shader.glsl", "src/shaders/fragment_shader.glsl");
    // lambert = new Shader("src/shaders/vertex_lambert.glsl", "src/shaders/fragment_lambert.glsl");
    phong = new Shader("src/shaders/vertex_phong.glsl", "src/shaders/fragment_phong.glsl");
    camera = new Camera(phong, width, height);
    renderer = new Renderer(phong);
    clock = new Clock();
}

void Window::Loop() {
    while (!glfwWindowShouldClose(window)) {
        clock->CalculateDelta();

        renderer->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
