#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void get_user_input(char&, int&, int&, int&, int&);
float compute_item_cost(char, int, int, int, int);       //Function Prototypes
void heading();

int main()
{
	heading();
	int num_pieces, width, height, length;       //Variable Declarations
	char wood_type;

	get_user_input(wood_type, num_pieces, width, height, length);   //Priming Read
	float total_cost = 0;
	while (wood_type != 'T') {
		float cost = compute_item_cost(wood_type, num_pieces, width, height, length);
		string wood_name;
		switch (wood_type) {    //Switch statement
		case 'P':
			wood_name = "Pine";
			break;
		case 'F':
			wood_name = "Fir";
			break;
		case 'C':
			wood_name = "Cedar";
			break;
		case 'M':
			wood_name = "Maple";
			break;
		case 'O':
			wood_name = "Oak";
			break;
		default:
			cout << "This input is invalid";
			break;
		}
		cout << fixed << showpoint;
		cout << num_pieces << " " << width << "X" << height << "X" << length << " " << wood_name << ", Cost: $" << setprecision(2) << cost << endl;
		cout << "****************************************************************************************************" << endl;
		total_cost += cost;   //Update total cost
		get_user_input(wood_type, num_pieces, width, height, length);   //Get next input
	}
	cout << "Total: $" << setprecision(2) << total_cost << endl;
	system("pause");
	return 0;   //Return 0 if all goes as expected
}

void get_user_input(char& wood_type, int& num_pieces, int& width, int& height, int& length)
{  //Function to obtain user input 
	cout << "Enter item (Wood Type -- Number of pieces -- Width -- Height -- Length): " << endl;
	cin >> wood_type >> num_pieces >> width >> height >> length;
	return;
}

float compute_item_cost(char wood_type, int num_pieces, int width, int height, int length)
{   //Function to compute cost of wood
	float rate;
	float cost;
	switch (wood_type) {
	case 'P':
		rate = 0.89;
		break;
	case 'F':
		rate = 1.09;
		break;
	case 'C':
		rate = 2.26;
		break;
	case 'M':
		rate = 4.50;
		break;
	case 'O':
		rate = 3.10;
		break;
	default:
		cout << "This input is invalid";
		break;
	}
	cost = float(rate * num_pieces * width * height * length) / 12;
	return cost;
}

void heading()
{
	cout << "****************************************************************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "March 29, 2018" << endl;
	cout << "Lab 9, Problem 2" << endl;
	cout << "****************************************************************************************************" << endl;
}
