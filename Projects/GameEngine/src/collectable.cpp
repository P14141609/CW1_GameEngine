/**
@file collectable.cpp
*/

// Imports
#include "collectable.h"

// Constructor
Collectable::Collectable(const std::string ksObjectFile, const std::string ksTextureFile, const glm::vec3 kPosition, const float kfRotation)
{
	m_position = kPosition;
	m_fRotation = kfRotation;

	m_pModel = std::shared_ptr<Model>(new Model(ksObjectFile, ksTextureFile));
}

// Void: Called to render the Collectable
void Collectable::render()
{
	// Renders the GameObject's Model
	m_pModel->render(m_position, m_fRotation);
}