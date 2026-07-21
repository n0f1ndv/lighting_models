#include "clock.hpp"

#include <iostream>

Clock::Clock() 
    : time{0}
    , delta_time{0}
    , last_frame{0}
    , current_frame{0} {}

void Clock::CalculateDelta() {
    current_frame = glfwGetTime();

    time += current_frame;
    delta_time = current_frame - last_frame;
    last_frame = current_frame;

    glfwSetTime(0);
}
