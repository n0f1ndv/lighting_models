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


class Object {
public:
    glm::vec3 model_color;
    glm::vec3 position;
    float rotation_angle;
    glm::vec3 rotation_axis;
    glm::vec3 scale;

    Object(
        glm::vec3 model_color,
        glm::vec3 position,
        float rotation_angle,
        glm::vec3 rotation_axis,
        glm::vec3 scale
    );
};

class Scene {
public:
    Scene(Shader* shader);

    std::vector<PhongLight> lights;
    std::vector<Object> objects;

private:
    Shader* shader;

    void AddObject(Object& object);
    void AddPhongLight(PhongLight& light);
};
