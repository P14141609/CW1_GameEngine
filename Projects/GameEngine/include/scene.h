#ifndef SCENE_H
#define SCENE_H

// Imports
#include "player.h"
#include "model.h"
#include "camera.h"
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

	std::vector<std::shared_ptr<Camera>> m_pCameras; //!< Vector of Camera pointers for Cameras within the Scene
	std::vector<std::shared_ptr<Model>> m_pModels; //!< Vector of Model pointers for Models within the Scene
	
	std::shared_ptr<Camera> m_pActiveCamera; //!< Pointer to the Camera currently being used

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