
/**
@file robot.cpp
*/

// Imports
#include "robot.h"

// Constructor
Robot::Robot()
{
	m_fArmAngles[LEFT] = 0.0;
	m_fArmAngles[RIGHT] = 0.0;
	m_fLegAngles[LEFT] = 0.0;
	m_fLegAngles[RIGHT] = 0.0;

	m_bArmsMoving = true;
	m_armStates[LEFT] = FORWARD;
	m_armStates[RIGHT] = BACKWARD;

	m_bLegsMoving = true;
	m_legStates[LEFT] = FORWARD;
	m_legStates[RIGHT] = BACKWARD;
}

void Robot::draw(const glm::vec3 kPosition, const float kfRotation)
{
	glPushMatrix();
		glTranslatef(kPosition.x, kPosition.y, kPosition.z);	// draw robot at desired coordinates
		glRotatef(kfRotation, false, true, false);

		// draw head and torso parts
		drawHead(glm::vec3(1.0f, 2.0f, 0.0f));
		drawTorso(glm::vec3(1.5f, 0.0f, 0.0f));

		// move the left arm away from the torso and rotate it to give "walking" effect
		glPushMatrix();
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(m_fArmAngles[LEFT], true, false, false); // rotate around x coord
			drawArm(glm::vec3(2.5f, 0.0f, -0.5f));
		glPopMatrix();

		// move the right arm away from the torso and rotate it to give "walking" effect
		glPushMatrix();
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(m_fArmAngles[RIGHT], true, false, false); // rotate around x coord
			drawArm(glm::vec3(-1.5f, 0.0f, -0.5f));
		glPopMatrix();

		// move the left leg away from the torso and rotate it to give "walking" effect
		glPushMatrix();
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(m_fLegAngles[LEFT], true, false, false); // rotate around x coord
			drawLeg(glm::vec3(-0.5f, -5.0f, -0.5f));
		glPopMatrix();

		// move the right leg away from the torso and rotate it to give "walking" effect
		glPushMatrix();
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(m_fLegAngles[RIGHT], true, false, false); // rotate around x coord
			drawLeg(glm::vec3(1.5f, -5.0f, -0.5f));
		glPopMatrix();

	glPopMatrix();	// pop back to original coordinate system
}

void Robot::drawCube(const glm::vec3 kPosition)
{
	glPushMatrix();
		glTranslatef(kPosition.x, kPosition.y, kPosition.z);
		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.0f, 0.0f);	// top face
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);	// front face
			glVertex3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);	// right face
			glVertex3f(0.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, -1.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
			glVertex3f(-1.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);	// bottom face
			glVertex3f(0.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);	// back face
			glVertex3f(-1.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(0.0f, -1.0f, -1.0f);
		glEnd();
	glPopMatrix();
}
void Robot::drawArm(const glm::vec3 kPosition)
{
	glPushMatrix();
		glColor3f(kPosition.x, kPosition.y, kPosition.z);	// red
		glTranslatef(kPosition.x, kPosition.y, kPosition.z);
		glScalef(1.0f, 4.0f, 1.0f);		// arm is a 1x4x1 cube
		drawCube(glm::vec3(0.0f, 0.0f, 0.0f));
	glPopMatrix();
}
void Robot::drawHead(const glm::vec3 kPosition)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);	// white
		glTranslatef(kPosition.x, kPosition.y, kPosition.z);
		glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
		drawCube(glm::vec3(0.0f, 0.0f, 0.0f));
	glPopMatrix();
}
void Robot::drawTorso(const glm::vec3 kPosition)
{
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);	// blue
		glTranslatef(kPosition.x, kPosition.y, kPosition.z);
		glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
		drawCube(glm::vec3(0.0f, 0.0f, 0.0f));
	glPopMatrix();
}
void Robot::drawLeg(const glm::vec3 kPosition)
{
	glPushMatrix();
	glTranslatef(kPosition.x, kPosition.y, kPosition.z);

	// draw the foot
	glPushMatrix();
		glTranslatef(0.0f, -0.5f, 0.0f);
		drawFoot(glm::vec3(0.0f, -5.0f, 0.0f));
	glPopMatrix();

	glScalef(1.0f, 5.0f, 1.0f);		// leg is a 1x5x1 cube
		glColor3f(1.0f, 1.0f, 0.0f);	// yellow
		drawCube(glm::vec3(0.0f, 0.0f, 0.0f));
	glPopMatrix();
}
void Robot::drawFoot(const glm::vec3 kPosition)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(kPosition.x, kPosition.y, kPosition.z);
		glScalef(1.0f, 0.5f, 3.0f);
		drawCube(glm::vec3(0.0f, 0.0f, 0.0f));
	glPopMatrix();
}

// Update method
void Robot::update(const float kfElapsedTime)
{
	// if leg is moving forward, increase angle, else decrease angle
	for (char side = 0; side < 2; side++)
	{
		if (m_bArmsMoving)
		{
			// arms
			if (m_armStates[side] == FORWARD)
				m_fArmAngles[side] += 40.0f * kfElapsedTime;
			else
				m_fArmAngles[side] -= 40.0f * kfElapsedTime;

			// change state if exceeding angles
			if (m_fArmAngles[side] >= 15.0f)
				m_armStates[side] = BACKWARD;
			else if (m_fArmAngles[side] <= -15.0f)
				m_armStates[side] = FORWARD;
		}

		if (m_bLegsMoving)
		{
			// legs
			if (m_legStates[side] == FORWARD)
				m_fLegAngles[side] += 40.0f * kfElapsedTime;
			else
				m_fLegAngles[side] -= 40.0f * kfElapsedTime;

			// change state if exceeding angles
			if (m_fLegAngles[side] >= 15.0f)
				m_legStates[side] = BACKWARD;
			else if (m_fLegAngles[side] <= -15.0f)
				m_legStates[side] = FORWARD;
		}
	}
}