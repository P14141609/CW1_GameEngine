#version 430

in vec3 texCoords;
uniform samplerCube cubeMap;

out vec4 FragColour;

void main() 
{
	FragColour = texture(cubeMap, texCoords);
}