#pragma once

#include <glad/glad.h>

#include <GLFW/glfw3.h>

class Clock {
public:
    double time;
    double delta_time;

    Clock();

    void CalculateDelta();

private:
    double last_frame;
    double current_frame;
};
