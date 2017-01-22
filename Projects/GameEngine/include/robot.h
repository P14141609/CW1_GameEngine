#ifndef ROBOT_H
#define ROBOT_H

#include "camera.h"
#include "model.h"

#include <SFML\glew.h>		
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\wglext.h>
#include <SFML\glext.h>

#include <memory>
#include <vector>
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
	/// \param kPosition Vector for Robot position
	/// \param kfRotation Float for Robot rotation angle
	///
	///////////////////////////////////////////////// 
	void draw(const glm::vec3 kPosition, const float kfRotation);

	void drawCube(const glm::vec3 kPosition); //!< Called to render a unit cube
	void drawArm(const glm::vec3 kPosition); //!< Called to render the Robot's arm
	void drawHead(const glm::vec3 kPosition); //!< Called to render the Robot's head
	void drawTorso(const glm::vec3 kPosition); //!< Called to render the Robot's torso
	void drawLeg(const glm::vec3 kPosition); //!< Called to render the Robot's lef
	void drawFoot(const glm::vec3 kPosition); //!< Called to render the Robot's foot
};
#endif