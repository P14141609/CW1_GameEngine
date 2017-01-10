/**
@file player.cpp
*/

// Imports
#include "player.h"

// Constructor
Player::Player()
{
	// TODO
}

// Void: Called to update the player model
void Player::update(float fElapsedTime)
{
	m_robot->update(fElapsedTime);
}

// Void: Called to render the player model
void Player::render()
{
	m_robot->drawRobot();
}