#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;

//low sensitivity plagiarism check
string algs(string filename, char sense){
	string pairs = "The following pairs are suspicious:\n";
	docList docs;
	int numMatches = 0;	
	int numPairs = 0;
	NgramCollection coll1(4);
	NgramCollection coll2(4);

	//check files
	int check = docs.checkFileList(filename);
	if (check == 0)
		return "ERROR - Bad file input.\n";
	vector<string> v = docs.makeList(filename);
	vector<NgramCollection> colls;
	
	//fill vector of Ngrams input
	for (unsigned i = 0; i != v.size(); i++){
		NgramCollection coll(4);
		colls.push_back(coll);
		colls.at(i).getInput(v.at(i));
	}

	//check for repeated files
	cout << "seg fault 1\n";
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

	//compare Ngrams
	for (auto iter1 = colls.begin(); iter1 != colls.end(); iter1++){
		coll1 = *iter1;
		cout << "seg fault 2\n";
		unsigned i = 0;
		for (auto iter2 = iter1++; iter2 != colls.end(); iter2++){
			numMatches = 0;
			coll2 = *iter2;
			cout << "seg fault 3\n";
			unsigned j = i + 1;
			if (j > v.size())
				break;
			int num1 = coll1.getNumWords();
			int num2 = coll2.getNumWords();
			auto coll1iter = coll1.counts.begin();
			auto coll2iter = coll2.counts.begin();
			int val;
			while (coll2iter != coll2.counts.end() && coll1iter != coll1.counts.end()){
				val = compare(coll1iter->first, coll2iter->first);
				if (val == 0){
					numMatches++;
					coll1iter++;
					coll2iter++;
					switch (sense){
						case 'h':
							if (numMatches >= coll2.getNumGrams()/25){
								pairs += v.at(i) + " " + v.at(j) + "\n";
							}
							break;
						case 'm':
							if (numMatches >= coll2.getNumGrams()/10){
								pairs += v.at(i) + " " + v.at(j) + "\n";
							}				
							break;				
						case 'l':
							if (numMatches >= coll2.getNumGrams()/4){
								pairs += v.at(i) + " " + v.at(j) + "\n";
							}				
							break;												
					}
				} else if (val < 0){
					coll1iter++;
				} else if (val > 0){
					coll2iter++;
				}
			}
		}
	}
	return pairs;
}

int compare(vector<string> v1, vector<string> v2){
	int value;
	auto iter1 = v1.begin();
	auto iter2 = v2.begin();
	while (iter1 != v1.end() && iter2 != v2.end()){
		if ((*iter1).compare(*iter2) < 0){
			value = -1;
		} else if ((*iter1).compare(*iter2) > 0){
			value = 1;
		} else {
			iter1++;
			iter2++;
		}
	}
	value = 0;
	return value;
}








