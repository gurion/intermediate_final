#include "../include/NgramCollection.hpp"
#include <cassert>

using std::vector;
using std::string;
using std::map;
using std::ifstream;
using std::cout;

//puts file data into an Ngram Collection
int NgramCollection::getInput(string filename){
    //initialize variables, check data
    ifstream in(filename);
    string str = "";
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
        numGrams++;
    }
    return numWords;
}

//creates N-grams, adds to map
void NgramCollection::increment(vector<string>::const_iterator begin, vector<string>::const_iterator end){
  assert(end - begin == n); //make sure we've got the right number of words
  vector<string> outerKey;
  vector<string>::const_iterator it;
  //push into vector
  for (it = begin; it != end-1; it++){
    outerKey.push_back(*it);
  }
  counts[outerKey][*it]++;
}

string NgramCollection::toString() const{
  string str = "";
  for (auto iterOuter = counts.begin(); iterOuter != counts.end(); iterOuter++){
    map<string, unsigned> tempM = iterOuter->second;
    for (auto iterInner = tempM.begin(); iterInner != tempM.end(); iterInner++){
      vector<string> tempV = iterOuter->first;
      for (auto it = tempV.begin(); it != tempV.end(); it++){
    str += *it + " ";
      }
      str += iterInner->first + " " + std::to_string(iterInner->second) + "\n";
    }
  }
  return str;
}
