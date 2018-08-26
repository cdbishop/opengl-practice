#version 330 core
out vec4 FragColor;

in vec3 inColour;

void main()
{
    FragColor = vec4(inColour, 1.0);
} 