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
	/// \param kPosition Vector for Collectable position
	/// \param kfRotation Float for Collectable rotation angle
	///
	///////////////////////////////////////////////// 
	Collectable(const glm::vec3 kPosition, const float kfRotation);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Collectable
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif