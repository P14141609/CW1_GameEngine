/**
@file camera.cpp
*/

// Imports
#include "stdafx.h"
#include "camera.h"

// Constructor
Camera::Camera(const std::string ksShaderFile, const glm::vec3 kPosition, const glm::vec3 kTargetPos, const glm::mat4 kPerspective)
{
	// Defines View
	m_view = glm::lookAt
	(
		kPosition, // Camera Pos
		kTargetPos, // Camera looking at
		glm::vec3(0.0, 1.0, 0.0)  // Camera 'Up'
	);

	// Defines Perspective
	m_perspective = kPerspective;
}

void Camera::initShader(const std::string ksShaderFile)
{
	// Tries to compile the external shaders to the shader member
	try {
		m_shader.compileShader(std::string(ksShaderFile + ".vert").c_str());
		m_shader.compileShader(std::string(ksShaderFile + ".frag").c_str());
		m_shader.link();
		m_shader.validate();
		m_shader.use();
	}
	catch (GLSLProgramException & e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}
