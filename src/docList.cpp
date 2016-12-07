#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::map;
using std::ifstream;
using std::cout;

//checks that all files open - original and each file specified
int docList::checkFileList(string filename){
	ifstream in(filename);
	if (!in.is_open()){
		return 0;
	}
	string file;
	while (in >> file){
		ifstream check(file);
		if (!check.is_open()){
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
		list = {""};
		return list;
	}
}

/*
vector<NgramCollection> docList::makeDocs(docList files){
	vector<NgramCollection> docs;
	for (int i = 1; i < files.getNumDocs()){
		string str = "coll" + to_string(i);
		new NgramCollection str(3);

	}
	for (auto iter = filelist.begin(); iter != filelist.end(); iter++){
		
	}
	return docs;
}
*/
