/**
@file model.cpp
*/

// Imports
#include "model.h"

// Constructor
Model::Model(const std::string ksObjectFile, const std::string ksTextureFile)
{
	m_sObjectFile = ksObjectFile;

	ModelLoader::loadObj(ksObjectFile, m_modelData);
	TextureLoader::loadBMP(ksTextureFile, m_textureID);
}

// Void: Called to render the Model
void Model::render(const glm::vec3 kPosition, const float kfRotation)
{
	GLfloat materialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat materialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat materialShininess = 4.0f; // Lower for a sharper specular highlight
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);

	glPushMatrix();

		glTranslatef(kPosition.x, kPosition.y, kPosition.z);
		glRotatef(kfRotation, false, true, false);

		////////////////////////////////////////////////////////
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
		else sf::err() << m_sObjectFile << " missing normals." << std::endl;

		if (m_modelData.vertexTexturePairs.size() > 0)
		{
			glEnable(GL_TEXTURE_2D);	// we are using textures
			std::vector<float>& textureCoordinates = m_modelData.vertexTexturePairs;
			glBindTexture(GL_TEXTURE_2D, m_textureID);

			glEnableClientState(GL_TEXTURE_COORD_ARRAY); //glTexCoordPointer will point to an array
			glTexCoordPointer(2, GL_FLOAT, 0, &textureCoordinates[0]);
		}
		else sf::err() << m_sObjectFile << " missing texture coordinates." << std::endl;

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