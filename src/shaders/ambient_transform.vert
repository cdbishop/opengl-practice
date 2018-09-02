#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 inAmbientColour;
out vec3 inDiffuseColour;
out vec3 inObjectColour;
out float inAmbientStrength;
out vec3 inNormal;
out vec3 inLightPos;
out vec3 inFragPos;

uniform mat4 mvp;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 objectColour;
uniform vec3 ambientLightColour;
uniform vec3 diffuseLightColour;
uniform float ambientStrength;
uniform vec3 lightPos;

void main()
{
    gl_Position = mvp * vec4(aPos, 1.0);
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    inAmbientColour = ambientLightColour;
    inDiffuseColour = diffuseLightColour;
    inObjectColour = objectColour;
    inAmbientStrength = ambientStrength;
    inNormal = aNormal;
    inLightPos = lightPos;    
    inFragPos = vec3(model * vec4(aPos, 1.0));
}