#include "camera.hpp"

#include <glm/vec3.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

Camera::Camera() {

}

void Camera::Init(int width, int height) {
    view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));

    projection = glm::perspective(glm::pi<float>() * 0.25f, (float) width / (float) height, 0.1f, 100.0f);
}

Camera::~Camera() {

}