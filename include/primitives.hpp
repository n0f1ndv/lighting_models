#pragma once

#include <glad/glad.h>

// Triangle primitive
const GLfloat TRIANGLE_VERTICES[9] = {
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
        0.0, 0.5, 0.0
    };

const GLuint TRIANGLE_INDICES[3] = {
    0, 1, 2
};

// Rectangle primitive
const GLfloat RECTANGLE_VERTICES[12] = {
    1.0, 1.0, 0.0, 
    1.0, -1.0, 0.0,
    -1.0, -1.0, 0.0,
    -1.0, 1.0, 0.0
};

const GLuint RECTANGLE_INDICES[6] = {
    0, 1, 2, 0, 2, 3
};