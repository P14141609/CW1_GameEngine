#ifndef MODEL_H
#define MODEL_H

// Imports
#include "glm.hpp"
#include "gl_core_4_3.hpp"
#include "Texture.h"

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

	Texture* m_pTexture;
	
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
	/// \brief Initialises Model handles
	///
	/// \param kfPositionData
	/// \param kfUVData
	/// \param kIndexData
	///
	///////////////////////////////////////////////// 
	void initModel(const float kfPositionData[], const float kfUVData[], const GLuint kIndexData[]);

	/////////////////////////////////////////////////
	///
	/// \brief Initialises the Model texture
	///
	/// \param ksFilePath The file path to a specified texture file
	///
	///////////////////////////////////////////////// 
	void initTexture(const std::string ksFilePath);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Model
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif