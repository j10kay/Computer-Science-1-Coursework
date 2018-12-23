#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
void heading();
float average(float total, int numb_of_temps);
float difference_of(float a, float b);


int main()
{
	heading();
	cout << fixed << showpoint;
	float temperature_1, temperature_2;
	float total_temperature;
	ifstream temperature_file;
	temperature_file.open("infile.txt");       // Open file
	
	cout << "TEMP" << "                     " << "DIFF" << endl;
	temperature_file >> temperature_1;         // Read value from file
	cout << setprecision(1) << temperature_1 << endl;
	total_temperature = temperature_1;         // Create a count variable for total temperature 

	temperature_file >> temperature_2;
	total_temperature += temperature_2;            // Update count variable as values are read
	cout << setprecision(1) << temperature_2 << "                     " 
		 << difference_of(temperature_1, temperature_2) << endl;         // Calculate temperature difference 
	
	
	temperature_file >> temperature_1;
	cout << setprecision(1) << temperature_1 << "                     " 
		 << difference_of(temperature_2, temperature_1) << endl;
	total_temperature += temperature_1;
	
	temperature_file >> temperature_2;
	total_temperature += temperature_2;
	cout << setprecision(1) << temperature_2 << "                     " 
		 << difference_of(temperature_1, temperature_2) << endl;

	temperature_file >> temperature_1;
	cout << setprecision(1) << temperature_1 << "                     " 
		 << difference_of(temperature_2, temperature_1) << endl;
	total_temperature += temperature_1;
	
	temperature_file >> temperature_2;
	total_temperature += temperature_2;
	cout << setprecision(1) << temperature_2 << "                     " 
		 << difference_of(temperature_1, temperature_2) << endl;

	temperature_file >> temperature_1;
	cout << setprecision(1) << temperature_1 << "                     " 
		 << difference_of(temperature_2, temperature_1) << endl;
	total_temperature += temperature_1;
	
	temperature_file >> temperature_2;
	total_temperature += temperature_2;
	cout << setprecision(1) << temperature_2 << "                     " 
		 << difference_of(temperature_1, temperature_2) << endl;

	temperature_file >> temperature_1;
	cout << setprecision(1) << temperature_1 << "                     " 
		 << difference_of(temperature_2, temperature_1) << endl;
	total_temperature += temperature_1;
	
	temperature_file >> temperature_2;
	total_temperature += temperature_2;
	cout << setprecision(1) << temperature_2 << "                     " 
		 << difference_of(temperature_1, temperature_2) << endl;

	temperature_file >> temperature_1;
	cout << setprecision(1) << temperature_1 << "                     " 
		 << difference_of(temperature_2, temperature_1) << endl;
	total_temperature += temperature_1;
	
	temperature_file >> temperature_2;
	total_temperature += temperature_2;
	cout << setprecision(1) << temperature_2 << "                     " 
		 << difference_of(temperature_1, temperature_2) << endl;

	cout << setprecision(2) << "Average Temperature: " 
		 << average(total_temperature, 12) << endl;      //Calculate average temperature 

	temperature_file.close();              // Close temperature file
	system("pause");
	return 0;
}


void heading()
{
	cout << "***********************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "February 8, 2018" << endl;
	cout << "Lab 4, Problem 2" << endl;
	cout << "Problem: Compute the difference between temperatures and the average temperature" << endl;
	cout << "***********************************************************" << endl;
}

float difference_of(float a, float b)
{
	float temperature_difference = b - a;
	return temperature_difference;
}

float average(float total, int numb_of_temps)
{
	float average_temperature = total / numb_of_temps;
	return average_temperature;
}
