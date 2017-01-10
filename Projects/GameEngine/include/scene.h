#ifndef SCENE_H
#define SCENE_H

// Imports
#include "player.h"
#include "model.h"
#include <memory>
#include <vector>

/////////////////////////////////////////////////
///
/// \brief Class for world handling
/// 
/////////////////////////////////////////////////
class Scene
{
private:
	Player m_player = Player(0.0f, 0.0f, 0.0f, 0.0f); //!< Player member for character handling
	std::vector<std::shared_ptr<Model>> m_models; //!< Vector of Model pointers to associated Models in the Scene

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	///////////////////////////////////////////////// 
	Scene();

	/////////////////////////////////////////////////
	///
	/// \brief Called to update the Scene
	///
	/// \param kfElapsedTime The time since last update
	///
	///////////////////////////////////////////////// 
	void update(const float kfElapsedTime);

	/////////////////////////////////////////////////
	///
	/// \brief Called to render the Scene
	///
	///////////////////////////////////////////////// 
	void render();
};

#endif