#version 430

in vec3 vertPos;
in vec3 N;

uniform vec3 cameraPos;
uniform samplerCube cubeMap;

layout( location = 0 ) out vec4 FragColour;

void main() 
{
	float refractiveIndex = 1.1;
    float ratio = 1.00 / refractiveIndex; 

    vec3 I = normalize(vertPos - cameraPos);
    vec3 R = refract(I, normalize(N), ratio);
    FragColour = texture(cubeMap, R);
}