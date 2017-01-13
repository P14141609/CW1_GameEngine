
/**
@file robot.cpp
*/

// Imports
#include "stdafx.h"
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

	// GENERATE UNIT CUBE
	float positionData[] =
	{
		 1.0f,  1.0f,  1.0f,	// 0
		-1.0f,  1.0f,  1.0f,	// 1
		 1.0f,  1.0f, -1.0f,	// 2
		-1.0f,  1.0f, -1.0f,	// 3

		 1.0f, -1.0f,  1.0f,	// 4
		-1.0f, -1.0f,  1.0f,	// 5
		 1.0f, -1.0f, -1.0f,	// 6
		-1.0f, -1.0f, -1.0f		// 7
	};

	GLuint indexData[] =
	{
		1, 0, 2,
		1, 3, 2,

		1, 0, 4,
		1, 5, 4,

		2, 0, 4,
		2, 6, 4,

		3, 2, 6,
		3, 7, 6,

		1, 3, 7,
		1, 5, 7,

		5, 4, 6,
		5, 7, 6
	};

	m_sizeOfIndices = sizeof(indexData);

	// Create and populate the buffer objects using separate buffers
	gl::GenBuffers(2, m_vboHandles);
	GLuint positionBufferHandle = m_vboHandles[0];
	GLuint indexBufferHandle = m_vboHandles[1];

	// Create and set-up the vertex array object
	gl::GenVertexArrays(1, &m_vaoHandle);
	gl::BindVertexArray(m_vaoHandle);

	gl::BindBuffer(gl::ARRAY_BUFFER, positionBufferHandle);
	gl::BufferData(gl::ARRAY_BUFFER, sizeof(positionData), positionData, gl::STATIC_DRAW);

	gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, indexBufferHandle);
	gl::BufferData(gl::ELEMENT_ARRAY_BUFFER, m_sizeOfIndices, indexData, gl::STATIC_DRAW);

	gl::EnableVertexAttribArray(0);  // Vertex position

	gl::BindBuffer(gl::ARRAY_BUFFER, positionBufferHandle);
	gl::VertexAttribPointer(0, 3, gl::FLOAT, FALSE, 0, (GLubyte *)NULL);
}

// Draw methods
void Robot::drawCube(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel)
{
	// Gets the location ID of the non-uniform variable in the shader
	GLint posID = gl::GetAttribLocation(kCamera->getShaderHandle(), "vertPosition");
	// Gets the location ID of the uniform variables in the shader
	GLint modelMatrixID = gl::GetUniformLocation(kCamera->getShaderHandle(), "mModel");
	GLint viewMatrixID = gl::GetUniformLocation(kCamera->getShaderHandle(), "mView");
	GLint projectionMatrixID = gl::GetUniformLocation(kCamera->getShaderHandle(), "mProjection");

	// Passes the matrix data to the shader
	gl::UniformMatrix4fv(modelMatrixID, 1, gl::FALSE_, glm::value_ptr(kModel));
	gl::UniformMatrix4fv(viewMatrixID, 1, gl::FALSE_, glm::value_ptr(kCamera->getView()));
	gl::UniformMatrix4fv(projectionMatrixID, 1, gl::FALSE_, glm::value_ptr(kCamera->getPerspective()));

	gl::BindVertexArray(m_vaoHandle);
	gl::DrawElements(gl::TRIANGLES, m_sizeOfIndices / sizeof(GLuint), gl::UNSIGNED_INT, NULL);
	gl::BindVertexArray(0);
}
void Robot::drawArm(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel, const side kSide)
{
	// Scaling matrix
	glm::mat4 scale = glm::mat4 // arm is a 1x4x1 cube
	(
		1, 0, 0, 0,
		0, 4, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
	float fXOffset;

	if (kSide == LEFT)
		fXOffset = 2.5f;
	else
		fXOffset = -1.5f;

	// Translation matrix
	glm::mat4 translate = glm::mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		fXOffset, 0, -0.5, 1
	);
	// Rotational matrix
	glm::mat4 rotate = glm::mat4
	(
		glm::cos(m_fArmAngles[kSide]), 0, -glm::sin(m_fArmAngles[kSide]), 0,
		0, 1, 0, 0,
		glm::sin(m_fArmAngles[kSide]), 0, glm::cos(m_fArmAngles[kSide]), 0,
		0, 0, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	glm::mat4 M = scale * translate * rotate * kModel;

	drawCube(kCamera, M);
}
void Robot::drawHead(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel)
{
	// Scaling matrix
	glm::mat4 scale = glm::mat4 // head is a 2x2x2 cube
	(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 1
	);
	// Translation matrix
	glm::mat4 translate = glm::mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		1, 2, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	glm::mat4 M = scale * translate * kModel;

	drawCube(kCamera, M);

	//glPushMatrix();
	//	glColor3f(1.0f, 1.0f, 1.0f);	// white
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(2.0f, 2.0f, 2.0f);		
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::drawTorso(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel)
{
	// Scaling matrix
	glm::mat4 scale = glm::mat4 // torso is a 3x5x2 cube
	(
		3, 0, 0, 0,
		0, 5, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 1
	);
	// Translation matrix
	glm::mat4 translate = glm::mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		1.5, 0, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	glm::mat4 M = scale * translate * kModel;

	drawCube(kCamera, M);

	//glPushMatrix();
	//	glColor3f(0.0f, 0.0f, 1.0f);	// blue
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(3.0f, 5.0f, 2.0f);		
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::drawLeg(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel, const side kSide)
{
	// Scaling matrix
	glm::mat4 scale = glm::mat4 // leg is a 1x5x1 cube
	(
		1, 0, 0, 0,
		0, 5, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	float fXOffset;

	if (kSide == LEFT)
		fXOffset = -0.5f;
	else
		fXOffset = 1.5f;

	// Translation matrix
	glm::mat4 translate = glm::mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		fXOffset, -5.0, -0.5, 1
	);
	// Rotational matrix
	glm::mat4 rotate = glm::mat4
	(
		glm::cos(m_fLegAngles[kSide]), 0, -glm::sin(m_fLegAngles[kSide]), 0,
		0, 1, 0, 0,
		glm::sin(m_fLegAngles[kSide]), 0, glm::cos(m_fLegAngles[kSide]), 0,
		0, 0, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	glm::mat4 M = scale * translate * rotate * kModel;

	drawCube(kCamera, M);

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
void Robot::drawFoot(const std::shared_ptr<Camera> kCamera, const glm::mat4 kModel, const side kSide)
{
	// Scaling matrix 
	glm::mat4 scale = glm::mat4 // foot is a 1x0.5x3 cube
	(
		1, 0, 0, 0,
		0, 0.5, 0, 0,
		0, 0, 3, 0,
		0, 0, 0, 1
	);

	float fXOffset;

	if (kSide == LEFT)
		fXOffset = -0.5f;
	else
		fXOffset = 1.5f;

	// Translation matrix
	glm::mat4 translate = glm::mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		fXOffset, -5.0, -0.5, 1
	);
	// Rotational matrix
	glm::mat4 rotate = glm::mat4
	(
		glm::cos(m_fLegAngles[kSide]), 0, -glm::sin(m_fLegAngles[kSide]), 0,
		0, 1, 0, 0,
		glm::sin(m_fLegAngles[kSide]), 0, glm::cos(m_fLegAngles[kSide]), 0,
		0, 0, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	glm::mat4 M = scale * translate * rotate * kModel;

	drawCube(kCamera, M);

	//glPushMatrix();
	//	glColor3f(1.0f, 1.0f, 1.0f); // yellow
	//	glTranslatef(xPos, yPos, zPos);
	//	glScalef(1.0f, 0.5f, 3.0f); // foot is a 1x0.5x3 cube
	//	DrawCube(0.0f, 0.0f, 0.0f);
	//glPopMatrix();
}
void Robot::draw(const std::shared_ptr<Camera> kCamera, const glm::vec3 kPosition, const float kfRotation)
{
	// Sets the active shader
	gl::UseProgram(kCamera->getShaderHandle());

	// Scaling matrix
	glm::mat4 scale = glm::mat4 
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
	// Translation matrix
	glm::mat4 translate = glm::mat4
	(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		kPosition.x, kPosition.y, kPosition.z, 1
	);
	// Rotational matrix
	glm::mat4 rotate = glm::mat4
	(
		glm::cos(kfRotation), 0, -glm::sin(kfRotation), 0,
		0, 1, 0, 0,
		glm::sin(kfRotation), 0, glm::cos(kfRotation), 0,
		0, 0, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	glm::mat4 M = scale * translate * rotate;

	drawHead(kCamera, M);
	drawTorso(kCamera, M);

	drawArm(kCamera, M, LEFT);
	drawArm(kCamera, M, RIGHT);

	drawLeg(kCamera, M, LEFT);
	drawLeg(kCamera, M, RIGHT);

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