#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 inColour;
out float inAmbient;

uniform mat4 mvp;
uniform vec3 objectColour;
uniform vec3 lightColour;
uniform float ambientStrength;

void main()
{
    gl_Position = mvp * vec4(aPos, 1.0);
    inColour = objectColour * lightColour;
    inAmbient = ambientStrength;
}