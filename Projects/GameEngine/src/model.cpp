/**
@file model.cpp
*/

// Imports
#include "model.h"

// Constructor
Model::Model()
{
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_fRotation = 0.0f;

	// TEMPORARY
	loadFromObj("Irrelevant");
}

// Void: Loads an obj file into the class
void Model::loadFromObj(const std::string ksFilePath)
{
	//// TEMPORARY
	//// GENERATE UNIT CUBE
	//float fPositionData[] =
	//{
	//	 1.0f,  1.0f,  1.0f,	// 0
	//	-1.0f,  1.0f,  1.0f,	// 1
	//	 1.0f,  1.0f, -1.0f,	// 2
	//	-1.0f,  1.0f, -1.0f,	// 3
	//
	//	 1.0f, -1.0f,  1.0f,	// 4
	//	-1.0f, -1.0f,  1.0f,	// 5
	//	 1.0f, -1.0f, -1.0f,	// 6
	//	-1.0f, -1.0f, -1.0f		// 7
	//};
	//
	//float fUVData[] =
	//{
	//	0.0f, 0.0f,
	//	0.0f, 0.0f,
	//	0.0f, 0.0f,
	//	0.0f, 0.0f,
	//
	//	0.0f, 0.0f,
	//	0.0f, 0.0f,
	//	0.0f, 0.0f,
	//	0.0f, 0.0f,
	//};
	//
	//GLuint indexData[] =
	//{
	//	1, 0, 2,
	//	1, 3, 2,
	//
	//	1, 0, 4,
	//	1, 5, 4,
	//
	//	2, 0, 4,
	//	2, 6, 4,
	//
	//	3, 2, 6,
	//	3, 7, 6,
	//
	//	1, 3, 7,
	//	1, 5, 7,
	//
	//	5, 4, 6,
	//	5, 7, 6
	//};
	//
	//m_indexDataSize = sizeof(indexData);
	//
	//initModel(fPositionData, fUVData, indexData);
	//initTexture("res/Textures/Red500x500.png");
}

// Void: Initialises the Model
void Model::initModel()
{
	
}

// Void: Initialises the Model texture
void Model::initTexture(const std::string ksFilePath)
{
	
}

// Void: Called to render the Model
void Model::render()
{
	glPushMatrix();

		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_fRotation, false, true, false);

		// Draw model

	glPopMatrix();
}