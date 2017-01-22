/**
@file staticobject.cpp
*/

// Imports
#include "staticobject.h"

// Constructor
StaticObject::StaticObject()
{
	// TODO
}

// Void: Called to render the StaticObject
void StaticObject::render()
{
	// Renders the GameObject's Model
	m_pModel->render(m_position, m_rotation);
}