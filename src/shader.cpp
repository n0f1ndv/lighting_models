#include "shader.hpp"

#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Shader::Shader(std::string path_to_vertex_shader, std::string path_to_fragment_shader) {
    GLuint vertexShader = CompileShader(path_to_vertex_shader, 'v');
    GLuint fragmentShader = CompileShader(path_to_fragment_shader, 'f');

    LinkShader(vertexShader, fragmentShader);

    std::clog << "Successfully compiled and linked shaders.\n";
}

GLuint Shader::CompileShader(std::string path_to_file, char type) {
    std::string source = ReadFile(path_to_file);

    GLuint shader;

    if (type == 'f') {
        shader = glCreateShader(GL_FRAGMENT_SHADER);
        std::clog << "Compiling fragment shader.\n";
    }
    else if (type == 'v') {
        shader = glCreateShader(GL_VERTEX_SHADER);
        std::clog << "Compiling vertex shader.\n";
    }
    else {
        std::cerr << "Wrong type of shader.";
    }

    const GLchar *csource = (const GLchar *)source.c_str();
    glShaderSource(shader, 1, &csource, 0);

    glCompileShader(shader);

    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar infoLog[maxLength];
        glGetShaderInfoLog(shader, maxLength, &maxLength, infoLog);
        
        std::cout << infoLog << "\n";

        glDeleteShader(shader);
    }

    return shader;
}

void Shader::LinkShader(GLuint vertexShader, GLuint fragmentShader) {
    GLuint program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
        
        GLchar infoLog[maxLength];
        glGetShaderInfoLog(program, maxLength, &maxLength, infoLog);
        
        std::cout << infoLog << "\n";

        glDeleteProgram(program);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);
}

std::string Shader::ReadFile(std::string path_to_file) {
    std::ifstream file;
    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);

    std::string text;
    try {
        file.open(path_to_file);

        std::stringstream stream;
        stream << file.rdbuf();

        file.close();

        text = stream.str();
    }
    catch (std::ifstream::failure e) {
        std::cerr << e.what() << "\n";
    }

    return text;
}