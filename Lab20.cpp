#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int numbers[10];
	int maximum = 0;
	int minimum = 99999999;
	for (int i = 0; i < 10; i++) {
		cout << "Enter an integer: ";
		cin >> numbers[i];
		if (numbers[i] > maximum) {  //Obtain maximum
			maximum = numbers[i];
		}
	}
	for (int i = 0; i < 10; i++) {   //Obtain minimum
		if (numbers[i] < minimum) {
			minimum = numbers[i];
		}
	}

	cout << "The numbers you entered are: " << endl;
	for (int i = 0; i < 10; i++) {    //Print numbers
		cout << numbers[i] << " ";
	}
	cout << endl;
	cout << "The maximum is " << maximum << endl;
	cout << "The minimum is " << minimum << endl;
	system("pause");
	return 0;
}
