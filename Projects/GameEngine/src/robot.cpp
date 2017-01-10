/**
@file robot.cpp
*/

// Imports
#include "robot.h"

// Constructor
Robot::Robot()
{
	m_armAngles[LEFT] = 0.0;
	m_armAngles[RIGHT] = 0.0;
	m_legAngles[LEFT] = 0.0;
	m_legAngles[RIGHT] = 0.0;

	m_armsMoving = true;
	m_armStates[LEFT] = FORWARD_STATE;
	m_armStates[RIGHT] = BACKWARD_STATE;

	m_legsMoving = true;
	m_legStates[LEFT] = FORWARD_STATE;
	m_legStates[RIGHT] = BACKWARD_STATE;
}

// Draw methods
void Robot::drawCube(const float kfXPos, const float kfYPos, const float kfZPos)
{
	//glPushMatrix();
	//	glTranslatef(xPos, yPos, zPos);
	//	glBegin(GL_POLYGON);
	//		glVertex3f(0.0f, 0.0f, 0.0f);	// top face
	//		glVertex3f(0.0f, 0.0f, -1.0f);
	//		glVertex3f(-1.0f, 0.0f, -1.0f);
	//		glVertex3f(-1.0f, 0.0f, 0.0f);
	//		glVertex3f(0.0f, 0.0f, 0.0f);	// front face
	//		glVertex3f(-1.0f, 0.0f, 0.0f);
	//		glVertex3f(-1.0f, -1.0f, 0.0f);
	//		glVertex3f(0.0f, -1.0f, 0.0f);
	//		glVertex3f(0.0f, 0.0f, 0.0f);	// right face
	//		glVertex3f(0.0f, -1.0f, 0.0f);
	//		glVertex3f(0.0f, -1.0f, -1.0f);
	//		glVertex3f(0.0f, 0.0f, -1.0f);
	//		glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
	//		glVertex3f(-1.0f, 0.0f, -1.0f);
	//		glVertex3f(-1.0f, -1.0f, -1.0f);
	//		glVertex3f(-1.0f, -1.0f, 0.0f);
	//		glVertex3f(0.0f, 0.0f, 0.0f);	// bottom face
	//		glVertex3f(0.0f, -1.0f, -1.0f);
	//		glVertex3f(-1.0f, -1.0f, -1.0f);
	//		glVertex3f(-1.0f, -1.0f, 0.0f);
	//		glVertex3f(0.0f, 0.0f, 0.0f);	// back face
	//		glVertex3f(-1.0f, 0.0f, -1.0f);
	//		glVertex3f(-1.0f, -1.0f, -1.0f);
	//		glVertex3f(0.0f, -1.0f, -1.0f);
	//	glEnd();
	//glPopMatrix();
}
void Robot::drawArm(const float kfXPos, const float kfYPos, const float kfZPos)
{
	//glPushMatrix();
	//	glColor3f(1.0f, 0.0f, 0.0f);	// red
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(1.0f, 4.0f, 1.0f);		// arm is a 1x4x1 cube
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::drawHead(const float kfXPos, const float kfYPos, const float kfZPos)
{
	//glPushMatrix();
	//	glColor3f(1.0f, 1.0f, 1.0f);	// white
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::drawTorso(const float kfXPos, const float kfYPos, const float kfZPos)
{
	//glPushMatrix();
	//	glColor3f(0.0f, 0.0f, 1.0f);	// blue
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::drawLeg(const float kfXPos, const float kfYPos, const float kfZPos)
{
	//glPushMatrix();
	//	glTranslatef(xPos, yPos, zPos);
	//
	//	// draw the foot
	//	glPushMatrix();
	//		glTranslatef(0.0f, -0.5f, 0.0f);
	//		DrawFoot(0.0f, -5.0f, 0.0f);
	//	glPopMatrix();
	//
	//	glScalef(1.0f, 5.0f, 1.0f);		// leg is a 1x5x1 cube
	//	glColor3f(1.0f, 1.0f, 0.0f);	// yellow
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::drawFoot(const float kfXPos, const float kfYPos, const float kfZPos)
{
	//glPushMatrix();
	//	glColor3f(1.0f, 1.0f, 1.0f);
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(1.0f, 0.5f, 3.0f);
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::draw(const float kfXPos, const float kfYPos, const float kfZPos, const float kfRotation)
{
	//glPushMatrix();
	//	glTranslatef(m_position.x, m_position.y, m_position.z);	// draw robot at desired coordinates
	//	glRotatef(m_rotation, false, true, false);
	//
	//	// draw head and torso parts
	//	DrawHead(1.0f, 2.0f, 0.0f);
	//	DrawTorso(1.5f, 0.0f, 0.0f);
	//
	//	// move the left arm away from the torso and rotate it to give "walking" effect
	//	glPushMatrix();
	//		glTranslatef(0.0f, -0.5f, 0.0f);
	//		glRotatef(armAngles[LEFT], true, false, false); // rotate around x coord
	//		DrawArm(2.5f, 0.0f, -0.5f);
	//	glPopMatrix();
	//
	//	// move the right arm away from the torso and rotate it to give "walking" effect
	//	glPushMatrix();
	//		glTranslatef(0.0f, -0.5f, 0.0f);
	//		glRotatef(armAngles[RIGHT], true, false, false); // rotate around x coord
	//		DrawArm(-1.5f, 0.0f, -0.5f);
	//	glPopMatrix();
	//
	//	// move the left leg away from the torso and rotate it to give "walking" effect
	//	glPushMatrix();
	//		glTranslatef(0.0f, -0.5f, 0.0f);
	//		glRotatef(legAngles[LEFT], true, false, false); // rotate around x coord
	//		DrawLeg(-0.5f, -5.0f, -0.5f);
	//	glPopMatrix();
	//
	//	// move the right leg away from the torso and rotate it to give "walking" effect
	//	glPushMatrix();
	//		glTranslatef(0.0f, -0.5f, 0.0f);
	//		glRotatef(legAngles[RIGHT], true, false, false); // rotate around x coord
	//		DrawLeg(1.5f, -5.0f, -0.5f);
	//	glPopMatrix();
	//
	//glPopMatrix();	// pop back to original coordinate system
}

// Update method
void Robot::update(const float kfElapsedTime)
{
	// if leg is moving forward, increase angle, else decrease angle
	for (char side = 0; side < 2; side++)
	{
		if (m_armsMoving)
		{
			// arms
			if (m_armStates[side] == FORWARD_STATE)
				m_armAngles[side] += 20.0f * kfElapsedTime;
			else
				m_armAngles[side] -= 20.0f * kfElapsedTime;

			// change state if exceeding angles
			if (m_armAngles[side] >= 15.0f)
				m_armStates[side] = BACKWARD_STATE;
			else if (m_armAngles[side] <= -15.0f)
				m_armStates[side] = FORWARD_STATE;
		}

		if (m_legsMoving)
		{
			// legs
			if (m_legStates[side] == FORWARD_STATE)
				m_legAngles[side] += 20.0f * kfElapsedTime;
			else
				m_legAngles[side] -= 20.0f * kfElapsedTime;

			// change state if exceeding angles
			if (m_legAngles[side] >= 15.0f)
				m_legStates[side] = BACKWARD_STATE;
			else if (m_legAngles[side] <= -15.0f)
				m_legStates[side] = FORWARD_STATE;
		}
	}
}