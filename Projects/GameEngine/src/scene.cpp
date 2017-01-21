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

	// Pushes new Model pointer onto vector of Models
	// Model #1
	m_pModels.push_back
	(
		std::shared_ptr<Model>
		(
			new Model()
		)
	);

	// Sets display perspective setting
	gluPerspective(getActiveCamera()->getFOV(), getActiveCamera()->getAspectRatio(), getActiveCamera()->getNear(), getActiveCamera()->getFar());
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

	m_player.render();

	for (std::shared_ptr<Model> model : m_pModels) model->render();
}