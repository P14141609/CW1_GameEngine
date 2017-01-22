#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

// Imports
#include <SFML\glew.h>		
#include <SFML\OpenGL.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\wglext.h>
#include <SFML\glext.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/////////////////////////////////////////////////
///
/// \brief Class for image file loading
/// 
/////////////////////////////////////////////////
class TextureLoader
{
public:

	/////////////////////////////////////////////////
	///
	/// \brief Loads a bitmap and binds it to the referenced texture handle
	///
	/// \param ksTextureFile The file path to an image file
	/// \param texture A texture handle pointer
	///
	///////////////////////////////////////////////// 
	static int loadBMP(const std::string ksTextureFile, GLuint &texture);
};

#endif