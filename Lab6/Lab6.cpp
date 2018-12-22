#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Function Prototypes (structure chart functions)
int Get_lab_data();
int Get_quiz_data();
int Get_test_data();
int Get_assignment_data();
char Compute_lab_grade(int);
char Compute_quiz_grade(int);
char Compute_test_grade(int);
char Compute_assignment_grade(int);
ifstream myfile;                          // Global file variable
float grade_weight(char);
char Compute_final_grade(float);


int main()
{


	myfile.open("infile.txt");            //Open file
	
	float final_average;                 // Variable Declarations
	char final_grade;
	char final_lab_grade;              
	char final_assignment_grade; 
	char final_quiz_grade; 
	char final_test_grade;
	int num_students = 1;

	while (num_students <= 6) {

		final_lab_grade = Compute_lab_grade(Get_lab_data());
		final_assignment_grade = Compute_assignment_grade(Get_assignment_data());
		final_quiz_grade = Compute_quiz_grade(Get_quiz_data());
		final_test_grade = Compute_test_grade(Get_test_data());

		cout << "Student" << " " << num_students << endl;
		cout << "Student's Lab grade is: " << final_lab_grade << endl;
		cout << "Student's Assignment grade is: " << final_assignment_grade << endl;
		cout << "Student's Quiz grade is: " << final_quiz_grade << endl;
		cout << "Student's Test grade is: " << final_test_grade << endl;
		final_average = ((10 * grade_weight(final_quiz_grade) + (25 * grade_weight(final_assignment_grade))          // Compute final average
			          + (30 * grade_weight(final_lab_grade)) + (35 * grade_weight(final_test_grade))) / float(100));
		cout << "Student's final grade is: " << Compute_final_grade(final_average) << endl << endl;
		num_students++;                        // Increment loop counter 
	}
	myfile.close();        //Close file
	system("pause");
	return 0;              //Return 0 if all processes execute 
}


int Get_lab_data()                           //Function to read lab values from file
{
	int lab_total = 0;
	int lab_count = 1;
	int lab_reading;

	while (lab_count <= 5) {
		myfile >> lab_reading;
		lab_total += lab_reading;
		lab_count++;
	}
	return lab_total;
}

int Get_quiz_data()                     //Function to read quiz values from file
{
	int quiz_total = 0;
	int quiz_count = 1;
	int quiz_reading; 

	while (quiz_count <= 12) {
		myfile >> quiz_reading;
		quiz_total += quiz_reading;
		quiz_count++;
	}
	return quiz_total;
}

int Get_test_data()                     //Function to read test values from file
{
	int test_total = 0;
	int test_count = 1;
	int test_reading = 0;

	while (test_count <= 3) {
		myfile >> test_reading;
		test_total += test_reading;
		test_count++;
	}
	return test_total;
}

int Get_assignment_data()                //Function to read assignment values from file
{
	int assignment_total = 0;
	int assignment_count = 1;
	int assignment_reading;

	while (assignment_count <= 7) {
		myfile >> assignment_reading;
		assignment_total += assignment_reading;
		assignment_count++;
	}
	return assignment_total;
}

char Compute_lab_grade(int lab_data)        //Function to compute lab grade based on lab total
{
	char lab_grade;
	if (lab_data > 60) {
		lab_grade = 'A';
	}
	else if (lab_data >= 50) {
		lab_grade = 'B';
	}
	else if (lab_data >= 40) {
		lab_grade = 'C';
	}
	else if (lab_data >= 30) {
		lab_grade = 'D';
	}
	else {
		lab_grade = 'F';
	}
	return lab_grade;
}

char Compute_quiz_grade(int quiz_data)          //Function to compute quiz grade based on quiz total
{
	char quiz_grade;
	if (quiz_data > 100) {
		quiz_grade = 'A';
	}
	else if (quiz_data >= 85) {
		quiz_grade = 'B';
	}
	else if (quiz_data >= 70) {
		quiz_grade = 'C';
	}
	else if (quiz_data >= 60) {
		quiz_grade = 'D';
	}
	else {
		quiz_grade = 'F';
	}
	return quiz_grade;
}

char Compute_test_grade(int test_data)          //Function to compute test grade based on test total
{
	char test_grade;
	if (test_data > 360) {
		test_grade = 'A';
	}
	else if (test_data >= 210) {
		test_grade = 'B';
	}
	else if (test_data >= 180) {
		test_grade = 'C';
	}
	else if (test_data >= 150) {
		test_grade = 'D';
	}
	else {
		test_grade = 'F';
	}
	return test_grade;
}

char Compute_assignment_grade(int assignment_data)          //Function to compute assignment grade based on assignment total
{
	char assignment_grade;
	if (assignment_data > 130) {
		assignment_grade = 'A';
	}
	else if (assignment_data >= 112) {
		assignment_grade = 'B';
	}
	else if (assignment_data >= 100) {
		assignment_grade = 'C';
	}
	else if (assignment_data >= 80) {
		assignment_grade = 'D';
	}
	else {
		assignment_grade = 'F';
	}
	return assignment_grade;
}

float grade_weight(char letter_grade)        //Function to convert letter grades to their equivalent weights
{
	if (letter_grade == 'A') {
		return 4.0;
	}
	else if (letter_grade == 'B') {
		return 3.0;
	}
	else if (letter_grade == 'C') {
		return 2.0;
	}
	else if (letter_grade == 'D') {
		return 1.0;
	}
	else {
		return 0.0;
	}
}

char Compute_final_grade(float final_average)        //Function to return grade based on final average
{
	char final_grade;
	if (final_average > 3.49) {
		final_grade = 'A';
	}
	else if (final_average >= 2.7) {
		final_grade = 'B';
	}
	else if (final_average >= 1.7) {
		final_grade = 'C';
	}
	else if (final_average >= 0.7) {
		final_grade = 'D';
	}
	else {
		final_grade = 'F';
	}
	return final_grade;
}
