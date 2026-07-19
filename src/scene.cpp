#include "scene.hpp"

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

    AddPhongLight(light_source);
}

void Scene::AddPhongLight(PhongLight& light) {
    lights.push_back(light);

    UpdateLight(light);
}

void Scene::UpdateLight(PhongLight& light) {
    shader->SetUniformVec3fv("light_color", light.light_color);
    shader->SetUniformVec3fv("light_position", light.light_position);
    shader->SetUniform1f("ambient_reflection_constant", light.ambient_reflection_constant);
    shader->SetUniform1f("diffuse_reflection_constant", light.diffuse_reflection_constant);
    shader->SetUniform1f("specular_reflection_constant", light.specular_reflection_constant);
    shader->SetUniform1i("shininess_constant", light.shininess_constant);
}

void Scene::AddObject() {

}

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