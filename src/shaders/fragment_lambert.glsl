#version 330

in vec3 normal;
in vec3 light_direction;

uniform vec3 model_color;

void main(void) {
    float diffuse = clamp(dot(light_direction, normal), 0.0, 1.0);

    gl_FragColor = vec4(diffuse * model_color, 1.0);
}