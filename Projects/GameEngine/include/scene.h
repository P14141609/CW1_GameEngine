#ifndef SCENE_H
#define SCENE_H

// Imports
#include "player.h"
#include "camera.h"
#include "gameobject.h"
#include "collectable.h"
#include "staticobject.h"
#include "light.h"

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
	std::vector<std::shared_ptr<GameObject>> m_pGameObjects; //!< Vector of GameObject pointers for GameObjects within the Scene
	std::vector<std::shared_ptr<Light>> m_pLights; //!< Vector of Light pointers for Lights within the Scene

	std::shared_ptr<Camera> m_pActiveCamera; //!< Pointer to the Camera currently being used

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Constructor
	///
	/// \param kfAspectRatio The window aspect ratio
	///
	///////////////////////////////////////////////// 
	Scene(const float kfAspectRatio);

	/////////////////////////////////////////////////
	///
	/// \brief Processes input
	///
	/// \param kfElapsedTime The time since last update
	///
	///////////////////////////////////////////////// 
	void processInput(const float kfElapsedTime);

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

	std::vector<std::shared_ptr<Camera>> getCameras() { return m_pCameras; } //!< Returns a vector of Camera ptrs
	std::shared_ptr<Camera> getActiveCamera() { return m_pActiveCamera; } //!< Returns the active Camera ptr
};

#endif