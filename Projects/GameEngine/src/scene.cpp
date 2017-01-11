/**
@file scene.cpp
*/

// Imports
#include "scene.h"

// Constructor
Scene::Scene()
{
	// TODO
}

// Void: Called to update the Scene
void Scene::update(const float kfElapsedTime)
{
	m_player.update(kfElapsedTime);
}

// Void: Called to render the Scene
void Scene::render()
{
	m_player.render();

	for (std::shared_ptr<Model> model : m_pModels) 
		model->render();
}