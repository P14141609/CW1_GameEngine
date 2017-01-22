#ifndef MODELLOADER_H
#define MODELLOADER_H

// Imports
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

struct ModelData 
{
	std::vector<float> vertexTriplets;
	std::vector<float> vertexNormalTriplets;
	std::vector<float> vertexTexturePairs;
};

/////////////////////////////////////////////////
///
/// \brief Class for Model file loading
/// 
/////////////////////////////////////////////////
class ModelLoader
{
private:

protected:

public:

	/////////////////////////////////////////////////
	///
	/// \brief Loads a .obj and binds the data to the input variable
	///
	/// \param ksObjectFile The file path to an object file
	/// \param modelData A modelData object pointer
	///
	///////////////////////////////////////////////// 
	static void loadObj(const std::string ksObjectFile, ModelData &modelData);
};

#endif