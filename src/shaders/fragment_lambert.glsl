#version 330

in vec3 normal;
in vec3 light_direction;

uniform vec3 model_color;

void main(void) {
    // dot(L, N) is simply |L||N|cosa so when a is near pi/2 then reflected light is equal to zero
    // when a is closer to 0 then the light is reflected
    // a is an angle between N and L
    float diffuse = clamp(dot(light_direction, normal), 0.0, 1.0);

    gl_FragColor = vec4(diffuse * model_color, 1.0);
}