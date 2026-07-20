#version 330

in vec3 normal;
in vec3 viewer_position;
in vec3 frag_position;

out vec4 FragColor;

uniform vec3 model_color;
uniform vec3 light_color;
uniform vec3 light_position;
uniform float ambient_reflection_constant;
uniform float diffuse_reflection_constant;
uniform float specular_reflection_constant;
uniform int shininess_constant; 

void main(void) {
    // ambient
    vec3 ambient = ambient_reflection_constant * light_color;

    // diffuse
    vec3 light_direction = normalize(light_position - frag_position);                           // vector from surface to light source
    float diff = diffuse_reflection_constant * max(dot(light_direction, normal), 0.0);

    vec3 diffuse = diff * light_color;

    // specular
    vec3 reflected_ray = reflect(-light_direction, normal);                                     // vector of perfect ray, light_direction is negative because the formula requires vector point to the surface
    vec3 viewer_direction = normalize(viewer_position - frag_position);                         // vector from surface to viewer
    
    float dot_rv = max(dot(reflected_ray, viewer_direction), 0.0);                              // I split specular calculation into three steps for clearance
    float pow_dot_rv = pow(dot_rv, shininess_constant);
    float spec = specular_reflection_constant * pow_dot_rv;

    vec3 specular = spec * light_color;

    FragColor = vec4((ambient + diffuse + specular) * model_color, 1.0);
}