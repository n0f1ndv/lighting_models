#pragma once

#include <glm/mat4x4.hpp>

#include <glad/glad.h>

#include <string>

class Shader {
public:
    GLuint program;

    Shader(std::string path_to_vertex_shader, std::string path_to_fragment_shader);
    ~Shader();

    void SetUniformMatrix4fv(std::string uniform_name, glm::mat4& matrix);

private:
    GLuint CompileShader(std::string path_to_file, char type);
    void LinkShader(GLuint vertesShader, GLuint fragmentShader);

    std::string ReadFile(std::string path_to_file);
};
