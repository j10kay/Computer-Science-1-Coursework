#include <iostream>     
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
void heading();         //Function Prototypes
float compute_interest(float, float, char);
void print_report(float, int, char);
float compute_service_charge(float, float, char);

int main() {

	heading();
	ifstream myfile; 
	int account_number;
	char account_type;
	float minimum_balance;
	float current_balance;
	int num_customers = 1;
	myfile.open("infile.txt");   //Open File
	float total_interest, total_service_charge, updated_balance;

	while (num_customers <= 5) {     //Counter-Controlled Loop (5 iterations for 5 customer accounts)
		myfile >> account_number >> account_type >> minimum_balance >> current_balance;   //Take readings from file
		total_interest = compute_interest(minimum_balance, current_balance, account_type);
		total_service_charge = compute_service_charge(minimum_balance, current_balance, account_type);
		updated_balance = (current_balance + total_interest - total_service_charge);     //New balance after service charge deductions and added interest
		print_report(updated_balance, account_number, account_type);
		num_customers++;       //Increment Loop Counter
	}
	myfile.close();    //Close File
	system("pause");
	return 0;
}

void heading() {                       //Header Function for my output
	cout << "******************************************************************" << endl;
	cout << "Chijioke Enyinnaya Kamanu" << endl;
	cout << "Student ID: @02840667" << endl;
	cout << "CS 1 Midterm, Spring 2018" << endl;
	cout << "March 1, 2018" << endl;
	cout << "******************************************************************" << endl;
	return;
}

float compute_interest(float minimum_balance, float current_balance, char acct_type) {      // Function to compute interest 
	                                                                                        // based on account type and current balance
	float interest = 0;
	if (current_balance >= minimum_balance) {
		if (acct_type == 'S') {
			interest = (0.04 * current_balance);
		}
		else if (acct_type == 'C') {
			if (current_balance - minimum_balance <= 5000) {
				interest = (0.05 * current_balance);
			}
			else {
				interest = (0.03 * current_balance);
			}
		}
	}
	return interest;
}

void print_report(float current_balance, int acct_number, char acct_type) {              //Function to print output containing required information

	cout << fixed << showpoint;
	cout << "******************************************************************" << endl;
	cout << "Account Number: " << acct_number << endl;
	if (acct_type == 'S') {
		cout << "Account Type: Savings" << endl;
	}
	else {
		cout << "Account Type: Checking " << endl;
	}
	cout << "Account Balance: " << setprecision(2) << current_balance << endl << endl;
	return;
}

float compute_service_charge(float minimum_balance, float current_balance, char acct_type) {     //Function to determine service charge based on account type
	float service_charge = 0;
	if (current_balance < minimum_balance) {
		if (acct_type == 'C') {
			service_charge = 25.00;
		}
		else {
			service_charge = 10.00;
		}
	}
	return service_charge;
}
