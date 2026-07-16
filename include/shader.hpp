#pragma once

#include <glad/glad.h>

#include <string>

class Shader {
public:
    GLuint id;

    Shader(std::string path_to_vertex_shader, std::string path_to_fragment_shader);

private:
    GLuint CompileShader(std::string path_to_file, char type);
    void LinkShader(GLuint vertesShader, GLuint fragmentShader);

    std::string ReadFile(std::string path_to_file);
};
