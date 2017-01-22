/**
@file model.cpp
*/

// Imports
#include "model.h"

// Constructor
Model::Model(const std::string ksObjectFile, const std::string ksTextureFile, const glm::vec3 kPosition, const float kfRotation)
{
	m_sObjectFile = ksObjectFile;

	m_position = kPosition;
	m_fRotation = kfRotation;

	m_modelData = ModelLoader::loadObj(ksObjectFile);
	TextureLoader::loadBMP(ksTextureFile, m_textureID);
}

// Void: Called to render the Model
void Model::render()
{
	glPushMatrix();

		glTranslatef(m_position.x, m_position.y, m_position.z);
		glRotatef(m_fRotation, false, true, false);

		// activate and specify pointer to vertex array
		glEnableClientState(GL_VERTEX_ARRAY);

		std::vector<float>& vertices = m_modelData.vertexTriplets;

		glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);

		// pointer to normal array
		if (m_modelData.vertexNormalTriplets.size() > 0)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			std::vector<float>& normals = m_modelData.vertexNormalTriplets;
			glNormalPointer(GL_FLOAT, 0, &normals[0]);
		}
		else
		{
			sf::err() << m_sObjectFile << " missing normals." << std::endl;
		}

		if (m_modelData.vertexTexturePairs.size() > 0)
		{
			glEnable(GL_TEXTURE_2D);	// we are using textures
			std::vector<float>& textureCoordinates = m_modelData.vertexTexturePairs;
			glBindTexture(GL_TEXTURE_2D, m_textureID);

			glEnableClientState(GL_TEXTURE_COORD_ARRAY); //glTexCoordPointer will point to an array
			glTexCoordPointer(2, GL_FLOAT, 0, &textureCoordinates[0]);
		}
		else
		{
			sf::err() << m_sObjectFile << " missing texture coordinates." << std::endl;
		}

		// draw the shape...
		glDrawArrays(GL_TRIANGLES, 0, (unsigned int)vertices.size() / 3);

		// deactivate vertex arrays after drawing
		glDisableClientState(GL_VERTEX_ARRAY);

		if (m_modelData.vertexNormalTriplets.size() > 0)
		{
			// deactivate
			glDisableClientState(GL_NORMAL_ARRAY);
		}

		if (m_modelData.vertexTexturePairs.size() > 0)
		{
			// tidy up
			glBindTexture(GL_TEXTURE_2D, NULL);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisable(GL_TEXTURE_2D);
		}

	glPopMatrix();
}