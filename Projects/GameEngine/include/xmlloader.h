#ifndef XMLLOADER_H
#define XMLLOADER_H

// Imports
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

struct XmlData
{
	// TODO
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