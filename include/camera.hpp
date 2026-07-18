#pragma once

#include "shader.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera {
public:
    Camera(Shader* shader, int width, int height);
    ~Camera();
    
    void Init(int width, int height);

private:
    Shader* shader;

    glm::mat4 projection;
    glm::mat4 view;
    glm::vec3 position;
};