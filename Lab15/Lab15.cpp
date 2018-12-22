#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void switch_name(string&);

int main()
{
	ifstream myfile;
	cout << fixed << showpoint;
	myfile.open("infile.txt");      //Open File
	string full_name;                //Variable Declarations
	float gpa;
	char whitespace;
	string switched_name;

	getline(myfile, full_name); //Priming Read
	myfile >> gpa;

	while (myfile) {
		switch_name(full_name);
		cout << full_name << " " << setprecision(1) << gpa << endl;
		myfile.get(whitespace);
		getline(myfile, full_name);    //Get next (Incremental Read)
		myfile >> gpa;
	}
	system("pause");
	return 0;
}

void switch_name(string& name) {   //Function to switch names 
	int comma_pos = name.find(',');
	string last_name = name.substr(0, comma_pos);
	string first_name = name.substr(comma_pos + 2, name.length() - comma_pos + 1);
	name = first_name + " " + last_name;
}
