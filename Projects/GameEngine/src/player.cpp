
/**
@file player.cpp
*/

// Imports
#include "player.h"

#include <SFML\Graphics.hpp>

// Constructor
Player::Player(const glm::vec3 kPosition, const float kfRotation)
{
	m_position = kPosition;
	m_fRotation = kfRotation;

	// Defines a new Robot to represent the Player in game
	m_pRobot = std::shared_ptr<Robot>(new Robot());
}

// Void: Processes keyboard input
void Player::processKeyInput(const int kiKey, const float kfElapsedTime)
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
		case sf::Keyboard::W:
		{
			moveForward(8.0f * kfElapsedTime);
		} break;
	
		// If input is Down
		case sf::Keyboard::Down:
		case sf::Keyboard::S:
		{
			moveForward(-8.0f * kfElapsedTime);
		} break;
	
		// If input is Left
		case sf::Keyboard::Left:
		case sf::Keyboard::A:
		{
			m_fRotation += 90.0f * kfElapsedTime;
		} break;
	
		// If input is Right
		case sf::Keyboard::Right:
		case sf::Keyboard::D:
		{
			m_fRotation += -90.0f * kfElapsedTime;
		} break;
	
		// Default case
		default: break; // Do Nothing
	}
}

// Void: Moves the Player forward
void Player::moveForward(const float kfDist)
{
	// Defines forward Normal vector
	glm::vec3 forwardNormal = glm::vec3(cosf(glm::radians(m_fRotation - 90)), 0, -sinf(glm::radians(m_fRotation - 90)));

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
	glEnable(GL_COLOR_MATERIAL);
		//glDisable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
		m_pRobot->draw(m_position, m_fRotation);
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
	glDisable(GL_COLOR_MATERIAL);
}