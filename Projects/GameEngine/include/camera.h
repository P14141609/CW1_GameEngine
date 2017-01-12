#ifndef CAMERA_H
#define CAMERA_H

// Imports
#include "glm.hpp"
#include "gl_core_4_3.hpp"
#include "gtc\matrix_transform.hpp"
#include "gtc\type_ptr.hpp"

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
	GLuint m_shaderHandle; //!< Stores the program handle of the camera shader

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param kPosition Position of the Camera
	/// \param kTargetPos Position the Camera is aimed at
	/// \param kPerspective Camera perspective settings
	///
	///////////////////////////////////////////////// 
	Camera(const glm::vec3 kPosition, const glm::vec3 kTargetPos, const glm::mat4 kPerspective);

	glm::mat4 getView() { return m_view; }; //!< Returns the view matrix
	glm::mat4 getPerspective() { return m_perspective; }; //!< Returns the perspective matrix
	GLuint getShaderHandle() { return m_shaderHandle; }; //!< Returns the shader program handle
};

#endif