#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void get_store_data(ifstream&, string[], float[][5]);  //Function Prototypes
float compute_sales_total(float[][5], int);
void display_store_data(string[], float[][5], float[]);
void heading();

int main() {
	heading();
	string store_names[7];     //Array Declarations
	float sales_total[7][5];
	float grand_total[7];
	ifstream myfile;
	myfile.open("infile.txt");
	get_store_data(myfile, store_names, sales_total);
	for (int i = 0; i < 7; i++) {
		grand_total[i] = compute_sales_total(sales_total, i);
	}
	display_store_data(store_names, sales_total, grand_total);
	system("pause");
	return 0;
}

void get_store_data(ifstream& myfile, string store_names[], float sales_total[][5]) {   //Function to assign read data to array elements

	for (int i = 0; i < 7; i++) {
		myfile >> store_names[i];
		for (int j = 0; j < 5; j++) {
			myfile >> sales_total[i][j];
		}
	}
}

float compute_sales_total(float sales_total[][5], int store_index) {   //Compute total from array elements
	float total = 0;
	for (int i = 0; i < 5; i++) {
		total += sales_total[store_index][i];
	}
	return total;
}

void display_store_data(string store_names[], float sales_total[][5], float grand_total[]) {  //Function to print output
	cout << fixed << showpoint;
	cout << "Store Name" << '\t' << "JAN" << '\t' << "FEB" << '\t' << "MAR"
		 << '\t' << "APR" << '\t' << "MAY" << '\t' << "Total" << endl << endl;
	for (int i = 0; i < 7; i++) {
		cout << setprecision(2) << store_names[i] << '\t';

		for (int j = 0; j < 5; j++) {
			cout << setprecision(2) << sales_total[i][j] << '\t';
		}
		cout << setprecision(2) << grand_total[i] << endl;
	}
}

void heading() {    //Header Function for my output
	cout << "*********************************************************************" << endl;
	cout << "Chijioke E. Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "April 19, 2018" << endl;
	cout << "Lab 12" << endl;
	cout << "*********************************************************************" << endl << endl;
}
