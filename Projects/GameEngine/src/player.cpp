
/**
@file player.cpp
*/

// Imports
#include "stdafx.h"
#include "player.h"

// Constructor
Player::Player(const glm::vec3 kPosition, const float kfRotation)
{
	m_position = kPosition;
	m_rotation = kfRotation;

	m_pRobot = std::shared_ptr<Robot>(new Robot());
}

// Void: Processes keyboard input
void Player::processKeyInput(const int kiKey)
{
	switch (kiKey)
	{
		// If input is Spacebar
		case sf::Keyboard::Space:
		{
			// Inverts the current bool values for limb movement
			m_pRobot->m_bArmsMoving = !m_pRobot->m_bArmsMoving;
			m_pRobot->m_bLegsMoving = !m_pRobot->m_bLegsMoving;
		} break;

		// If input is Up
		case sf::Keyboard::Up:
		{
			moveForward(0.5f);
		} break;

		// If input is Down
		case sf::Keyboard::Down:
		{
			moveForward(-0.5f);
		} break;

		// If input is Left
		case sf::Keyboard::Left:
		{
			m_rotation += 2.5f;
		} break;

		// If input is Right
		case sf::Keyboard::Right:
		{
			m_rotation += -2.5f;
		} break;

		// Default case
		default: break; // Do Nothing
	}
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
	m_pRobot->update(kfElapsedTime);
}

// Void: Called to render the Player model
void Player::render()
{
	m_pRobot->draw(m_position, m_rotation);
}