#version 330 core
out vec4 FragColor;

in vec3 inAmbientColour;
in vec3 inDiffuseColour;
in vec3 inObjectColour;
in float inAmbientStrength;
in vec3 inNormal;
in vec3 inLightPos;
in vec3 inFragPos;

void main()
{
    vec3 ambient = inAmbientStrength * inAmbientColour;
    vec3 norm = normalize(inNormal);
    vec3 lightDir = normalize(inLightPos - inFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * inDiffuseColour;
    FragColor = vec4(ambient + diffuse * inObjectColour, 1.0);
}