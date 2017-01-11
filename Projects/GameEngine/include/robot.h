#ifndef ROBOT_H
#define ROBOT_H

#include "glm.hpp"

// constants for arm and leg movement states
const char BACKWARD_STATE = 0;
const char FORWARD_STATE = 1;

// index constants for accessing arm and leg array data
const char LEFT = 0;
const char RIGHT = 1;

class Robot
{
private:

	char m_cLegStates[2];
	char m_cArmStates[2];

	float m_fLegAngles[2];
	float m_fArmAngles[2];

	// draws a unit cube
	void drawCube(const glm::vec3 kPosition);

	// methods to draw the parts of the robot
	void drawArm(const glm::vec3 kPosition);
	void drawHead(const glm::vec3 kPosition);
	void drawTorso(const glm::vec3 kPosition);
	void drawLeg(const glm::vec3 kPosition);
	void drawFoot(const glm::vec3 kPosition);

public:

	Robot();
	~Robot() {};

	bool m_bArmsMoving;
	bool m_bLegsMoving;

	// draws the entire robot
	void draw(const glm::vec3 kPosition, const float kfRotation);

	// updates the robot data
	void update(const float kfElapsedTime);
};

#endif