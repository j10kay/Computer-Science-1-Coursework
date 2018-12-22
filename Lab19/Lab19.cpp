#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

enum HealthType { Poor, Fair, Good, Excellent };       //User-defined data type for health
enum YearType {Freshman, Sophomore, Junior, Senior};   //User-defined data type for classification

struct StudentType {          //User-defined data type for multiple student records
	string id;
	string name;
	YearType year;
	HealthType health;
	float gpa;
};

void heading();                //Function Prototypes
void printStruct(StudentType);

int main() {

	heading();
	ifstream myfile;
	StudentType Student;     //Variable declarations
	char student_year;
	char health_status;
	myfile.open("infile.txt"); 

	myfile >> Student.id >> Student.name >> student_year >> health_status >> Student.gpa;     //Priming Read
	cout << left << setw(15) << " ID Number " << left << setw(15) << " Name " << left 
		 << setw(20) << " Classification " << left << setw(15) << " Health " << left << setw(7) << " GPA " << endl;
	cout << "---------------------------------------------------------------------" << endl;

	while (myfile) {         //While Loop to iterate through file records
		switch (student_year) {    //Switch statement to convert data types
		case 'f':
			Student.year = Freshman;
			break;
		case 's':
			Student.year = Sophomore;
			break;
		case 'j':
			Student.year = Junior;
			break;
		case 'n':
			Student.year = Senior;
			break;
		default:
			break;
		}

		switch (health_status) {
		case 'p':
			Student.health = Poor;
			break;
		case 'f':
			Student.health = Fair;
			break;
		case 'g':
			Student.health = Good;
			break;
		case 'e':
			Student.health = Excellent;
			break;
		default:
			break;
		}
		printStruct(Student);
		myfile >> Student.id >> Student.name >> student_year >> health_status >> Student.gpa;
	}

	system("pause");
	return 0;        //Return 0 if all goes as planned
}

void heading() {    //Header Function for my output
	cout << "*********************************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "April 5, 2018" << endl;
	cout << "Lab 10" << endl;
	cout << "*********************************************************************" << endl << endl;
}

void printStruct(StudentType student) {    //Function to print records from StudentType data type
	cout << fixed << showpoint;
	string student_type;
	string health_condition;

	switch (student.year) {
	case Freshman:
		student_type = "Freshman";
		break;
	case Sophomore:
		student_type = "Sophomore";
		break;
	case Junior:
		student_type = "Junior";
		break;
	case Senior:
		student_type = "Senior";
		break;
	default:
		break;
	}

	switch (student.health) {
	case Poor:
		health_condition = "Poor";
		break;
	case Fair:
		health_condition = "Fair";
		break;
	case Good:
		health_condition = "Good";
		break;
	case Excellent:
		health_condition = "Excellent";
		break;
	default:
		break;
	}
	cout << left << setw(15) << student.id << left << setw(15) << student.name << left 
		 << setw(20) << student_type << left << setw(15) << health_condition << left << setw(7) << setprecision(2) << student.gpa << endl;
}
