#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;

//low sensitivity plagiarism check
string lowAlgs(string filename){
	string pairs = "";
	int check = checkFileList(filename);
	if (check == 0)
		return 0;
	vector<string> v = makeList(filename);
	NgramCollection coll1(3);
	NgramCollection coll2(3);

	for (unsigned i = 0; i != v.size(); i++){
		coll1.getInput(v.at(i));
		for (unsigned j = i + 1; j != v.size(); j++){
			coll2.getInput(v.at(j));
			if (v.at(i) == v.at(j))
				pairs += v.at(i) + " " + v.at(j) + "\n";

		}
	}
}