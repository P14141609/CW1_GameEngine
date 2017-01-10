/**
@file player.cpp
*/

// Imports
#include "player.h"

// Constructor
Player::Player(const float kfXPos, const float kfYPos, const float kfZPos, const float kfRotation)
{
	m_position = glm::vec3(kfXPos, kfYPos, kfZPos);
	m_rotation = kfRotation;
}

// Void: Moves the Player forward
void Player::moveForward(const float kfDist)
{
	// Defines forward Normal vector
	glm::vec3 forwardNormal = glm::vec3(cosf(glm::radians(m_rotation - 90)), 0, -sinf(glm::radians(m_rotation - 90)));

	// Applies distance split between x/z
	m_position.x += -kfDist * forwardNormal.x;
	m_position.z += -kfDist * forwardNormal.z;
}

// Void: Called to update the Player model
void Player::update(const float kfElapsedTime)
{
	m_robot->update(kfElapsedTime);
}

// Void: Called to render the Player model
void Player::render()
{
	m_robot->draw(m_position.x, m_position.y, m_position.z, m_rotation);
}