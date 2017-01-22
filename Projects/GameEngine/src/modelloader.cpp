/**
@file modelloader.cpp
*/

// Imports
#include "modelloader.h"

// Void: Loads a .obj and binds the data to the referenced input variable
void ModelLoader::loadObj(const std::string ksObjectFile, ModelData &modelData)
{
	std::fstream modelfile(ksObjectFile, std::ios_base::in);

	if (!modelfile.is_open())
	{
		std::cerr << "Model \"" << ksObjectFile << "\" not found.";
		throw std::invalid_argument("File not found");
		return;
	}
	else
	{
		std::cerr << "Model \"" << ksObjectFile << "\" successfully loaded." << std::endl;
	}

	std::vector<float> vertices;
	std::vector<float> vertexNormals;
	std::vector<float> vertexTextureCoordinates;

	// Storage for processed data in a format for opengl
	std::vector<unsigned int> faceVertexIndices;
	std::vector<unsigned int> faceTextureIndices;
	std::vector<unsigned int> faceNormalIndices;

	std::string line;
	std::string token = "";
	while (std::getline(modelfile, line))
	{
		std::istringstream iss(line);

		// process the line
		token = "";

		iss >> token; // read to first whitespace

		if (token == "#")
		{
			// ignore rest of line
			// iss >> s;
		}
		else if (token == "v")
		{
			// store 3 floats in m_vertices vector
			float fX, fY, fZ;

			while (iss >> fX >> fY >> fZ)
			{
				vertices.push_back(fX);
				vertices.push_back(fY);
				vertices.push_back(fZ);
			}
		}
		else if (token == "vn")
		{
			// store 3 floats in m_vertexNormals vector
			float fX, fY, fZ;

			while (iss >> fX >> fY >> fZ)
			{
				vertexNormals.push_back(fX);
				vertexNormals.push_back(fY);
				vertexNormals.push_back(fZ);
			}
		}
		else if (token == "vt")
		{
			// store 2 floats in m_vertexTextureCoordinates vector
			float fX, fY;

			while (iss >> fX >> fY)
			{
				vertexTextureCoordinates.push_back(fX);
				vertexTextureCoordinates.push_back(fY);
			}
		}
		else if (token == "f")
		{
			unsigned int uiV, uiT, uiN;

			for (int i = 0; i < 3; i++)
			{
				iss >> uiV; // Passes first character to vertex
				faceVertexIndices.push_back(uiV - 1);

				int nextChar = iss.peek(); // Peek next character
				if (nextChar == '/') // Next is slash
				{
					iss.ignore(1); // Ignores next char
					int nextChar = iss.peek(); // Peek next character
					if (nextChar != '/') // If next character is a forward slash
					{
						iss >> uiT;
						faceTextureIndices.push_back(uiT - 1);
					}

					iss.ignore(1); // Read the slash

					// Read the normal index
					iss >> uiN;
					faceNormalIndices.push_back(uiN - 1);
				}
			}
		}
		else
		{
			// ignore any line without these qualifiers
			// ignore rest of line
		}
	}

	for (std::vector<unsigned int>::iterator it = faceVertexIndices.begin(); it != faceVertexIndices.end(); ++it)
	{
		int vertexNumber = (*it);
		// 3 floats per triangular face

		// index and copy 3 floats to the m_vertexTriplets vector
		for (int i = 0; i < 3; i++)
		{
			modelData.vertexTriplets.push_back(vertices.at(vertexNumber * 3 + i));
		}
	}

	// we create a list of normal triplets for each face (with duplicates)
	// this will then be the same size as the m_vertexTriplets vector
	for (std::vector<unsigned int>::iterator it = faceNormalIndices.begin(); it != faceNormalIndices.end(); ++it)
	{
		//here we have a 1 base index
		// get the face number as 0 indexed
		int vertexNormalNumber = (*it);

		// index and copy 3 floats to the m_vertexNormalTriplets vector
		for (int i = 0; i < 3; i++)
		{
			modelData.vertexNormalTriplets.push_back(vertexNormals.at(vertexNormalNumber * 3 + i));
		}
	}

	// create actual vertices here (with duplicates)
	// this is in the form that glDrawArrays can work with
	for (std::vector<unsigned int>::iterator it = faceTextureIndices.begin(); it != faceTextureIndices.end(); ++it)
	{
		int vertexNumber = (*it);
		// assume triangles so far
		// assert((faceVertexIndices.size() % 3) == 0);

		// index and copy 2 floats to the m_vertexTexturePairs vector
		for (int i = 0; i < 2; i++)
		{
			modelData.vertexTexturePairs.push_back(vertexTextureCoordinates.at(vertexNumber * 2 + i));
		}
	}

	modelfile.close();
}