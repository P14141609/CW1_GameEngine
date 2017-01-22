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
	/// \brief Loads a .obj and returns the data
	///
	/// \param ksObjectFile The file path to an object file
	///
	///////////////////////////////////////////////// 
	static ModelData loadObj(const std::string ksObjectFile);
};

#endif