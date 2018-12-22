#include <iostream>
using namespace std;

int main()
{
	int user_input = 0;


	while (true) {              //while loop with condition
		cout << "Enter a number from 0 to 9: ";  //Prompt user for input
		cin >> user_input;

		while (cin.fail()) {                //Keep prompting for input until integer is given
			cout << "Invalid data type." << endl << "Enter a number from 0 to 9: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> user_input;
		}

		switch (user_input) {             //switch statement with user input as parameter
		case 0:
			cout << "Zero." << endl;
			continue;
		case 1:
			cout << "One." << endl;
			continue;
		case 2:
			cout << "Two." << endl;
			continue;
		case 3:
			cout << "Three." << endl;
			continue;
		case 4:
			cout << "Four." << endl;
			continue;
		case 5:
			cout << "Five." << endl;
			continue;
		case 6:
			cout << "Six." << endl;
			continue;
		case 7:
			cout << "Seven." << endl;
			continue;
		case 8:
			cout << "Eight." << endl;
			continue;
		case 9:
			cout << "Nine." << endl;
			continue;
		default:
			cout << "The input is out of range." << endl;
			break;
		}
		if (user_input > 9) {
			break;
		}
	}
	system("pause");
	return 0;
}
