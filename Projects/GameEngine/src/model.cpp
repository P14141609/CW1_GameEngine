/**
@file model.cpp
*/

// Imports
#include "stdafx.h"
#include "model.h"

#include "glm.hpp"
#include "gl_core_4_3.hpp"
#include <GLFW/glfw3.h>

// Constructor
Model::Model()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_fRotation = 0.0f;

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

	m_indexDataSize = sizeof(indexData);

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
	gl::BufferData(gl::ELEMENT_ARRAY_BUFFER, m_indexDataSize, indexData, gl::STATIC_DRAW);

	gl::EnableVertexAttribArray(0);  // Vertex position

	gl::BindBuffer(gl::ARRAY_BUFFER, positionBufferHandle);
	gl::VertexAttribPointer(0, 3, gl::FLOAT, FALSE, 0, (GLubyte *)NULL);
}

// Void: Loads an obj file into the class
void Model::loadFromObj(const std::string ksFilePath)
{
	// TODO
}

// Void: Called to render the Model
void Model::render(const std::shared_ptr<Camera> kCamera)
{
	// Sets the active shader
	//gl::UseProgram(kCamera->getShaderHandle());

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
		m_position.x, m_position.y, m_position.z, 1
	);
	// Rotational matrix
	glm::mat4 rotate = glm::mat4
	(
		glm::cos(m_fRotation), 0, -glm::sin(m_fRotation), 0,
		0, 1, 0, 0,
		glm::sin(m_fRotation), 0, glm::cos(m_fRotation), 0,
		0, 0, 0, 1
	);

	// Defines Model position matrix = The sum up all the matraces
	//glm::mat4 M = scale * translate * rotate;
	//
	//// Gets the location ID of the non-uniform variable in the shader
	//GLint posID = gl::GetAttribLocation(kCamera->getShaderHandle(), "vertPosition");
	//// Gets the location ID of the uniform variables in the shader
	//GLint modelMatrixID = gl::GetUniformLocation(kCamera->getShaderHandle(), "mModel");
	//GLint viewMatrixID = gl::GetUniformLocation(kCamera->getShaderHandle(), "mView");
	//GLint projectionMatrixID = gl::GetUniformLocation(kCamera->getShaderHandle(), "mProjection");
	//
	//// Passes the matrix data to the shader
	//gl::UniformMatrix4fv(modelMatrixID, 1, gl::FALSE_, glm::value_ptr(M));
	//gl::UniformMatrix4fv(viewMatrixID, 1, gl::FALSE_, glm::value_ptr(kCamera->getView()));
	//gl::UniformMatrix4fv(projectionMatrixID, 1, gl::FALSE_, glm::value_ptr(kCamera->getPerspective()));
	//
	//gl::BindVertexArray(m_vaoHandle);
	//gl::DrawElements(gl::TRIANGLES, m_indexDataSize / sizeof(GLuint), gl::UNSIGNED_INT, NULL);
	//gl::BindVertexArray(0);
}