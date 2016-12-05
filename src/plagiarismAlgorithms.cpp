#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;

//low sensitivity plagiarism check
string lowAlgs(string filename){
	string pairs = "";
	NgramCollection coll1(3);
	NgramCollection coll2(3);
	docList docs;
	int check = docs.checkFileList(filename);
	if (check == 0)
		return "";
	vector<string> v = docs.makeList(filename);

	for (unsigned i = 0; i != v.size(); i++){
		coll1.getInput(v.at(i));
		for (unsigned j = i + 1; j != v.size(); j++){
			coll2.getInput(v.at(j));
			if (v.at(i) == v.at(j)){
				pairs += v.at(i) + " " + v.at(j) + "\n";
			}
			int num1 = coll1.getNumWords;
			int num2 = coll2.getNumWords;
			for (auto it = coll1.counts.begin())

		}
	}
	return pairs;
}