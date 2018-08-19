#version 330 core

in vec3 inColour;
out vec4 FragColor;

void main()
{
    FragColor = vec4(inColour, 1.0);
} 