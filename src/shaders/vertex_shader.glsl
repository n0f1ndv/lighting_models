#version 330
layout (location = 0) in vec3 attrib_pos;

out vec3 v_color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void) {
    gl_Position = projection * view * model * vec4(attrib_pos, 1.0);

    v_color = (attrib_pos + 1) / 2;
}