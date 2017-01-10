#ifndef ROBOT_H
#define ROBOT_H

#include "glm.hpp"
#include <gl/gl.h>
#include <gl/glu.h>

// constants for arm and leg movement states
const char BACKWARD_STATE = 0;
const char FORWARD_STATE = 1;

// index constants for accessing arm and leg array data
const char LEFT = 0;
const char RIGHT = 1;

class Robot
{
private:

	char m_legStates[2];
	char m_armStates[2];

	float m_legAngles[2];
	float m_armAngles[2];

	// draws a unit cube
	void drawCube(const float kfXPos, const float kfYPos, const float kfZPos);

	// methods to draw the parts of the robot
	void drawArm(const float kfXPos, const float kfYPos, const float kfZPos);
	void drawHead(const float kfXPos, const float kfYPos, const float kfZPos);
	void drawTorso(const float kfXPos, const float kfYPos, const float kfZPos);
	void drawLeg(const float kfXPos, const float kfYPos, const float kfZPos);
	void drawFoot(const float kfXPos, const float kfYPos, const float kfZPos);

public:

	Robot();
	~Robot() {};

	bool m_armsMoving;
	bool m_legsMoving;

	// draws the entire robot
	void draw(const float kfXPos, const float kfYPos, const float kfZPos, const float kfRotation);

	// updates the robot data
	void update(const float kfElapsedTime);
};

#endif