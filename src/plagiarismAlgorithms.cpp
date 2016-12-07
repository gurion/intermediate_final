#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;

//plagiarism algorithm
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
	int counter = 0;
	for (string s: v){
	  NgramCollection coll(4);
	  colls.push_back(coll);
	  colls.at(counter).getInput(s);
	  counter++;
	}
	/*
	for (unsigned i = 0; i < v.size(); i++){
		cout << i << " " << v.at(i) <<"\n";
		NgramCollection coll(4);
		colls.push_back(coll);
		colls.at(i).getInput(v.at(i));
	}
	*/
	cout <<"out of for";
	/*
	//check for repeated files
	string file1;
	string file2;
	for (auto iter = v.begin(); iter != v.end() - 1; iter++){
		cout << "in for";
		file1 = *iter;
		file2 = *(iter++);
		if (file1 == file2){
			pairs += file1 + " " + file2 + "\n";
			numPairs++;			
		}
	}
	cout << "out of for1";
	*/	
	//compare Ngrams
	cout << colls.size() << "size";
	for (auto iter1 = colls.begin(); iter1 != colls.end() - 1; iter1++){	  
		cout << "making coll1";
		//coll1 = *iter1;
		unsigned i = 0;
		cout << "made coll1";
		for (auto iter2 = iter1++; iter2 != colls.end(); iter2++){
			numMatches = 0;
			//coll2 = *iter2;
			unsigned j = i + 1;
			if (j > v.size())
				break;
			int num1 = (*iter1).getNumWords();
			int num2 = (*iter2).getNumWords();
			auto coll1iter = (*iter1).counts.begin();
			auto coll2iter = (*iter2).counts.begin();
			int val;
			while (coll2iter != (*iter2).counts.end() && coll1iter != (*iter1).counts.end()){
				val = compare(coll1iter->first, coll2iter->first);
				if (val == 0){
					numMatches++;
					coll1iter++;
					coll2iter++;
					switch (sense){
						case 'h':
						  if (numMatches >= (*iter2).getNumGrams()/25){
								pairs += v.at(i) + " " + v.at(j) + "\n";
							}
							break;
						case 'm':
						  if (numMatches >= (*iter2).getNumGrams()/10){
								pairs += v.at(i) + " " + v.at(j) + "\n";
							}				
							break;				
						case 'l':
						  if (numMatches >= (*iter2).getNumGrams()/4){
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
			return -1;
		} else if ((*iter1).compare(*iter2) > 0){
			return 1;
		} else {
			iter1++;
			iter2++;
		}
	}
	return 0;
}








