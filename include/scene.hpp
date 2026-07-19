#pragma once

#include "shader.hpp"

#include <glm/vec3.hpp>

#include <vector>

class PhongLight {
public:
    glm::vec3 light_color;
    glm::vec3 light_position;
    float ambient_reflection_constant;
    float diffuse_reflection_constant;
    float specular_reflection_constant;
    int shininess_constant;

    PhongLight(
        glm::vec3 light_color,
        glm::vec3 light_position,
        float ambient_reflection_constant,
        float diffuse_reflection_constant,
        float specular_reflection_constant,
        int shininess_constant
    );
};


class Scene {
public:
    Scene(Shader* shader);

    std::vector<PhongLight> lights;

    void UpdateLight(PhongLight& light);
    void AddObject();

private:
    Shader* shader;

    void AddPhongLight(PhongLight& light);
};
