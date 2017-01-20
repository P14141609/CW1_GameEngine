/**
@file camera.cpp
*/

// Imports
#include "stdafx.h"
#include "camera.h"

// Constructor
Camera::Camera(glm::vec3 kPosition, const glm::vec3 kTargetPos, const float kfAspectRatio, const float kfFOV, const float kfNear, const float kfFar)
{
	// Defines position
	m_position = kPosition;

	// Defines View
	m_view = glm::lookAt
	(
		m_position, // Camera Pos
		kTargetPos, // Camera looking at
		glm::vec3(0.0, 1.0, 0.0)  // Camera 'Up'
	);

	m_fFOV = kfFOV;
	m_fNear = kfNear;
	m_fFar = kfFar;

	// Defines Perspective
	m_perspective = glm::perspective(
		m_fFOV,
		kfAspectRatio,
		m_fNear,
		m_fFar
	);
}

void Camera::resize(const float kfAspectRatio)
{
	// Defines Perspective
	m_perspective = glm::perspective(
		m_fFOV,
		kfAspectRatio,
		m_fNear,
		m_fFar
	);
}