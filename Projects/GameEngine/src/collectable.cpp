/**
@file collectable.cpp
*/

// Imports
#include "collectable.h"

// Constructor
Collectable::Collectable(const glm::vec3 kPosition, const float kfRotation)
{
	m_position = kPosition;
	m_fRotation = kfRotation;
}

// Void: Called to render the Collectable
void Collectable::render()
{
	// Renders the GameObject's Model
	m_pModel->render(m_position, m_fRotation);
}