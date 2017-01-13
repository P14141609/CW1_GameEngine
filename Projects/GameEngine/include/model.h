#ifndef MODEL_H
#define MODEL_H

// Imports
#include "glm.hpp"
#include "gl_core_4_3.hpp"

#include <GLFW/glfw3.h>
#include <memory>
#include <vector>

#include "camera.h"

/////////////////////////////////////////////////
///
/// \brief Class for model handling
/// 
/////////////////////////////////////////////////
class Model
{
private:
	glm::vec3 m_position; //!< Model position vector
	float m_fRotation; //!< Model rotation angle

	GLuint m_vboHandles[3];
	GLuint m_vaoHandle;
	GLuint m_indexDataSize;

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	///////////////////////////////////////////////// 
	Model();

	/////////////////////////////////////////////////
	///
	/// \brief Loads an obj file into the class
	///
	/// \param ksFilePath The file path to a specified .obj file
	///
	///////////////////////////////////////////////// 
	void loadFromObj(const std::string ksFilePath);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Model
	///
	/// \param kCamera Camera pointer to use in rendering
	///
	///////////////////////////////////////////////// 
	void render(const std::shared_ptr<Camera> kCamera);
};

#endif