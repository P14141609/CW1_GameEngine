#ifndef ROBOT_H
#define ROBOT_H

#include "glm.hpp"

class Robot
{
private:

	enum side { LEFT, RIGHT }; //!< Side enum for handling robot limbs
	enum moveState { FORWARD, BACKWARD }; //!< Movement state for limb control

	moveState m_legStates[2]; //!< MoveState array for left&right leg movement handling
	moveState m_armStates[2]; //!< MoveState array for left&right arm movement handling
	
	float m_fLegAngles[2]; //!< Float array for left&right leg movement handling
	float m_fArmAngles[2]; //!< Float array for left&right arm movement handling
	
	/////////////////////////////////////////////////
	///
	/// \brief Draws a 1x1x1 cube at a specified position
	///
	/// \param kPosition Vector for cube position
	///
	///////////////////////////////////////////////// 
	void drawCube(const glm::vec3 kPosition);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's arm at a specified position
	///
	/// \param kPosition Vector for arm position
	///
	///////////////////////////////////////////////// 
	void drawArm(const glm::vec3 kPosition);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's head at a specified position
	///
	/// \param kPosition Vector for head position
	///
	///////////////////////////////////////////////// 
	void drawHead(const glm::vec3 kPosition);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's torso at a specified position
	///
	/// \param kPosition Vector for torso position
	///
	///////////////////////////////////////////////// 
	void drawTorso(const glm::vec3 kPosition);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's leg at a specified position
	///
	/// \param kPosition Vector for leg position
	///
	///////////////////////////////////////////////// 
	void drawLeg(const glm::vec3 kPosition);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's foot at a specified position
	///
	/// \param kPosition Vector for foot position
	///
	///////////////////////////////////////////////// 
	void drawFoot(const glm::vec3 kPosition);

public:

	bool m_bArmsMoving; //!< Boolean for arm movement control
	bool m_bLegsMoving; //!< Boolean for leg movement control

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	///////////////////////////////////////////////// 
	Robot();

	/////////////////////////////////////////////////
	///
	/// \brief Denstructor
	///
	///////////////////////////////////////////////// 
	~Robot() {};

	/////////////////////////////////////////////////
	///
	/// \brief Called to update the Robot model
	///
	/// \param kfElapsedTime The time since last update
	///
	///////////////////////////////////////////////// 
	void update(const float kfElapsedTime);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Robot model
	///
	/// \param kPosition Vector for Robot position
	/// \param kfRotation Float for Robot rotation angle
	///
	///////////////////////////////////////////////// 
	void draw(const glm::vec3 kPosition, const float kfRotation);
};

#endif