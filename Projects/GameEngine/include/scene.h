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
	Player m_player = Player(glm::vec3(0.0f, 0.0f, 0.0f), 0.0f); //!< Player member for character handling

	std::vector<std::shared_ptr<Camera>> m_pCameras; //!< Vector of Camera pointers for Cameras within the Scene
	std::vector<std::shared_ptr<Model>> m_pModels; //!< Vector of Model pointers for Models within the Scene
	
	std::shared_ptr<Camera> m_pActiveCamera; //!< Pointer to the Camera currently being used

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param fAspectRatio The window aspect ratio
	///
	///////////////////////////////////////////////// 
	Scene(float fAspectRatio);

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

	std::vector<std::shared_ptr<Camera>> getCameras() { return m_pCameras; } //!< Returns a vector of Cameras
};

#endif