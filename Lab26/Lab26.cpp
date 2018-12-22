#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct examType {                    //Custom data type to store grade data
	string semester_name;
	int semester_year;
	int no_of_grades;
	float average_grade;
	int no_of_grades_above_average;
	int no_of_grades_below_average;
	int grades_array[35];
};

//Function Prototypes
void heading();
void input_data(examType[], ifstream&);
void print_results(examType[]);
void calculate_statistics(examType[]);
void calculate_average(int, examType[]);
void calculate_above_average(int, examType[]);
void calculate_below_average(int, examType[]);


int main() {
	heading();
	ifstream myfile;
	myfile.open("infile.txt");
	examType statistics_array[5];
	input_data(statistics_array, myfile);
	calculate_statistics(statistics_array);
	print_results(statistics_array);
	system("pause");
	return 0;
}

//Header Function
void heading() {
	cout << "****************************************************************************************************" << endl;
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "April 26, 2018" << endl;
	cout << "CS Exam #2" << endl;
	cout << "****************************************************************************************************" << endl;
}

//Function to populate some elements of the struct
void input_data(examType statistics_array[], ifstream& myfile) {
	for (int i = 0; i < 5; i++) {
		myfile >> statistics_array[i].semester_name >> statistics_array[i].semester_year
			   >> statistics_array[i].no_of_grades;
		for (int j = 0; j < statistics_array[i].no_of_grades; j++) {
			myfile >> statistics_array[i].grades_array[j];
		}
	}
}

//Function to print results
void print_results(examType statistics_array[]) {
	cout << fixed << showpoint;
	for (int i = 0; i < 5; i++) {
		cout << "****************************************************************************************************" << endl;
		cout << "Analysis of exams in " << statistics_array[i].semester_name 
		     << " " << statistics_array[i].semester_year << "." << endl << endl;
		cout << "The number of grades is " << statistics_array[i].no_of_grades << "." << endl;
		cout << "The average grade is " << setprecision(2) << statistics_array[i].average_grade << "." << endl;
		cout << "The number of grades above the average is " << statistics_array[i].no_of_grades_above_average << "." << endl;
		cout << "The number of grades below the average is " << statistics_array[i].no_of_grades_below_average << "." << endl;
		cout << "****************************************************************************************************" << endl << endl;
	}
}

//Calculates required statistics
void calculate_statistics(examType statistics_array[]) {
	for (int i = 0; i < 5; i++) {
		calculate_average(i, statistics_array);
		calculate_above_average(i, statistics_array);
		calculate_below_average(i, statistics_array);
	}
}

//Function to calculate and store average grade to struct
void calculate_average(int semester_index, examType statistics_array[]) {  
	int grade_sum = 0;        //Initialize sum of grades to zero.
	for (int j = 0; j < statistics_array[semester_index].no_of_grades; j++) {  //Loop through each grade 
		grade_sum += statistics_array[semester_index].grades_array[j];  //Update sum of grades after each iteration
	}
	float average_grade;
	average_grade = float(grade_sum) / statistics_array[semester_index].no_of_grades;
	statistics_array[semester_index].average_grade = average_grade;
}

//Function to obtain and store number of grades above the average grade
void calculate_above_average(int semester_index, examType statistics_array[]) {
	int above_average_count = 0;
	for (int j = 0; j < statistics_array[semester_index].no_of_grades; j++) {
		if (statistics_array[semester_index].grades_array[j] > statistics_array[semester_index].average_grade) {  //Compare grade to average
			above_average_count++;
		}
	}
	statistics_array[semester_index].no_of_grades_above_average = above_average_count;
}

//Function to obtain and store number of grades below the average grade
void calculate_below_average(int semester_index, examType statistics_array[]) {
	int below_average_count = 0;
	for (int j = 0; j < statistics_array[semester_index].no_of_grades; j++) {  
		if (statistics_array[semester_index].grades_array[j] < statistics_array[semester_index].average_grade) {  //Compare grade to average
			below_average_count++;
		}
	}
	statistics_array[semester_index].no_of_grades_below_average = below_average_count;
}
