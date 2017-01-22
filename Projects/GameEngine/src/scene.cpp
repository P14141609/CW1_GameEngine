/**
@file scene.cpp
*/

// Imports
#include "scene.h"

// Constructor
Scene::Scene(const float kfAspectRatio)
{
	XmlData configuration;
	// Loads the xml config file into the configuration variable
	XMLLoader::loadXml("res/configs/scene01.xml", configuration);

	m_pPlayer = configuration.player;

	m_pCameras = configuration.cameras;
	m_pGameObjects = configuration.gameobjects;
	m_pLights = configuration.lights;

	// PLACEHOLDER BELOW //////////////////////////////////////////
	m_pPlayer = std::shared_ptr<Player>(new Player(glm::vec3(0.0f, 0.0f, 0.0f), 0.0f));

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
				70.0f,
				kfAspectRatio,
				0.0f,
				1000.0f
			)
		)
	);
	// Camera #2
	m_pCameras.push_back
	(
		std::shared_ptr<Camera>
		(
			new Camera
			(
				glm::vec3(-10.0f, 5.0f, 0.0f),
				glm::vec3(1.0f, 0.0f, 0.0f),
				120.0f,
				kfAspectRatio,
				0.0f,
				1000.0f
			)
		)
	);


	// Pushes new GameObject pointer onto vector of GameObjects
	// GameObject #1
	m_pGameObjects.push_back
	(
		std::shared_ptr<GameObject>
		(
			new Collectable("res/models/x-35_obj.obj", "res/textures/x-35.bmp", glm::vec3(0.0f, 0.0f, -20.0f), 0.0f)
		)
	);
	// GameObject #2
	m_pGameObjects.push_back
	(
		std::shared_ptr<GameObject>
		(
			new StaticObject("res/models/terrain.obj", "res/textures/terrainTexture.bmp", glm::vec3(0.0f, -2500.0f, 0.0f), 0.0f)
		)
	);

	// Pushes new Light pointer onto vector of Lights
	// GameObject #2
	m_pLights.push_back
	(
		std::shared_ptr<Light>
		(
			new Light(glm::vec3(0.0f, 25.0f, 0.0f))
		)
	);
	// PLACEHOLDER ABOVE //////////////////////////////////////////

	// Sets the active Camera to the first in the vector
	m_pActiveCamera = m_pCameras.at(0);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i))) m_pPlayer->processKeyInput(i, kfElapsedTime);
	}

	// TEMPORARY
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
	{
		m_pActiveCamera = m_pCameras.at(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
	{
		m_pActiveCamera = m_pCameras.at(1);
	}
}

// Void: Called to update the Scene
void Scene::update(const float kfElapsedTime)
{
	// Processes input
	processInput(kfElapsedTime);

	// Configures all light sources
	for (std::shared_ptr<Light> pLight : m_pLights) pLight->configureGL();

	// Updates the Player
	m_pPlayer->update(kfElapsedTime);
}

// Void: Called to render the Scene
void Scene::render()
{
	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
	glLoadIdentity();

	gluPerspective(m_pActiveCamera->getFOV(), m_pActiveCamera->getAspectRatio(), m_pActiveCamera->getNear(), m_pActiveCamera->getFar());
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Configures the view with activeCamera
	gluLookAt
	(
		// Camera Position
		m_pActiveCamera->getPosition().x,
		m_pActiveCamera->getPosition().y,
		m_pActiveCamera->getPosition().z,
		// Camera Direction + Position
		m_pPlayer->getPosition().x,
		m_pPlayer->getPosition().y,
		m_pPlayer->getPosition().z,
		//m_pActiveCamera->getDirection().x + m_pActiveCamera->getPosition().x,
		//m_pActiveCamera->getDirection().y + m_pActiveCamera->getPosition().y,
		//m_pActiveCamera->getDirection().z + m_pActiveCamera->getPosition().z,
		// Camera Up
		m_pActiveCamera->getUp().x,
		m_pActiveCamera->getUp().y,
		m_pActiveCamera->getUp().z
	);
	
	// Renders the Player
	m_pPlayer->render();
	
	// Renders all GameObjects
	for (std::shared_ptr<GameObject> pGameObject : m_pGameObjects) pGameObject->render();
}