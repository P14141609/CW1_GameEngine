/**
@file scene.cpp
*/

// Imports
#include "scene.h"

// Constructor
Scene::Scene(const float kfAspectRatio)
{
	// Pushes new Camera pointer onto vector of Cameras
	// Camera #1
	m_pCameras.push_back
	(
		std::shared_ptr<Camera>
		(
			new Camera
			(
				glm::vec3(0.0f, 5.0f, 10.0f),
				glm::vec3(0.0f, 0.0f, -1.0f),
				120.0f,
				kfAspectRatio,
				0.0f,
				1000.0f
			)
		)
	);

	// Sets the active Camera to the first in the vector
	m_pActiveCamera = m_pCameras.at(0);

	// Pushes new GameObject pointer onto vector of GameObjects
	// GameObject #1
	m_pGameObjects.push_back
	(
		std::shared_ptr<GameObject>
		(
<<<<<<< HEAD
			new Model("", "", glm::vec3(0.0f, 0.0f, 0.0f), 0.0f)
=======
			new Collectable()
		)
	);
	// GameObject #2
	m_pGameObjects.push_back
	(
		std::shared_ptr<GameObject>
		(
			new StaticObject()
>>>>>>> master
		)
	);

	// Sets display perspective setting
	gluPerspective(m_pActiveCamera->getFOV(), m_pActiveCamera->getAspectRatio(), m_pActiveCamera->getNear(), m_pActiveCamera->getFar());
}

// Void: Processes input
void Scene::processInput(const float kfElapsedTime)
{
	// For every key on the keyboard
	for (int i = 0; i <= sf::Keyboard::KeyCount; i++)
	{
		// If the key is pressed then pass it to Player
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i))) m_player.processKeyInput(i, kfElapsedTime);
	}
}

// Void: Called to update the Scene
void Scene::update(const float kfElapsedTime)
{
	processInput(kfElapsedTime);

	m_player.update(kfElapsedTime);
}

// Void: Called to render the Scene
void Scene::render()
{
	// Configures the view with activeCamera
	gluLookAt
	(
		// Camera Position
		m_pActiveCamera->getPosition().x,
		m_pActiveCamera->getPosition().y,
		m_pActiveCamera->getPosition().z,
		// Camera Direction + Position
		m_pActiveCamera->getDirection().x + m_pActiveCamera->getPosition().x,
		m_pActiveCamera->getDirection().y + m_pActiveCamera->getPosition().y,
		m_pActiveCamera->getDirection().z + m_pActiveCamera->getPosition().z,
		// Camera Up
		m_pActiveCamera->getUp().x,
		m_pActiveCamera->getUp().y,
		m_pActiveCamera->getUp().z
	);

	// Renders the Player
	m_player.render();

	// Renders all GameObjects
	for (std::shared_ptr<GameObject> pGameObject : m_pGameObjects) pGameObject->render();
}