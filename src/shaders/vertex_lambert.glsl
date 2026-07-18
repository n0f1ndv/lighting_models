#version 330
layout (location = 0) in vec3 attrib_pos;
layout (location = 1) in vec3 attrib_norm;

out vec3 normal;
out vec3 light_direction;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 camera_position;

void main(void) {
    // I need to transform position attribute to world space to make computation on it
    vec3 frag_position = vec3(model * vec4(attrib_pos, 1.0));
    vec3 light_position = camera_position;

    normal = mat3(transpose(inverse(model))) * attrib_norm;
    light_direction = normalize(light_position - frag_position);

    gl_Position = vec4(projection * view * model * vec4(attrib_pos, 1.0));
}