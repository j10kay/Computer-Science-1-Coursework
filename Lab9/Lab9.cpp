#include <iostream> 
#include <fstream> 
#include <string>
#include <iomanip>

using namespace std;
void heading();
int get_year();
int get_starting_day();
void print_heading(int);               //Function prototypes
string read_month_name();
int read_num_days();
int print_month(int, int, string);
ifstream myfile;

int main()
{
	heading();
	myfile.open("infile.txt");
	int first_day;
	int year = get_year();
	first_day = get_starting_day();
	print_heading(year);
	int num_of_months;
	for (num_of_months = 0; num_of_months < 12; num_of_months++) {                //Counter-controlled for loop
		string month = read_month_name();
		int num_days = read_num_days();
		first_day = print_month(first_day, num_days, month);
	}
	system("pause");
	return 0;                //Return 0 if all executes as planned
}

void heading() {                       //Header Function for my output
	cout << "******************************************************************" << endl;
	cout << "Chijioke Enyinnaya Kamanu" << endl;
	cout << "Student ID: @02840667" << endl;
	cout << "Program to display calendar" << endl;
	cout << "March 8, 2018" << endl;
	cout << "******************************************************************" << endl;
	return;
}

int get_year() {           //Read year from keybpard
	int year;
	cout << "Enter a year: ";
	cin >> year;
	return year;
}

int get_starting_day() {                //Read starting day from keyboard
	int start_date;
	cout << "Enter the day of the week for the first day of the "
		<< "year(0 = Sunday, 1 = Monday, 2 = Tuesday, "
		<< "3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday): ";
	cin >> start_date;
	return start_date;
}

void print_heading(int year) {           //Print year heading
	cout << endl;
	cout << "                        " << "YEAR -- " << year << endl;
	return;
}

string read_month_name() {             //Read month from file
	string month;
	myfile >> month;
	return month;
}

int read_num_days() {                 //Read number of days from file
	int num_days;
	myfile >> num_days;
	return num_days;
}

int print_month(int first_day, int no_of_days, string month_name) {   //Print month function
	int last_day;
	cout << endl;
	cout << setw(30) << month_name << endl << endl;
	cout << setw(54) << "Sun  : Mon  : Tue  : Wed  : Thu  : Fri  : Sat  :" << endl << endl;

	for (int space = 0; space < first_day; space++) {     //Print adequate number of spaces
		cout << "       " ;
	}

	for (int day = 1; day <= no_of_days; day++) {         //Enter new line after 7 days
		cout << setw(7) << day;
		if ((first_day + day) % 7 == 0){
		cout << endl << endl;
		}
	}
	cout << endl;
	last_day = ((no_of_days + first_day) % 7);
	cout << endl << endl;
	return last_day;
}
