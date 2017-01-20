/**
@file camera.cpp
*/

// Imports
#include "stdafx.h"
#include "camera.h"

// Constructor
Camera::Camera(const glm::vec3 kPosition, const glm::vec3 kTargetPos, const glm::mat4 kPerspective)
{
	// Defines View
	m_view = glm::lookAt
	(
		kPosition, // Camera Pos
		kTargetPos, // Camera looking at
		glm::vec3(0.0, 1.0, 0.0)  // Camera 'Up'
	);

	// Defines Perspective
	m_perspective = kPerspective;
}