#ifndef CAMERA_H
#define CAMERA_H

// Imports
#include <memory>
#include <string>
#include "glm.hpp"
#include "gl_core_4_3.hpp"

#include "gtc\matrix_transform.hpp"
#include "gtc\type_ptr.hpp"

#include "glslprogram.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/////////////////////////////////////////////////
///
/// \brief Class for camera handling
/// 
/////////////////////////////////////////////////
class Camera
{
private:
	glm::mat4 m_view; //!< Matrix for the camera view
	glm::mat4 m_perspective; //!< Matrix for the camera perspective

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param ksShaderFile Path to the shader files 
	/// \param kPosition Position of the Camera
	/// \param kTargetPos Position the Camera is aimed at
	/// \param kPerspective Camera perspective settings
	///
	///////////////////////////////////////////////// 
	Camera(glm::vec3 kPosition, const glm::vec3 kTargetPos, const glm::mat4 kPerspective);

	glm::mat4 getView() { return m_view; }; //!< Returns the view matrix
	glm::mat4 getPerspective() { return m_perspective; }; //!< Returns the perspective matrix
};

#endif