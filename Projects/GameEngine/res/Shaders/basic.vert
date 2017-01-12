/* OLD

#version 430

layout (location=0) in vec3 vertexPosition;
layout (location=1) in vec3 vertexColour;

out vec3 colour;

void main()
{
    colour = vertexColour;

    gl_Position = vec4(vertexPosition,1.0);
}*/

// NEW

#version 430

in vec4 vertPosition;

uniform mat4 mModel;        //Matrix to convert to world coordinate system
uniform mat4 mView;         //Matrix to convert into camera coordinate system
uniform mat4 mProjection;   //Matrix to convert to normalised screen coordinates

in vec3 vertexColour;
out vec3 colour;

void main()
{
	colour = vertexColour;

	//Transform from local to world to camera to NDCs
	gl_Position = mProjection * mView * mModel * vertPosition;
}

