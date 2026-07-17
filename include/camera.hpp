#pragma once

#include <glm/mat4x4.hpp>

class Camera {
public:
    Camera();
    ~Camera();
    
    void Init(int width, int height);

private:
    glm::mat4 projection;
    glm::mat4 view;
};