#version 430

in vec3 vertPos;
in vec3 N;

uniform vec3 cameraPos;
uniform samplerCube cubeMap;

layout( location = 0 ) out vec4 FragColour;

void main() 
{
    vec3 I = normalize(vertPos - cameraPos);
    vec3 R = reflect(I, normalize(N));
    FragColour = texture(cubeMap, R);
}