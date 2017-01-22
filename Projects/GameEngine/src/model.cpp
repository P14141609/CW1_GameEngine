/**
@file model.cpp
*/

// Imports
#include "model.h"

// Constructor
Model::Model(const std::string ksObjectFile, const std::string ksTextureFile, const glm::vec3 kPosition, const float kfRotation)
{
	m_position = kPosition;
	m_fRotation = kfRotation;

	// TEMPORARY
	//loadObj(ksObjectFile);
	//loadTexture(ksTextureFile);
}

// Void: Called to render the Model
void Model::render()
{
	glPushMatrix();

		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_fRotation, false, true, false);

		// Draw model

	glPopMatrix();
}