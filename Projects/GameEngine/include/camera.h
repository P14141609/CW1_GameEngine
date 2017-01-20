#ifndef CAMERA_H
#define CAMERA_H

// Imports
#include <memory>
#include <string>
#include "glm.hpp"
#include "gl_core_4_3.hpp"

#include "gtc\matrix_transform.hpp"
#include "gtc\type_ptr.hpp"

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
	float m_fFOV = 120.f;
	float m_fNear = 0.f;
	float m_fFar = 1000.f;

	glm::vec3 m_position; //! Vector for the Camera position
	glm::mat4 m_view; //!< Matrix for the Camera view
	glm::mat4 m_perspective; //!< Matrix for the Camera perspective

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param kPosition Position of the Camera
	/// \param kTargetPos Position the Camera is aimed at
	/// \param kfAspectRatio
	/// \param kfFOV
	/// \param kfNear
	/// \param kfFar
	///
	///////////////////////////////////////////////// 
	Camera(glm::vec3 kPosition, const glm::vec3 kTargetPos, const float kfAspectRatio, const float kfFOV, const float kfNear, const float kfFar);

	/////////////////////////////////////////////////
	///
	/// \brief 
	///
	/// \param kfAspectRatio
	///
	///////////////////////////////////////////////// 
	void resize(const float kfAspectRatio);

	glm::vec3 getPosition() { return m_position; }; //!< Returns the Camera position
	glm::mat4 getView() { return m_view; }; //!< Returns the Camera view matrix
	glm::mat4 getPerspective() { return m_perspective; }; //!< Returns the Camera perspective matrix
};

#endif