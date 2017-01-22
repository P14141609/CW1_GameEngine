#ifndef MODEL_H
#define MODEL_H

// Imports
#include "camera.h"
#include "modelloader.h"
#include "textureloader.h"

#include <SFML\glew.h>		
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\wglext.h>
#include <SFML\glext.h>

#include <string>
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

	std::string m_sObjectFile; //!< Holds the obj file path

	ModelData m_modelData; //!< Stores Model data for rendering
	GLuint m_textureID; //!< Model Texture handle

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param ksObjectFile The file path to an object file
	/// \param ksTextureFile The file path to an image file
	///
	///////////////////////////////////////////////// 
	Model(const std::string ksObjectFile, const std::string ksTextureFile);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Model
	///
	/// \param kPosition Vector for Model position
	/// \param kfRotation Float for Model rotation angle
	///
	///////////////////////////////////////////////// 
	void render(const glm::vec3 kPosition, const float kfRotation);
};

#endif