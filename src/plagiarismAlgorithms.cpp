#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;

//low sensitivity plagiarism check
string lowAlgs(string filename){
	string pairs = "";
	/*
	NgramCollection coll1(3);
	NgramCollection coll2(3);
	*/
	docList docs;
	int numMatches = 0;
	int numTimes = 0;
	int numPairs = 0;

	int check = docs.checkFileList(filename);
	if (check == 0)
		return "ERROR - Bad file input.";
	vector<string> v = docs.makeList(filename);

	for (auto it = v.begin(); it != v.end(); it++){
		ifstream f1(*it);
		vector<string> file1;
		string file1str;
		int num1 = 0;
		while (f1 >> file1str){
			file1.push_back(file1str);
			num1++;
		}
		for (auto it2 = it + 1; it2 != v.end(); it2++){
			ifstream f2(*it2);
			vector<string> file2;
			string file2str;
			int num2 = 0;
			while (f2 >> file2str){
				file2.push_back(file2str);
				num2++;
			}
			//repeated file
			if (*it == *it2){
				pairs += *it + " " + *it2 + "\n";
				numPairs++;
			}

			//repeated words
			
		}	
	}	
	
	if (numPairs == 0){
		pairs = "No suspicious pairs found.";
	}
	return pairs;
}

string medAlgs(string filename){
	string output = "";
	return output;
}

string highAlgs(string filename){
	string output = "";
	return output;
}