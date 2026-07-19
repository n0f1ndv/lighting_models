#version 330

in vec3 normal;
in vec3 light_position;
in vec3 viewer_position;
in vec3 frag_position;

uniform vec3 model_color;

void main(void) {
    vec3 light_color = vec3(1.0, 1.0, 0.7);

    // ambient
    float ambient_reflection_constant = 0.3;

    vec3 ambient = ambient_reflection_constant * light_color;

    // diffuse
    float diffuse_reflection_constant = 0.9;

    vec3 light_direction = normalize(light_position - frag_position);                           // vector from surface to light source
    float diff = diffuse_reflection_constant * clamp(dot(light_direction, normal), 0.0, 1.0);

    vec3 diffuse = diff * light_color;

    // specular
    float specular_reflection_constant = 0.5;
    float shininess_constant = pow(2, 6);

    vec3 reflected_ray = reflect(-light_direction, normal);                                     // vector of perfect ray, light_direction is negative because the formular requires vector point to the surface
    vec3 viewer_direction = normalize(viewer_position - frag_position);                         // vector from surface to viewer
    
    float dot_rv = clamp(dot(reflected_ray, viewer_direction), 0.0, 1.0);                       // I split specular calculation into three steps for clearance
    float pow_dot_rv = pow(dot_rv, shininess_constant);
    float spec = specular_reflection_constant * pow_dot_rv;

    vec3 specular = spec * light_color;

    gl_FragColor = vec4((ambient + diffuse + specular) * model_color, 1.0);
}