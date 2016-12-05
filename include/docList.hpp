#ifndef DOCUMENT_LIST_HPP
#define DOCUMENT_LIST_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "NgramCollection.hpp"

class docList {

public: 
	docList(){}

	std::vector<std::string> makeList(std::string filename);

	int checkFileList(std::string filename);

	int getNumDocs();

private:
	std::vector<std::string> list;
	int numDocs;
};

#endif