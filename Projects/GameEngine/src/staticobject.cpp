/**
@file staticobject.cpp
*/

// Imports
#include "staticobject.h"

// Constructor
StaticObject::StaticObject(const glm::vec3 kPosition, const float kfRotation)
{
	m_position = kPosition;
	m_fRotation = kfRotation;
}

// Void: Called to render the StaticObject
void StaticObject::render()
{
	// Renders the GameObject's Model
	m_pModel->render(m_position, m_fRotation);
}