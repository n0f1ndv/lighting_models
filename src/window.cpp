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

    renderer = new Renderer();
    clock = new Clock();
}

void Window::Loop() {
    while (!glfwWindowShouldClose(window)) {
        clock->CalculateDelta();

        renderer->Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
