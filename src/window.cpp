#include "window.hpp"

#include <iostream>

Window::Window(int width, int height)
    : width{width}
    , height{height} {
    Init();
}

Window::~Window() {
    delete clock;

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

    clock = new Clock();
}

void Window::Loop() {
    while (!glfwWindowShouldClose(window)) {
        clock->CalculateDelta();

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
