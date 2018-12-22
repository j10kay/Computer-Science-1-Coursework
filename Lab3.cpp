#include <iostream>
using namespace std;
void print_BMI(int);           //function declaration 

int main()
{
	const int BMI_CONSTANT = 703;	// Non-metric constant
	float weight = 175;                // Weight in pounds
	float height = 72;			// Height in inches
	int bodyMassIndex;

	bool dataAreOK;              // True if data OK
								 // Calculate body mass index
	bodyMassIndex = weight * BMI_CONSTANT
		/ (height * height);
	// Print message indicating status
	cout << "Your BMI is "
		<< bodyMassIndex << ". " << endl;
	cout << "Interpretation and instructions. "
		<< endl;
	print_BMI(bodyMassIndex);
	system("pause");
	return 0;
}

void print_BMI(int bodyMassIndex)
{
	if (bodyMassIndex < 20)
		cout << "Underweight: ...." << endl;
	else if (bodyMassIndex <= 25)
		cout << "Normal: ...." << endl;
	else if (bodyMassIndex <= 30)
		cout << "Overweight:...." << endl;
	else
		cout << "Obese: ...." << endl;
	return;
}
