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

	char legStates[2];
	char armStates[2];

	float legAngles[2];
	float armAngles[2];

	// draws a unit cube
	void DrawCube(float xPos, float yPos, float zPos);

	// methods to draw the parts of the robot
	void DrawArm(float xPos, float yPos, float zPos);
	void DrawHead(float xPos, float yPos, float zPos);
	void DrawTorso(float xPos, float yPos, float zPos);
	void DrawLeg(float xPos, float yPos, float zPos);
	void DrawFoot(float xPos, float yPos, float zPos);

public:

	Robot(float xPos, float yPos, float zPos, float rotation);
	~Robot() {};

	glm::vec3 m_position;
	float m_rotation;

	bool armsMoving;
	bool legsMoving;

	// draws the entire robot
	void DrawRobot();

	// moves the robot forwards by distance
	void MoveForward(float dist);

	// updates the robot data
	void Update(float dt);
};

#endif