#include <iostream>
#include <string>
using namespace std;

enum HealthType { Poor, Fair, Good, Excellent };  //User-defined data type for health
struct StudentType {          //User-defined data type for multiple student records
	string id;
	string name;
	char year;
	float gpa;
	HealthType health;
};
void compareHealth(StudentType, StudentType);   //Function Prototype

int main() {

	StudentType StudentA;       //Declarations of Custom Data Type
	StudentType StudentB;
	StudentA.id = "@02840667";       //Individual Initializations of the various members of the StudentType data type
	StudentA.name = "Chijioke Kamanu";
	StudentA.year = 'F';
	StudentA.gpa = 4.00;
	StudentA.health = Good;

	StudentB.id = "@02835602";
	StudentB.name = "Emmanuel Aguebor";
	StudentB.year = 'F';
	StudentB.gpa = 3.60;
	StudentB.health = Excellent;

	compareHealth(StudentA, StudentB);
	compareHealth(StudentB, StudentA);

	system("pause");
	return 0;        //Return 0 if all goes as planned
}

void compareHealth(StudentType stdA, StudentType stdB) {   //Function to compare health status
	if (stdA.health < stdB.health) {
		cout << stdA.name << " is less healthy than " << stdB.name << "." << endl;
	}
	else if (stdA.health == stdB.health) {
		cout << stdA.name << "is as healthy as " << stdB.name << "." << endl;
	}
	else {
		cout << stdB.name << " is less healthy than " << stdA.name << "." << endl;
	}
}
