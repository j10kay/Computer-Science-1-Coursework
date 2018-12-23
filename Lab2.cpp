#include <iostream>                        // include input/output library code
#include <string>     // include string manipulate library code
#include <iomanip>
using namespace std;                       // allows all of the names in a namespace 
										   // to be accessed without the namespace 
										   // identifier as a qualifier
void heading();
const float MILE_RATE = 0.35;

int main()
{
	heading();
	float old_odometer_reading;
	float new_odometer_reading;
	float distance_difference;

	cout << fixed << showpoint;
	cout << "Enter beginning odometer reading => ";
	cin >> old_odometer_reading;
	cout << "Enter ending odometer reading => ";
	cin >> new_odometer_reading;
	distance_difference = new_odometer_reading - old_odometer_reading;
	cout << "You traveled " << setprecision(2) << distance_difference
		<< " miles. At $" << MILE_RATE << " per mile, your reimbuersement is $" << setprecision(2)
		<< distance_difference * MILE_RATE << "." << endl;
	system("pause");
	return 0;
}

void heading()
{
	cout << "***********************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "February 12, 2018" << endl;
	cout << "Class Exercise, Problem 2" << endl;
	cout << "MILEAGE REIMBURSEMENT CALCULATOR" << endl;
	cout << "***********************************************************" << endl;
}
