/**
@file scene.cpp
*/

// Imports
#include "stdafx.h"
#include "scene.h"

// Constructor
Scene::Scene()
{
	// Pushes new Camera pointer onto vector of Cameras
	// Camera #1
	m_pCameras.push_back
	(
		std::shared_ptr<Camera>
		(
			new Camera
			(
				"res/Shaders/basic",
				glm::vec3(0.0f, 5.0f, 10.0f),
				glm::vec3(0.0f, 0.0f, 0.0f),
				glm::perspective
				(
					120.f,
					(float)1280 / 720, // TEMPORARY
					0.0f,
					1000.0f
				)
			)
		)
	);

	// Sets the active Camera to the first in the vector
	m_pActiveCamera = m_pCameras.at(0);

	m_pModels.push_back
	(
		std::shared_ptr<Model>(new Model())
	);
}

// Void: Called to update the Scene
void Scene::update(const float kfElapsedTime)
{
	m_player.update(kfElapsedTime);
}

// Void: Called to render the Scene
void Scene::render()
{
	m_player.render(m_pActiveCamera);

	for (std::shared_ptr<Model> model : m_pModels) 
		model->render(m_pActiveCamera);
}