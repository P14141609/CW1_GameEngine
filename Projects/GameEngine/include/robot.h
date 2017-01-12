#ifndef ROBOT_H
#define ROBOT_H

#include "glm.hpp"
#include "gl_core_4_3.hpp"
#include <memory>
#include "camera.h"

class Robot
{
private:

	enum side { LEFT, RIGHT }; //!< Side enum for handling robot limbs
	enum moveState { FORWARD, BACKWARD }; //!< Movement state for limb control

	moveState m_legStates[2]; //!< MoveState array for left&right leg movement handling
	moveState m_armStates[2]; //!< MoveState array for left&right arm movement handling
	
	float m_fLegAngles[2]; //!< Float array for left&right leg movement handling
	float m_fArmAngles[2]; //!< Float array for left&right arm movement handling

	GLuint m_vboHandles[3];
	GLuint m_vaoHandle;
	GLuint m_programHandle;
	GLuint m_sizeOfIndices;

	/////////////////////////////////////////////////
	///
	/// \brief Draws a 1x1x1 cube at a specified position
	///
	/// \param kPosition Vector for Robot position
	/// \param kModel Model matrix used to translate, scale or rotate
	///
	///////////////////////////////////////////////// 
	void drawCube(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's arm at a specified position
	///
	/// \param kCamera Camera pointer to use in rendering
	/// \param kModel Model matrix used to translate, scale or rotate
	///
	///////////////////////////////////////////////// 
	void drawArm(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel, const side kSide);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's head at a specified position
	///
	/// \param kCamera Camera pointer to use in rendering
	/// \param kModel Model matrix used to translate, scale or rotate
	///
	///////////////////////////////////////////////// 
	void drawHead(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's torso at a specified position
	///
	/// \param kCamera Camera pointer to use in rendering
	/// \param kModel Model matrix used to translate, scale or rotate
	///
	///////////////////////////////////////////////// 
	void drawTorso(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's leg at a specified position
	///
	/// \param kCamera Camera pointer to use in rendering
	/// \param kModel Model matrix used to translate, scale or rotate
	///
	///////////////////////////////////////////////// 
	void drawLeg(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel, const side kSide);

	/////////////////////////////////////////////////
	///
	/// \brief Draws the Robot's foot at a specified position
	///
	/// \param kCamera Camera pointer to use in rendering
	/// \param kModel Model matrix used to translate, scale or rotate
	///
	///////////////////////////////////////////////// 
	void drawFoot(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel, const side kSide);

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