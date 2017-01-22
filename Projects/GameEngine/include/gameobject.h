#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Imports
#include "model.h"
#include "glm.hpp"

/////////////////////////////////////////////////
///
/// \brief Abstract base class for game object handling
/// 
/////////////////////////////////////////////////
class GameObject
{
protected:

	glm::vec3 m_position; //!< Position vector
	float m_rotation; //!< Rotation angle

	std::shared_ptr<Model> m_pModel; //!< Model for rendering

public:

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the GameObject
	///
	///////////////////////////////////////////////// 
	virtual void render() = 0;
};

#endif