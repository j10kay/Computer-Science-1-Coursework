#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int number_of_tabs = 3;

int main() {
	int row;
	int column;
	for (row = 0; row < 4; row++) {   //Outer Loop
		for (int i = 0; i < number_of_tabs; i++) {
			cout << '\t';
		}
		number_of_tabs--;
		for (column = 0; column < 1 + row; column++) {    //Inner Loop
			cout << "*" << '\t';
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
