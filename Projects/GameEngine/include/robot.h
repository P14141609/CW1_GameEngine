#ifndef ROBOT_H
#define ROBOT_H

#include "glm.hpp"
#include "gl_core_4_3.hpp"
#include <memory>
#include <vector>
#include "camera.h"
#include "model.h"

class Robot
{
private:

	enum side { LEFT, RIGHT }; //!< Side enum for handling robot limbs
	enum moveState { FORWARD, BACKWARD }; //!< Movement state for limb control

	moveState m_legStates[2]; //!< MoveState array for left&right leg movement handling
	moveState m_armStates[2]; //!< MoveState array for left&right arm movement handling
	
	float m_fLegAngles[2]; //!< Float array for left&right leg movement handling
	float m_fArmAngles[2]; //!< Float array for left&right arm movement handling
	
	std::vector<Model> m_bodyparts; //!< Vector of Models to store each body part

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
	/// \param kCamera Camera pointer to use in rendering
	/// \param kPosition Vector for Robot position
	/// \param kfRotation Float for Robot rotation angle
	///
	///////////////////////////////////////////////// 
	void draw(const std::shared_ptr<Camera> kCamera, const glm::vec3 kPosition, const float kfRotation);
};

#endif