#include "../include/docList.hpp"

using std::vector;
using std::string;
using std::ifstream;
using std::cout;

//checks that all files open - original and each file specified
int docList::checkFileList(string filename){
	ifstream in(filename);
	if (!in.is_open()){
		cout << "ERROR - Bad file.\n\n";
		return 0;
	}
	string file;
	while (in >> file){
		ifstream check(file);
		if (!check.is_open()){
			cout << "Error - Bad file in list.\n\n";
			return 0;
		}
		check.close();
	}
	in.close();
	return 1;
}

//creates a vector of all file names
vector<string> docList::makeList(string filename){
	int check = checkFileList(filename);
	vector<string> list;
	string str = "";
	if (check == 1){
		ifstream in(filename);
		while (in >> str){
			list.push_back(str);
			numDocs++;
		}

		in.close();
		return list;
	} else {
		cout << "ERROR - Bad file.";
		list = {""};
		return list;
	}
}

//returns number of docs in the vector
int docList::getNumDocs(){
	return numDocs;
}