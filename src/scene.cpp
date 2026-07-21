#include "scene.hpp"

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

#include <iostream>

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
    , scale{scale}
    , model{glm::mat4(1.0f)} {}

Scene::Scene(Shader* shader) 
    : shader{shader} {
    // Initial scene state
    PhongLight light_source = PhongLight(
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, -3.0f),
        0.25f,
        0.8f,
        0.3f,
        8
    );

    Object cube = Object(
        glm::vec3(0.0f, 1.0f, 1.0f),
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

    // Recently added element is the last one so I pass the last index as an id
    UpdatePhongLight(lights.size() - 1);    
}

void Scene::UpdatePhongLight(int id) {
    shader->Use();
    shader->SetUniformVec3fv("light_color",                 lights[id].light_color);
    shader->SetUniformVec3fv("light_position",              lights[id].light_position);
    shader->SetUniform1f("ambient_reflection_constant",     lights[id].ambient_reflection_constant);
    shader->SetUniform1f("diffuse_reflection_constant",     lights[id].diffuse_reflection_constant);
    shader->SetUniform1f("specular_reflection_constant",    lights[id].specular_reflection_constant);
    shader->SetUniform1i("shininess_constant",              lights[id].shininess_constant);
}

void Scene::AddObject(Object& object) {
    objects.push_back(object);

    object.model = glm::translate(object.model, object.position);
    object.model = glm::rotate(object.model, glm::radians(object.rotation_angle), object.rotation_axis);
    object.model = glm::scale(object.model, object.scale);

    // Recently added element is the last one so I the pass last index as an id
    UpdateObject(objects.size() - 1);
}

void Scene::UpdateObject(int id) {
    shader->Use();
    shader->SetUniformMatrix4fv("model", objects[id].model);
    shader->SetUniformVec3fv("model_color", objects[id].model_color);
}