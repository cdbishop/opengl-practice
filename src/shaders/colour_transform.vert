#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 inColour;

uniform mat4 mvp;
uniform vec3 objectColour;

void main()
{
    gl_Position = mvp * vec4(aPos, 1.0);
    inColour = objectColour;
}