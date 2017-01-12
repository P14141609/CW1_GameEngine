/* OLD

#version 430

in vec3 colour;
layout (location=0) out vec4 fragColour;

void main() {
    fragColour = vec4(colour, 1.0);
}*/

// NEW

#version 430

in vec3 colour;
out vec4 fragColour;

void main() 
{
    fragColour = vec4(colour, 1.0);
}

