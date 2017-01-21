#ifndef MODEL_H
#define MODEL_H

// Imports
#include "camera.h"

#include <SFML\glew.h>		
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\wglext.h>
#include <SFML\glext.h>

#include <memory>
#include <vector>
#include "glm.hpp"


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

	//Texture* m_pTexture;
	
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
	void initModel();

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