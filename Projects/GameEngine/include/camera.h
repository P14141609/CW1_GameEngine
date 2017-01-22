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
	float m_fFOV; //!< Field of view
	float m_fAspectRatio; //!< Display aspect ratio
	float m_fNear; //!< Near clipping distance
	float m_fFar; //!< Far clipping distance

	glm::vec3 m_position; //!< Position Vector
	glm::vec3 m_direction; //!< Direction unit vector
	glm::vec3 m_up; //!< 'Up' vector

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param kPosition Position of the Camera
	/// \param kDirection Direction of the Camera
	/// \param kfAspectRatio Display aspect ratio
	/// \param kfFOV Display field of view 
	/// \param kfNear Display near clipping distance
	/// \param kfFar Display far clipping distance
	///
	///////////////////////////////////////////////// 
	Camera(const glm::vec3 kPosition, const glm::vec3 kDirection, const float kfFOV, const float kfAspectRatio, const float kfNear, const float kfFar);
	
	void setAspectRatio(const float kfAspectRatio) { m_fAspectRatio = kfAspectRatio; }; //!< Sets a new Camera aspect ratio

	glm::vec3 getPosition() { return m_position; }; //!< Returns Camera position
	glm::vec3 getDirection() { return m_direction; }; //!< Returns Camera direction
	glm::vec3 getUp() { return m_up; } //!< Returns Camera 'up'
	float getFOV() { return m_fFOV; }; //!< Returns Camera field of view
	float getAspectRatio() { return m_fAspectRatio; }; //!< Returns Camera display aspect ratio
	float getNear() { return m_fNear; }; //!< Returns Camera near clipping distance
	float getFar() { return m_fFar; }; //!< Returns Camera far clipping distance
};

#endif