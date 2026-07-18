#version 330
layout (location = 0) in vec3 attrib_pos;

out vec3 v_color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 camera_position;

void main(void) {
    vec4 world_position = projection * view * model * vec4(attrib_pos, 1.0);

    float vertex_distance = length(vec4(camera_position, 1.0) - world_position);

    v_color = (attrib_pos * vertex_distance + 1) / 2;

    gl_Position = world_position;
}