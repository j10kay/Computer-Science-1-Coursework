#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void heading();
float compute_gross_pay(int, float, char); //function prototypes
float compute_taxes(float);
float compute_net_pay(float, float);
void print_pay_check(string, string, int, string, string, string, string, int, float, float, float);
float compute_federal_tax(float);
float compute_state_tax(float);
float compute_city_tax(float);

int main()
{
	heading();                 //header function
	char parttime_fulltime;        // variable declarations
	float payRate;
	float grossPay;
	float netPay;
	float totalTax;
    string last_name, first_name, street_address, street_name, street_type, city, state, date;
	int zip, deductions, address_num, employee_id;
	const string DATE = "02/15/2018";
	ifstream myfile;

	myfile.open("infile.txt"); // Open infile;

	myfile >> last_name >> first_name >> deductions >> employee_id >> address_num 
		   >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime;   // Obtain employee information from file
	float employee_gross_pay = compute_gross_pay(deductions, payRate, parttime_fulltime);
	float employee_taxes = compute_taxes(employee_gross_pay);
	float employee_net_pay = compute_net_pay(employee_gross_pay, employee_taxes);
	print_pay_check(last_name, first_name, address_num, street_name, DATE, city, state, zip, employee_gross_pay, employee_net_pay, employee_taxes);

	myfile >> last_name >> first_name >> deductions >> employee_id >> address_num 
		   >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // Obtain second row of information
	employee_gross_pay = compute_gross_pay(deductions, payRate, parttime_fulltime);
	employee_taxes = compute_taxes(employee_gross_pay);
	employee_net_pay = compute_net_pay(employee_gross_pay, employee_taxes);
	print_pay_check(last_name, first_name, address_num, street_name, DATE, city, state, zip, employee_gross_pay, employee_net_pay, employee_taxes);

	myfile >> last_name >> first_name >> deductions >> employee_id >> address_num 
		   >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // Obtain third row of information
	employee_gross_pay = compute_gross_pay(deductions, payRate, parttime_fulltime);
	employee_taxes = compute_taxes(employee_gross_pay);
	employee_net_pay = compute_net_pay(employee_gross_pay, employee_taxes);
	print_pay_check(last_name, first_name, address_num, street_name, DATE, city, state, zip, employee_gross_pay, employee_net_pay, employee_taxes);

	myfile >> last_name >> first_name >> deductions >> employee_id >> address_num 
		   >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // Obtain fourth row of information
	employee_gross_pay = compute_gross_pay(deductions, payRate, parttime_fulltime);
	employee_taxes = compute_taxes(employee_gross_pay);
	employee_net_pay = compute_net_pay(employee_gross_pay, employee_taxes);
	print_pay_check(last_name, first_name, address_num, street_name, DATE, city, state, zip, employee_gross_pay, employee_net_pay, employee_taxes);

	myfile >> last_name >> first_name >> deductions >> employee_id >> address_num 
		   >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // Obtain fifth row of information
	employee_gross_pay = compute_gross_pay(deductions, payRate, parttime_fulltime);
	employee_taxes = compute_taxes(employee_gross_pay);
	employee_net_pay = compute_net_pay(employee_gross_pay, employee_taxes);
	print_pay_check(last_name, first_name, address_num, street_name, DATE, city, state, zip, employee_gross_pay, employee_net_pay, employee_taxes);

	myfile >> last_name >> first_name >> deductions >> employee_id >> address_num 
		   >> street_name >> street_type >> city >> state >> zip >> payRate >> parttime_fulltime; // Obtain sixth row of information
	employee_gross_pay = compute_gross_pay(deductions, payRate, parttime_fulltime);
	employee_taxes = compute_taxes(employee_gross_pay);
	employee_net_pay = compute_net_pay(employee_gross_pay, employee_taxes);
	print_pay_check(last_name, first_name, address_num, street_name, DATE, city, state, zip, employee_gross_pay, employee_net_pay, employee_taxes);

	myfile.close();             // Close the file
	system("pause");
	return 0;                  // Return 0 if program runs as expected
}

void heading()
{
	cout << "****************************************************************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "February 15, 2018" << endl;
	cout << "Lab 5" << endl;
	cout << "Program to calculate Employee Tax and Income" << endl;
	cout << "****************************************************************************************************" << endl;
}

float compute_gross_pay(int deductions, float payRate, char parttime_fulltime)
{
	float gross_pay;
	if (parttime_fulltime == 'P') {                  //P - Part-time
		gross_pay = (40 * payRate) + (10.50 * deductions);
	}
	else if (parttime_fulltime == 'F') {             //F - Full-time
		gross_pay = (40 * payRate);
	}
	return gross_pay;
}

float compute_federal_tax(float gross_pay) {
	float federal_tax;
    if (gross_pay > 500) {
		federal_tax = (200 * 0.15) + (300 * 0.25) + ((gross_pay - 500) * 0.35);
	}
    else if (gross_pay > 200) {
		federal_tax = 200 * 0.15;
		federal_tax += (gross_pay - 200) * 0.25;
	}
	else {
		federal_tax = gross_pay * 0.15;
	}
	return federal_tax;
}

float compute_state_tax(float federal_tax) {
	float state_tax;
	if (federal_tax < 80) {
		state_tax = 0;
	}
	else if (federal_tax >= 80) {
		state_tax = 0.10 * federal_tax;
	}
	return state_tax;
}

float compute_city_tax(float state_tax) {
	float city_tax;
	if (state_tax <= 50) {
		city_tax = 0;
	}
	else if (state_tax > 50) {
		city_tax = 0.08 * state_tax;
	}
	return city_tax;
}

float compute_taxes(float gross_pay) {
	float cityTax;
	float stateTax;
	float federalTax;
	float totalTax;

	federalTax = compute_federal_tax(gross_pay);
	stateTax = compute_state_tax(federalTax);
	cityTax = compute_city_tax(stateTax);
	totalTax = federalTax + stateTax + cityTax;
	return totalTax;
}

float compute_net_pay(float gross_pay, float totalTax) {
	float net_pay;
	net_pay = gross_pay - totalTax;
	return net_pay;
}

void print_pay_check(string last_name, string first_name, int address_num, string street_name, string date, string city, string state, int zip, float gross_pay, float net_pay, float total_tax) {
	cout << fixed << showpoint;
	cout << "****************************************************************************************************" << endl << endl;
	cout << "ABC Flowers" << endl;
	cout << "123 Georgia Ave" << "                                   " << date << endl;
	cout << "Washington, DC 20059" << endl << endl;
	cout << "Payable to:  " << last_name << " " << first_name;
	cout << "              " << "Pay this amount: " << setprecision(2) << net_pay << endl;
	cout << "             " << address_num << " " << street_name << endl;
	cout << "             " << city << " " << state << " " << zip << endl << endl;
	cout << "Gross Pay:   " << setprecision(2) << gross_pay << endl;
	cout << "Total Taxes: " << setprecision(2) << total_tax << endl << endl;
	cout << "****************************************************************************************************" << endl;
	return;
}
