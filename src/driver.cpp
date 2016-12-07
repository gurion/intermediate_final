#include "../include/plagiarismAlgorithms.hpp"
#include "../include/docList.hpp"
#include "../include/NgramCollection.hpp"

using std::string;
using std::vector;
using std::cout;
using std::cin;

int main(){
	string filestring;
	char choiceChar;
	string output;
	cout << "Welcome to Gurion's Plagiarism Checker.\n\n";
	cout << "Please enter the name of your file (including extension) containing all the files you want to check: \n";
	cin >> filestring;
	cout << "Now please enter the sensitivity you'd like to use - High (h), Medium (m), or low (l): \n";
	cin >> choiceChar;
	choiceChar = tolower(choiceChar);
	while (choiceChar != 'h' && choiceChar != 'm' && choiceChar != 'l'){
		cout << "Invalid option, please enter one of (h, m, or l): ";
		cin >> choiceChar;
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