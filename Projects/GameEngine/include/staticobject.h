#ifndef STATICOBJECT_H
#define STATICOBJECT_H

// Imports
#include "gameobject.h"

/////////////////////////////////////////////////
///
/// \brief Class for static object handling
/// 
/////////////////////////////////////////////////
class StaticObject : public GameObject
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
	/// \param kPosition Vector for StaticObject position
	/// \param kfRotation Float for StaticObject rotation angle
	///
	///////////////////////////////////////////////// 
	StaticObject(const std::string ksObjectFile, const std::string ksTextureFile, const glm::vec3 kPosition, const float kfRotation);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the StaticObject
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif