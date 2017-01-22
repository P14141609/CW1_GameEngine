#ifndef XMLLOADER_H
#define XMLLOADER_H

// Imports
#include "player.h"
#include "camera.h"
#include "gameobject.h"
#include "collectable.h"
#include "staticobject.h"
#include "light.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

struct XmlData //!< Holds xml data
{
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Camera>> cameras;
	std::vector<std::shared_ptr<GameObject>> gameobjects;
	std::vector<std::shared_ptr<Light>> lights;
};

/////////////////////////////////////////////////
///
/// \brief Class for .xml file loading
/// 
/////////////////////////////////////////////////
class XMLLoader
{
public:

	/////////////////////////////////////////////////
	///
	/// \brief Loads a .xml file and binds the data to the referenced input variable
	///
	/// \param ksXmlFile The file path to an xml file
	/// \param xmlData An XmlData object pointer
	///
	///////////////////////////////////////////////// 
	static void loadXml(const std::string ksXmlFile, XmlData &xmlData);
};

#endif