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
	std::shared_ptr<Robot> m_pRobot; //!< The Robot player character

	glm::vec3 m_position; //!< Player position vector
	float m_rotation; //!< Player rotation angle

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param kPosition Vector for Player position
	/// \param kfRotation Float for Player rotation angle
	///
	///////////////////////////////////////////////// 
	Player(const glm::vec3 kPosition, const float kfRotation);

	/////////////////////////////////////////////////
	///
	/// \brief Processes keyboard input
	///
	/// \param kiKey The pressed key
	/// \param kfElapsedTime The time since last update
	///
	///////////////////////////////////////////////// 
	void processKeyInput(const int kiKey, const float kfElapsedTime);

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

	void setPosition(const glm::vec3 kPosition) { m_position = kPosition; } //!< 
	void setRotation(const float kRotation) { m_rotation = kRotation; } //!< 
};

#endif