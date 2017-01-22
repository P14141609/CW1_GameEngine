/**
@file collectable.cpp
*/

// Imports
#include "collectable.h"

// Constructor
Collectable::Collectable()
{
	// TODO
}

// Void: Called to render the Collectable
void Collectable::render()
{
	// Renders the GameObject's Model
	m_pModel->render(m_position, m_rotation);
}