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
	/// \param ksObjectFile The file path to an object file
	/// \param ksTextureFile The file path to an image file
	/// \param kPosition Vector for Model position
	/// \param kfRotation Float for Model rotation angle
	///
	///////////////////////////////////////////////// 
	Model(const std::string ksObjectFile, const std::string ksTextureFile, const glm::vec3 kPosition, const float kfRotation);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Model
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif