#ifndef MODELLOADER_H
#define MODELLOADER_H

// Imports
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

struct ModelData //!< Holds vertex/normal/texture data for rendering a model
{
	std::vector<float> vertexTriplets;
	std::vector<float> vertexNormalTriplets;
	std::vector<float> vertexTexturePairs;
};

/////////////////////////////////////////////////
///
/// \brief Class for .obj file loading
/// 
/////////////////////////////////////////////////
class ModelLoader
{
public:

	/////////////////////////////////////////////////
	///
	/// \brief Loads a .obj and binds the data to the referenced input variable
	///
	/// \param ksObjectFile The file path to an object file
	/// \param modelData A modelData object pointer
	///
	///////////////////////////////////////////////// 
	static void loadObj(const std::string ksObjectFile, ModelData &modelData);
};

#endif