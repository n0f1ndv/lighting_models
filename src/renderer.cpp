#include "renderer.hpp"

#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

Renderer::Renderer(Shader* shader) 
    : shader{shader} {
    Setup();

    glUseProgram(shader->program);
    glm::vec3 model_color = glm::vec3(1.0f, 0.2f, 0.5f);
    shader->SetUniformVec3fv("model_color", model_color);

    scene = new Scene(shader);
}

void Renderer::Setup() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    // ebo is used for indices drawing
    // glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(CUBE_VERTICES_NORMALS), CUBE_VERTICES_NORMALS, GL_STATIC_DRAW);

    // ebo is used for indices drawing
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(CUBE_INDICES), CUBE_INDICES, GL_STATIC_DRAW);

    // attrib_pos
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(0);

    // attrib_norm
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

Renderer::~Renderer() {
    delete scene;
    delete shader;

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    // ebo is used for indices drawing
    // glDeleteBuffers(1, &ebo);
}

void Renderer::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    model = glm::rotate(model, glm::radians(2.0f), glm::vec3(0.0f, 1.0f, 1.0f));
    shader->SetUniformMatrix4fv("model", model);

    glUseProgram(shader->program);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}