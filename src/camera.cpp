#include "camera.hpp"

#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

Camera::Camera(Shader* shader, int width, int height) 
    : shader{shader} {
    Init(width, height);
}

void Camera::Init(int width, int height) {
    glUseProgram(shader->program);

    position = glm::vec3(0.0f, 0.0f, -10.0f);
    shader->SetUniformVec3fv("camera_position", position);

    view = glm::mat4(1.0f);
    view = glm::translate(view, position);
    shader->SetUniformMatrix4fv("view", view);

    projection = glm::perspective(glm::pi<float>() * 0.25f, (float) width / (float) height, 0.1f, 50.0f);
    shader->SetUniformMatrix4fv("projection", projection);
}

Camera::~Camera() {

}