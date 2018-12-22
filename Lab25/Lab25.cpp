#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Address_type
{
	int street_no;
	string street_name;
	string city;
	string state;
	int zip;
};

struct student_type
{
	string lname;
	string fname;
	int ID;
	float GPA;
	char classification;
	float account_balance;
	Address_type student_address;
};

void print_students(student_type[]);
void store_data(student_type[], ifstream&);
void heading();

int main() {
	heading();
	student_type student_array[5];
	ifstream myfile;
	myfile.open("infile.txt");

	store_data(student_array, myfile);
	print_students(student_array);

	system("pause");
	return 0;
}

void store_data(student_type student_array[], ifstream& myfile) {
	Address_type address;
	student_type student;
	char whitespace;
	for (int i = 0; i < 5; i++) {
		myfile >> student_array[i].lname >> student_array[i].fname >> student_array[i].ID >> student_array[i].GPA >> student_array[i].classification
			   >> student_array[i].account_balance >> student_array[i].student_address.street_no;
		myfile.get(whitespace);
		getline(myfile, student_array[i].student_address.street_name);
		myfile >> student_array[i].student_address.city >> student_array[i].student_address.state >> student_array[i].student_address.zip;

	}
}

void print_students(student_type student_array[]) {
	cout << endl;

	string classification;

	for (int i = 0; i < 5; i++) {
		switch (student_array[i].classification) {
		case 'F':
			classification = "Freshman";
			break;
		case 'S':
			classification = "Sophomore";
			break;
		case 'J':
			classification = "Junior";
			break;
		case 'N':
			classification = "Senior";
			break;
		default:
			break;
		}

		 cout << setw(10) << left << student_array[i].lname << " " << student_array[i].fname << "        "
			  << setw(10) << left << student_array[i].ID << setw(10) << left << student_array[i].GPA
			  << setw(10) << classification << "   " << setw(10) << student_array[i].account_balance << setw(10) << student_array[i].student_address.street_no
			  << " " << student_array[i].student_address.street_name << " " << student_array[i].student_address.city 
			  << " " << student_array[i].student_address.state << " " << student_array[i].student_address.zip << endl;
	}
}

void heading() {    //Header Function for my output
	cout << "****************************************************************************************************************" << endl;
	cout << "Chijioke E. Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "April 20, 2018" << endl;
	cout << "Class Exercise 12" << endl;
	cout << "****************************************************************************************************************" << endl << endl;
}
