#version 330

in vec3 frag_position;

uniform vec3 model_color;

void main(void) {
    gl_FragColor = vec4(frag_position, 1.0);
}