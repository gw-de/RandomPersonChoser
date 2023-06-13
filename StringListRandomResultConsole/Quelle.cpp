#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//function prototypes
void NewEntry();
void GenerateName(int random);

using namespace std;

int main(){
	//define variables
	unsigned short menu = 0;
	unsigned int random = 0;

	//generate random seed
	srand((int)time(0));

	//while loop until exit
	do {
		//display menu
		cout << "For New Entry press 0\n";
		cout << "To generate a name press 1\n";
		cout << "For exit press 2\n\n";

		//input of menu
		cin >> menu;

		//check for valid input
		if (cin.fail()){
			//clear error storage
			cin.clear();

			//clear input buffer
			cin.ignore(numeric_limits<streamsize>::max());

			cout << "\ninvalid input\n\n";
		}
		else{
			//conditions for menu
			//bugs for chars, but doesn't matter after portation into Windows
			switch (menu){
			case (0) : {	//new entry
						   NewEntry();
			} break;
			case (1) : {	//generate name
						   GenerateName(random);
			} break;
			case (2) : {	//exit
						   cout << "\nExit!\n\n";
			} break;
			default:{		//invalid input
							cout << "\nInvalid input!\n\n";
			} break;
			}
		}
	} while (menu != 2);

	return 0;
}



//new entry function
void NewEntry(){
	//define variable
	string WriteName;

	cout << "Write the name:";

	//clear input buffer
	cin.ignore();

	//get whole line
	getline(cin, WriteName);

	//declare instance of file class
	ofstream List1;

	//access file if possible
	if (List1.is_open() == true){
		cout << "\n\nFile could not be accessed!\n\n";
	}
	else{
		List1.open("List.txt", ios::app);

		//write line into file
		List1 << WriteName << endl;

		//close the file
		List1.close();
	}

	//feedback
	cout << "\nDone\n\n";
}



//generate name
void GenerateName(int random){
	//define variables
	string ReadName;
	bool FirstTime = 1;

	//define vector of strings
	vector<string> names;

	//create instance of file stream
	ifstream List;

	//access file if possible
	if (List.is_open() == true){
		cout << "\n\nFile could not be accessed!\n\n";
	}
	else
	{
		List.open("List.txt");

		//while loop line by line til end of file
		while (getline(List, ReadName)){
			//get line and save in string Name
			names.push_back(ReadName);
		}

		//close file
		List.close();
	}

	//check if list contains any lines
	if (names.size() == 0){
		cout << "\nList doesn't contain any names.\n\n";
	}
	else{
		//first random
		random = (int)(((((double)rand()) / RAND_MAX) * names.size()));

		//second random for real random number
		random = (int)(((((double)rand()) / RAND_MAX) * names.size()));

		//print the random name
		cout << endl << endl << names[random] << endl << endl;
		
	}

	//clear list
	names.clear();
}