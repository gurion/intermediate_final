#include "../include/NgramCollection.hpp"

using std::vector;
using std::string;
using std::map;
using std::ifstream;
using std::cout;

//puts file data into an Ngram Collection
int NgramCollection::getInput(string filename){
    //initialize variables, check data
    ifstream in(filename);
    string str;
    vector<string> words;
    while (in >> str){
    	words.push_back(str);
 		numWords++;
    }
    in.close();
    if (words.size() == 0){
    	cout << "ERROR - File empty.";
    	return 0;
    }
    vector<string>::const_iterator begin = words.begin();
    vector<string>::const_iterator end = begin + n;

    //put data into collection
    while (end <= words.end()){
    	increment(begin, end);
    	begin++;
    	end++;
    }
    return 1;
}

//creates N-grams, adds to map
void NgramCollection::increment(vector<string>::const_iterator begin, vector<string>::const_iterator end){
	vector<string> outerKey;
	vector<string>::const_iterator it;
	//push into vector
	for (it = begin; it != end-1; it++){
		outerKey.push_back(*it);
	}
	counts[outerKey][*it]++;	
}










