#include "scene.hpp"

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

PhongLight::PhongLight(
    glm::vec3 light_color,
    glm::vec3 light_position,
    float ambient_reflection_constant,
    float diffuse_reflection_constant,
    float specular_reflection_constant,
    int shininess_constant
) 
    : light_color{light_color}
    , light_position{light_position}
    , ambient_reflection_constant{ambient_reflection_constant}
    , diffuse_reflection_constant{diffuse_reflection_constant}
    , specular_reflection_constant{specular_reflection_constant}
    , shininess_constant{shininess_constant} {}

Object::Object(
    glm::vec3 model_color,
    glm::vec3 position,
    float rotation_angle,
    glm::vec3 rotation_axis,
    glm::vec3 scale
)
    : model_color{model_color}
    , position{position}
    , rotation_angle{rotation_angle}
    , rotation_axis{rotation_axis}
    , scale{scale} {}

Scene::Scene(Shader* shader) 
    : shader{shader} {
    PhongLight light_source = PhongLight(
        glm::vec3(1.0f, 1.0f, 0.7f),
        glm::vec3(0.0f, 0.0f, -3.0f),
        0.25f,
        0.5f,
        0.5f,
        8
    );

    Object cube = Object(
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        45.0f,
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    );

    AddPhongLight(light_source);
    AddObject(cube);
}

void Scene::AddPhongLight(PhongLight& light) {
    lights.push_back(light);

    // Move this to the public Update member function ig
    shader->Use();
    shader->SetUniformVec3fv("light_color", light.light_color);
    shader->SetUniformVec3fv("light_position", light.light_position);
    shader->SetUniform1f("ambient_reflection_constant", light.ambient_reflection_constant);
    shader->SetUniform1f("diffuse_reflection_constant", light.diffuse_reflection_constant);
    shader->SetUniform1f("specular_reflection_constant", light.specular_reflection_constant);
    shader->SetUniform1i("shininess_constant", light.shininess_constant);
}

void Scene::AddObject(Object& object) {
    objects.push_back(object);

    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, object.position);

    model = glm::rotate(model, glm::radians(object.rotation_angle), object.rotation_axis);

    model = glm::scale(model, object.scale);

    shader->Use();
    shader->SetUniformMatrix4fv("model", model);
    shader->SetUniformVec3fv("model_color", object.model_color);
}
