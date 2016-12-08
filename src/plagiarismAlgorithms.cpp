#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;

//plagiarism algorithm
string algs(string filename, char sense){
	string pairs = "";
	docList docs;
	int numMatches = 0;	
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
	//compare Ngram
	unsigned i = 0;
	for (auto iter1 = colls.begin(); iter1 != colls.end() - 1; iter1++){	 
		for (auto iter2 = iter1++; iter2 != colls.end(); iter2++){
			numMatches = 0;
			unsigned j = i + 1;
			if (j > v.size())
				break;
			int num1 = (*iter1).getNumGrams();
			int num2 = (*iter2).getNumGrams();
			int number = 0;
			if (num1 >= num2){
			  number = num2;
			} else {
			  number = num1;
			}
			auto coll1iter = (*iter1).counts.begin();
			auto coll2iter = (*iter2).counts.begin();
			int val;
			val = compare(coll1iter->first, coll2iter->first);
			int broken = 0;
			while (coll2iter != (*iter2).counts.end() && coll1iter != (*iter1).counts.end()){
				val = compare(coll1iter->first, coll2iter->first);
				if (val == 0){
					numMatches++;
					coll1iter++;
					coll2iter++;
					switch (sense){
						case 'h':
						  	if (numMatches >= number/25){
								pairs += v.at(i) + " " + v.at(j) + "\n";
								broken = 1;
							}
							break;
						case 'm':
						  	if (numMatches >= number/5){
								pairs += v.at(i) + " " + v.at(j) + "\n";
								broken = 1;
							}				
							break;				
						case 'l':
						  	if (numMatches >= number*2/5){
								pairs += v.at(i) + " " + v.at(j) + "\n";
								broken = 1;
							}				
							break;												
					}
				} else if (val < 0){
					coll1iter++;
				} else if (val > 0){
					coll2iter++;
				}
				if (broken == 1){
					break;
				}
			}
			j++;
		}
		i++;
	}
	pairs += "\n\n";
	return pairs;
}

int compare(vector<string> v1, vector<string> v2){
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
