#version 330 core
in vec3 FragPos;
in vec3 Normal;
in vec3 ourColor;

out vec4 FragColor;

uniform vec3 lightDir; // Direction of the light
uniform vec3 lightColor; // Color of the light

void main() {
    float diff = max(dot(normalize(Normal), -lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    FragColor = vec4(diffuse * ourColor, 1.0);
}
