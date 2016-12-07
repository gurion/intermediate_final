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
	NgramCollection coll1(3);
	NgramCollection coll2(3);

	int check = docs.checkFileList(filename);
	if (check == 0)
		return "ERROR - Bad file input.\n";
	vector<string> v = docs.makeList(filename);
	vector<NgramCollection> colls;
	
	//get input
	NgramCollection coll(3);
	for (unsigned i = 0; i != v.size(); i++){
		colls.push_back(coll);
		colls.at(i).getInput(v.at(i));
	}

	//check for repeated files
	string file1;
	string file2;
	for (auto iter = v.begin(); iter != v.end(); iter++){
		file1 = *iter;
		file2 = *(iter++);
		if (file1 == file2){
			pairs += file1 + " " + file2 + "\n";
			numPairs++;			
		}
	}

	for (auto iter1 = colls.begin(); iter1 != colls.end(); iter1++){
		coll1 = *iter1;
		unsigned i = 0;
		for (auto iter2 = iter1++; iter2 != colls.end(); iter2++){
			coll2 = *iter2;
			unsigned j = i + 1;
			if (j > v.size())
				break;
			int num1 = coll1.getNumWords();
			int num2 = coll2.getNumWords();
			if (num1 >= num2){
				for (auto coll1Iter = coll1.counts.begin(); coll1Iter != coll1.counts.end(); coll1Iter++){
					int broken = 0;
					for (auto coll2Iter = coll2.counts.begin(); coll2Iter != coll2.counts.end(); coll2Iter++){
						if (coll1Iter->first == coll2Iter->first){
							numMatches++;
							if (numMatches >= coll2.getNumGrams()/5){
								pairs += v.at(i) + " " + v.at(j) + "\n";
								broken = 1;
								break;
							}
						}
					}
					if (broken == 1)
						break;
				}
			} else {
				for (auto coll2Iter = coll2.counts.begin(); coll2Iter != coll2.counts.end(); coll2Iter++){
					int broken = 0;
					for (auto coll1Iter = coll1.counts.begin(); coll1Iter != coll1.counts.end(); coll1Iter++){
						if (coll1Iter->first == coll2Iter->first){
							numMatches++;
							if (numMatches >= coll1.getNumGrams()/5){
								pairs += v.at(i) + " " + v.at(j) + "\n";
								broken = 1;
								break;
							}
						}
					}
					if (broken == 1)
						break;
				}
			}
			j++;
		}
		i++;
	}
/*
	for (auto it = v.begin(); it != v.end(); it++){
		int numWords1 = coll1.getInput(*it);
		cout << "got file 1" << *it << " ";
		for (auto it2 = it + 1; it2 != v.end(); it2++){
			int numWords2 = coll2.getInput(*it2);
			cout << "got file 2" << *it << "\n";			
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
/*					}
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
	*/
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