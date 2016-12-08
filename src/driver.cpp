#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

#include <ctime>

using std::string;
using std::vector;
using std::cout;
using std::cin;

int main(int argc, char* argv[]){
	int start_s = clock();
	string filestring;
	char choiceChar;
	string output;
	cout << "\nWelcome to Gurion's Plagiarism Checker.\n\n";
	if (argc > 3 || argc <= 1){
		cout << "ERROR - Invalid arguments.\n Goodbye!\n\n";
		return 0;
	}
	if (argc == 2){
		filestring = argv[1];
		choiceChar = 'm';
	}
	if (argc == 3){
		filestring = argv[1];
		choiceChar = argv[2][0];
		choiceChar = tolower(choiceChar);
		if (choiceChar != 'h' && choiceChar != 'm' && choiceChar != 'l'){
			cout << "Invalid sensitivity parameter, program terminated. Goodbye!";
		}
	}

	output = algs(filestring, choiceChar);
	docList docs;
	vector<string> v  = docs.makeList(filestring);
	unsigned numDoc = v.size();
	
	if (output != "ERROR - Bad file input.")
		cout << "You input a list of " << numDoc << " files.\n";  
		cout << "The following pairs of files have been marked as suspiciously similar: \n\n";
	
	cout << output;
	
	int stop_s = clock();
	cout << "It took the program " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << " seconds to run.\n\n";
	cout << "Goodbye, have a beautiful time!";
	return 0;
}
