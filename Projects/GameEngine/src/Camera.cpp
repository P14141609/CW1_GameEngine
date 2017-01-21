/**
@file camera.cpp
*/

// Imports
#include "camera.h"

// Constructor
Camera::Camera(const glm::vec3 kPosition, const glm::vec3 kDirection, const float kfFOV, const float kfAspectRatio, const float kfNear, const float kfFar)
{
	// Defines position
	m_position = kPosition;
	m_direction = kDirection;
	m_up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_fFOV = kfFOV;
	m_fAspectRatio = kfAspectRatio;
	m_fNear = kfNear;
	m_fFar = kfFar;
}