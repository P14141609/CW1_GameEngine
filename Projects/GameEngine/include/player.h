#ifndef PLAYER_H
#define PLAYER_H

// Imports
#include "robot.h"
#include <memory>

/////////////////////////////////////////////////
///
/// \brief Class for player handling
/// 
/////////////////////////////////////////////////
class Player
{
private:
	std::unique_ptr<Robot> m_robot; //!< The Robot player character

	glm::vec3 m_position;
	float m_rotation;

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	///////////////////////////////////////////////// 
	Player(const float kfXPos, const float kfYPos, const float kfZPos, const float kfRotation);

	/////////////////////////////////////////////////
	///
	/// \brief Moves the Player forward by a given distance
	///
	/// \param kfDist The distance to move the Player
	///
	///////////////////////////////////////////////// 
	void moveForward(const float kfDist);

	/////////////////////////////////////////////////
	///
	/// \brief Called to update the Player model
	///
	/// \param kfElapsedTime The time since last update
	///
	///////////////////////////////////////////////// 
	void update(const float kfElapsedTime);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Player model
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif