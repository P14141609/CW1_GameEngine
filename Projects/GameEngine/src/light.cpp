/**
@file light.cpp
*/

// Imports
#include "light.h"

// Constructor
Light::Light(const glm::vec3 kPosition)
{
	m_position = kPosition;
}

// Void: Configures OpenGL for rendering
void Light::configureGL()
{
	GLfloat lightColour[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat noLight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat lightModelAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	GLfloat lightPosition[] = { m_position.x, m_position.y, m_position.z, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColour);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColour);
	glLightfv(GL_LIGHT0, GL_AMBIENT, noLight); // no ambient light from the source

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightModelAmbient); // use global ambient instead

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// create a default material for the models
	GLfloat materialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat materialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat materialShininess = 4.0f; // Lower for a sharper specular highlight

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);
}
