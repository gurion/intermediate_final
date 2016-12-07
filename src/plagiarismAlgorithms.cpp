#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;

//low sensitivity plagiarism check
string lowAlgs(string filename){
	string pairs = "The following pairs are suspicious:\n";
	docList docs;
	int numMatches = 0;
	int numTimes = 0;
	int numPairs = 0;
	NgramCollection coll1(4);
	NgramCollection coll2(4);

	int check = docs.checkFileList(filename);
	if (check == 0)
		return "ERROR - Bad file input.\n";
	vector<string> v = docs.makeList(filename);

	for (auto it = v.begin(); it != v.end(); it++){
		int numWords1 = coll1.getInput(*it);
		cout << "got file " << *it;
		for (auto it2 = it + 1; it2 != v.end(); it2++){
			int numWords2 = coll2.getInput(*it2);
			cout << "got file " << *it;
			//check for repeated file
			if (*it == *it2){
				pairs += *it + " " + *it2 + "\n";
				numPairs++;
			}

			if (numWords1 >= numWords2){
				for (auto coll1Iter = coll1.counts.begin(); coll1Iter != coll1.counts.end(); coll1Iter++){
					int broken = 0;
					for (auto coll2Iter = coll2.counts.begin(); coll2Iter != coll2.counts.end(); coll2Iter++){
						if (coll1Iter->first == coll2Iter->first){
							numMatches++;
							if (numMatches >= coll1.getNumGrams()/5){
								pairs += *it + " " + *it2 + "\n";
								broken = 1;
								break;
							}
						}
						/*
						if (counts.at(coll1Iter)->second.second == coll2Iter->second){
							numTimes += coll1Iter->second;
							if (numTimes >= numWords2/5){
								pairs += *it + " " + *it2 + "\n";
								broken = 1;
								break;
							}
						}
						*/
					}
					if (broken == 1){
						break;
					}
				}
			} else {
				for (auto coll2Iter = coll2.counts.begin(); coll2Iter != coll2.counts.end(); coll2Iter++){
					int broken = 0;
					for (auto coll1Iter = coll1.counts.begin(); coll1Iter != coll1.counts.end(); coll1Iter++){
						if (coll1Iter->first == coll2Iter->first){
							numMatches++;
							if (numMatches >= (coll2.getNumGrams())/5){
								pairs += *it + " " + *it2 + "\n";
								broken = 1;
								break;
							}
						}
					}
					if (broken == 1){
						break;
					}
				}				
			}
		}	
	}	
	
	if (numPairs == 0){
		pairs = "No suspicious pairs found.";
	}
	return pairs;
}

string medAlgs(string filename){
	string pairs = "";
	/*
	NgramCollection coll1(3);
	NgramCollection coll2(3);
	*/
	docList docs;
	int numMatches = 0;
	int numPairs = 0;

	int check = docs.checkFileList(filename);
	if (check == 0)
		return "ERROR - Bad file input.\n";
	vector<string> v = docs.makeList(filename);

	return pairs;
}

string highAlgs(string filename){
	string pairs = "";
	/*
	NgramCollection coll1(3);
	NgramCollection coll2(3);
	*/
	docList docs;
	int numMatches = 0;
	int numPairs = 0;

	int check = docs.checkFileList(filename);
	if (check == 0)
		return "ERROR - Bad file input.\n";
	vector<string> v = docs.makeList(filename);

	return pairs;
}