#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

//function prototypes
void GenerateName(int random, int i);

using namespace std;

int main(){
	//define variables
	unsigned int random = 0;

	//generate random seed
	srand((int)time(0));

	for (int i = 0; i < 25; i++){
		GenerateName(random, i);
	}

	return 0;
}


//generate name
void GenerateName(int random, int i){
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