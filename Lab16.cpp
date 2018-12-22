#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void get_data(int&, int&);   //Function Prototypes 
void print_data(int, int);
void heading();

int main()
{
	int user_miles;
	int user_hours;
	heading();
	get_data(user_miles, user_hours);
	print_data(user_miles, user_hours);
	system("pause");
	return 0;
}

void get_data(int& user_miles, int& user_hours) { //Obtain data from user

	cout << "Enter the number of miles: ";
	cin >> user_miles;
	cout << "Enter the number of hours: ";
	cin >> user_hours;
}

void print_data(int miles, int hours) {   //Print function
	cout << fixed << showpoint;
	cout << "The number of miles is " << setprecision(2) << miles << endl;
	cout << "The number of hours is " << setprecision(2) << hours << endl;
	cout << "The number of miles per hour is " << setprecision(2) << float(miles)/hours << endl;
}

void heading()  //Header Function for my output
{
	cout << "****************************************************************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "March 29, 2018" << endl;
	cout << "Lab 9" << endl;
	cout << "****************************************************************************************************" << endl;
}
