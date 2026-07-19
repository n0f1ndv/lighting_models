#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <glad/glad.h>

#include <string>

class Shader {
public:
    GLuint program;

    Shader(std::string path_to_vertex_shader, std::string path_to_fragment_shader);
    ~Shader();

    void SetUniformMatrix4fv(std::string uniform_name, glm::mat4& matrix);
    void SetUniformVec3fv(std::string uniform_name, glm::vec3& vector);
    void SetUniform1f(std::string uniform_name, float value);
    void SetUniform1i(std::string uniform_name, int value);

private:
    GLuint CompileShader(std::string path_to_file, char type);
    void LinkShader(GLuint vertesShader, GLuint fragmentShader);

    std::string ReadFile(std::string path_to_file);
};
