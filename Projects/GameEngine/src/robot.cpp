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

	// TODO
	// ADD MODELS OF EACH BODY PART TO MEMBER
	//m_bodyparts.push_back(head);
	//m_bodyparts.push_back(torso);

	//m_bodyparts.push_back(lArm);
	//m_bodyparts.push_back(rArm);

	//m_bodyparts.push_back(lLeg);
	//m_bodyparts.push_back(lFoot);

	//m_bodyparts.push_back(rLeg);
	//m_bodyparts.push_back(rFoot);
}

void Robot::draw(const std::shared_ptr<Camera> kCamera, const glm::vec3 kPosition, const float kfRotation)
{
	// Sets the active shader
	gl::UseProgram(kCamera->getShaderHandle());

	for (Model bodypart : m_bodyparts)
	{
		bodypart.render();
	}
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
				m_fArmAngles[side] += 20.0f * kfElapsedTime;
			else
				m_fArmAngles[side] -= 20.0f * kfElapsedTime;

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
				m_fLegAngles[side] += 20.0f * kfElapsedTime;
			else
				m_fLegAngles[side] -= 20.0f * kfElapsedTime;

			// change state if exceeding angles
			if (m_fLegAngles[side] >= 15.0f)
				m_legStates[side] = BACKWARD;
			else if (m_fLegAngles[side] <= -15.0f)
				m_legStates[side] = FORWARD;
		}
	}
}