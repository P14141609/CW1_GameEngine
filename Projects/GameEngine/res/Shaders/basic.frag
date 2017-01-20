#version 430

uniform sampler2D tex;
in vec2 texCoord;

out vec4 fragColour;

void main() 
{
    fragColour = texture(tex, texCoord);
}