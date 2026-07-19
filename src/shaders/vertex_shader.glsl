#version 330
layout (location = 0) in vec3 attrib_pos;

out vec3 frag_position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 camera_position;

void main(void) {
    frag_position = vec3(model * vec4(attrib_pos, 1.0));

    gl_Position = projection * view * model * vec4(attrib_pos, 1.0);;
}