#ifndef COLLECTABLE_H
#define COLLECTABLE_H

// Imports
#include "gameobject.h"

/////////////////////////////////////////////////
///
/// \brief Class for collectable object handling
/// 
/////////////////////////////////////////////////
class Collectable : public GameObject
{
private:

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param ksObjectFile The file path to an object file
	/// \param ksTextureFile The file path to an image file
	/// \param kPosition Vector for Collectable position
	/// \param kfRotation Float for Collectable rotation angle
	///
	///////////////////////////////////////////////// 
	Collectable(const std::string ksObjectFile, const std::string ksTextureFile, const glm::vec3 kPosition, const float kfRotation);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Collectable
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif