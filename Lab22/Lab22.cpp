#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

enum CarMakeType {Audi, Chrysler, Ford, Nissan, Mercedes, Honda, Volvo, Porsche, Lexus};    //Make enumerated list of cars that company sells.

struct DateType {           //Make a date struct that contains information about day, month, and year.
	int day;                //Declare struct variables.
	int month;
	int year;
};

struct CarType {            //Make struct that contains information about the customer, delivery date of the car, cost, and car model.
	string first_name;      //Declare struct variables.
	string last_name;
	float car_price;
	DateType delivery_date;
	CarMakeType car_make;
};

CarType Get_Car_Data(ifstream&);        //Function Prototypes
void Lookup_Car_Data(char, CarType[]);
void Modify_Car_Data(float, int, CarType[]);
void Output_Car_Data(CarType[], ofstream&);
void Print_Car_Report(CarType[]);
void Write_Car_Output(CarType[], ofstream&);
void heading();

int main() {
	ifstream myfile;
	ofstream output_file;
	heading();
	int index = 0;
	CarType Car_list[11];
	char user_choice;
	char user_car_choice;
	myfile.open("infile.txt");

	Car_list[index] = Get_Car_Data(myfile);       //Priming Read
	while (myfile) {
		index++;
		Car_list[index] = Get_Car_Data(myfile);   //Incremental Read
	}

	do {
		cout << endl << "Choose from the list of car manufacturers below." << endl << "(F-Ford, L-Lexus, N-Nissan,";
		cout << " M-Mercedes, H-Honda, A-Audi, C-Chrysler, V-Volvo, P-Porsche)" << endl << endl;
		cout << "Enter the name of the car you wish to discount: ";
		cin >> user_car_choice;
		Lookup_Car_Data(user_car_choice, Car_list);
		cout << endl << "Do you wish to modify more cars? ";
		cin >> user_choice;
	} while (user_choice != 'N');
	Output_Car_Data(Car_list, output_file);   //Output data to screen and file

	system("pause");
	return 0;   //Return 0 if all goes as planned
}

void heading() {    //Header Function for my output
	cout << "*********************************************************************" << endl;
	cout << "Chijioke E. Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "April 12, 2018" << endl;
	cout << "Lab 11" << endl;
	cout << "*********************************************************************" << endl << endl;
}

CarType Get_Car_Data(ifstream& myfile) {

	CarType random_car;
	char car_make_symbol;
	myfile >> random_car.first_name >> random_car.last_name >> random_car.car_price
		>> random_car.delivery_date.month >> random_car.delivery_date.day >> random_car.delivery_date.year
		>> car_make_symbol;

	switch (car_make_symbol) {
	
	case 'F':
		random_car.car_make = Ford;
		break;
	case 'L':
		random_car.car_make = Lexus;
		break;
	case 'N':
		random_car.car_make = Nissan;
		break;
	case 'M':
		random_car.car_make = Mercedes;
		break;
	case 'H':
		random_car.car_make = Honda;
		break;
	case 'A':
		random_car.car_make = Audi;
		break;
	case 'C':
		random_car.car_make = Chrysler;
		break;
	case 'V':
		random_car.car_make = Volvo;
		break;
	case 'P':
		random_car.car_make = Porsche;
		break;
	default:
		break;
	}
	return random_car;
}

void Lookup_Car_Data(char car_make_symbol, CarType Car_list[]) {
	
	CarMakeType car_make_enum;
	switch (car_make_symbol) {
	case 'F':
		car_make_enum = Ford;
		break;
	case 'L':
		car_make_enum = Lexus;
		break;
	case 'N':
		car_make_enum = Nissan;
		break;
	case 'M':
		car_make_enum = Mercedes;
		break;
	case 'H':
		car_make_enum = Honda;
		break;
	case 'A':
		car_make_enum = Audi;
		break;
	case 'C':
		car_make_enum = Chrysler;
		break;
	case 'V':
		car_make_enum = Volvo;
		break;
	case 'P':
		car_make_enum = Porsche;
		break;
	default:
		cout << "Invalid selection." << endl;
		break;
	}

	string car_model; 
	switch (car_make_enum) {

	case Ford:
		car_model = "Ford";
		break;
	case Lexus:
		car_model = "Lexus";
		break;
	case Nissan:
		car_model = "Nissan";
		break;
	case Mercedes:
		car_model = "Mercedes";
		break;
	case Honda:
		car_model = "Honda";
		break;
	case Audi:
		car_model = "Audi";
		break;
	case Chrysler:
		car_model = "Chrysler";
		break;
	case Volvo:
		car_model = "Volvo";
		break;
	case Porsche:
		car_model = "Porsche";
		break;
	default:
		cout << "Invalid selection." << endl;
		break;
	}

	for (int x = 0; x < 10; x++) {
		cout << fixed << showpoint;
		if (Car_list[x].car_make == car_make_enum) {
			cout << "You are modifying: " << endl;
			cout << '\t' << "Customer Name: " << Car_list[x].first_name << " " << Car_list[x].last_name << endl;
			cout << '\t' << "Car Price: $" << setprecision(2) << Car_list[x].car_price << endl;
			cout << '\t' << "Purchase Date: " << Car_list[x].delivery_date.month << "/"
				 << Car_list[x].delivery_date.day << "/" << Car_list[x].delivery_date.year << endl;
			cout << '\t' << "Car Model: " << car_model << endl;

			float discount_rate;
			cout << "Enter the desired discount (e.g. 0.10 for 10%): ";
			cin >> discount_rate;
			cout << "Old Price: $" << setprecision(2) << Car_list[x].car_price << endl;
			Modify_Car_Data(discount_rate, x, Car_list);
			cout << "New Price: $" << setprecision(2) << Car_list[x].car_price << endl;
			cout << (discount_rate * 100) << "% discount has been applied." << endl;
			break;
		}
		
	}
}

void Modify_Car_Data(float discount_rate, int array_member, CarType Car_list[]) {
	Car_list[array_member].car_price = Car_list[array_member].car_price * (1 - discount_rate);
}

void Output_Car_Data(CarType Car_list[], ofstream& output_file) {
	Print_Car_Report(Car_list);
	Write_Car_Output(Car_list, output_file);
}

void Print_Car_Report(CarType Car_list[]) {
	string car_model;
	
	
	cout  << "Customer Name" << '\t' << '\t' << "Price" << '\t' << '\t' << "     " << "Purchase-Date" << '\t' << '\t' << "Model" << endl;
	for (int x = 0; x < 10; x++) {
		switch (Car_list[x].car_make) {

		case Ford:
			car_model = "Ford";
			break;
		case Lexus:
			car_model = "Lexus";
			break;
		case Nissan:
			car_model = "Nissan";
			break;
		case Mercedes:
			car_model = "Mercedes";
			break;
		case Honda:
			car_model = "Honda";
			break;
		case Audi:
			car_model = "Audi";
			break;
		case Chrysler:
			car_model = "Chrysler";
			break;
		case Volvo:
			car_model = "Volvo";
			break;
		case Porsche:
			car_model = "Porsche";
			break;
		default:
			cout << "Invalid selection." << endl;
			break;
		}
		cout  << Car_list[x].first_name << " " << Car_list[x].last_name << '\t' << '\t' << "$" << Car_list[x].car_price
			<< '\t' << '\t' << Car_list[x].delivery_date.month << "/" << Car_list[x].delivery_date.day << "/" << Car_list[x].delivery_date.year
			<< '\t' << '\t' << car_model << '\n';
	}
}

void Write_Car_Output(CarType Car_list[], ofstream& output_file) {
	output_file.open("outfile.txt");
	for (int x = 0; x < 10; x++) {
		output_file << Car_list[x].first_name << " " << Car_list[x].last_name << " " << Car_list[x].car_price
			        << " " << Car_list[x].delivery_date.month << " " << Car_list[x].delivery_date.day << " " << Car_list[x].delivery_date.year
			        << " " << Car_list[x].car_make << '\n';
	}
	output_file.close();
}
