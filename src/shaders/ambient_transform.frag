#version 330 core
out vec4 FragColor;

in vec3 inColour;
in float inAmbient;

void main()
{
    vec3 ambient = inAmbient * inColour;
    FragColor = vec4(ambient, 1.0);
}