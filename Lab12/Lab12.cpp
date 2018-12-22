#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void lookup_name(ifstream&, string&, string&);      //Function Prototypes

int main() {
	ifstream myfile;                   //Variable Declarations
	string first_name;
	string last_name;
	string phone_number;
	char user_response;
	//user_response = 'Y';
	/*while (user_response == 'Y') {*/
		cout << "Enter last name: ";
		cin >> last_name;
		lookup_name(myfile, last_name, phone_number);
		if (phone_number != "") {
			cout << "The corresponding phone number is: " << phone_number << endl << endl;
		}
		else {
			cout << "The telephone number does not exist!" << endl << endl;
		}
		/*cout << "Do you want to look up another name in the directory (Y/N): ";
		cin >> user_response;
		if (user_response == 'N') {
			cout << "Goodbye." << endl;*/
	/*	}*/

	//}
	system("pause");
	return 0;      //Return 0 if all runs as expected
}

void lookup_name(ifstream& myfile, string& last_name, string& phone_number) {      //Function to obtain phone number
	myfile.open("infile.txt");
	string f_name;
	string l_name;
	string ph_num;
	myfile >> f_name >> l_name >> ph_num; //Priming Read
	while (myfile) {
		if (l_name == last_name) {
			phone_number = ph_num;
			break;
		}
		myfile >> f_name >> l_name >> ph_num;
	}
	myfile.close();
	return;
}
