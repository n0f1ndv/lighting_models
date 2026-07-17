#version 330
layout (location = 0) in vec3 attrib_pos;

out vec3 v_color;

void main(void) {
    gl_Position = vec4(attrib_pos, 1.0);

    v_color = (attrib_pos + 1) / 2;
}