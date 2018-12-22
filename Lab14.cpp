#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	float* floatPtr;
	int* intPtr;  //Integer Pointer
	string* stringPtr;
	floatPtr = new float;
	stringPtr = new string;
	intPtr = new int;  //intPtr points to a new integer
	*floatPtr = 2.5;
	*intPtr = 7;  //The asterisk is a dereferencing operator 
	*stringPtr = "Kamanu ";
	cout << *intPtr + *intPtr << endl;
	cout << setprecision(2) << *floatPtr * *floatPtr << endl;
	cout << *stringPtr + *stringPtr << endl;
	system("pause");
	return 0;
}
