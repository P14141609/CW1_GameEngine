#ifndef CAMERA_H
#define CAMERA_H

// Imports
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <string>
#include "glm.hpp"
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
	float m_fFOV; //!< Camera field of view
	float m_fAspectRatio; //!< Camera display aspect ratio
	float m_fNear; //!< Camera near clipping distance
	float m_fFar; //!< Camera far clipping distance

	glm::vec3 m_position; //!< Vector for the Camera position
	glm::vec3 m_direction; //!< Vector for the Camera direction
	glm::vec3 m_up; //!< Vector for the Camera's 'Up'

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param kPosition Position of the Camera
	/// \param kDirection Direction of the Camera
	/// \param kfAspectRatio
	/// \param kfFOV
	/// \param kfNear
	/// \param kfFar
	///
	///////////////////////////////////////////////// 
	Camera(const glm::vec3 kPosition, const glm::vec3 kDirection, const float kfFOV, const float kfAspectRatio, const float kfNear, const float kfFar);

	/////////////////////////////////////////////////
	///
	/// \brief 
	///
	/// \param kfAspectRatio
	///
	///////////////////////////////////////////////// 
	void setAspectRatio(const float kfAspectRatio) { m_fAspectRatio = kfAspectRatio; };

	glm::vec3 getPosition() { return m_position; }; //!< Returns the Camera's position
	glm::vec3 getDirection() { return m_direction; }; //!< Returns the Camera's direction
	glm::vec3 getUp() { return m_up; } //!< Returns the Camera's 'up'
	float getFOV() { return m_fFOV; }; //!< Returns the Camera's field of view
	float getAspectRatio() { return m_fAspectRatio; }; //!< Returns the Camera's display aspect ratio
	float getNear() { return m_fNear; }; //!< Returns the Camera's near clipping distance
	float getFar() { return m_fFar; }; //!< Returns the Camera's far clipping distance
};

#endif