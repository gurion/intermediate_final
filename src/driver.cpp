#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::string;
using std::vector;
using std::cout;
using std::cin;

int main(int argc, char* argv[]){
	string filestring;
	char choiceChar;
	string output;
	cout << "Welcome to Gurion's Plagiarism Checker.\n\n";
	cout << "Please enter the name of your file (including extension) containing all the files you want to check: \n";
	cout << "Now please enter the sensitivity you'd like to use - High (h), Medium (m), or low (l): \n";
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
			cout << "Invalid sensitivity, program terminated. Goodbye!";
		}
	}
	if (choiceChar == 'h')
		output = highAlgs(filestring);
		
	if (choiceChar == 'm')
		output = medAlgs(filestring);

	if (choiceChar == 'l')
		output = lowAlgs(filestring);
	
	if (output != "ERROR - Bad file input.")
		cout << "The following pairs of files have been marked as suspiciously similar: \n\n";
	cout << output;

	return 0;
}