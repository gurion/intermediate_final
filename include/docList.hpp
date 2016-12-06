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

	//std::vector<NgramCollection> makeDocs(std::vector<std::string> *filelist); 

	int checkFileList(std::string filename);

	int getNumDocs() { return numDocs; };

private:
	std::vector<std::string> list;
	std::map<std::string, NgramCollection> documents;
	int numDocs;
};

#endif