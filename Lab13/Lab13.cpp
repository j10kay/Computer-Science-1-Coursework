#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void evaluate_cholesterol(int, int, string&, string&);    //Function Prototypes
void evaluate_blood_pressure(int, int, string&, string&);
void heading();
float evaluate_ratio(int, int);

int main() {

	ifstream myfile;                                    //Data declaration
	myfile.open("infile.txt");
	int num_of_records;
	heading();
	cout << "How many patient records do you want to read? " << endl;
	cin >> num_of_records;

	int i;
	for (i = 1; i <= num_of_records; i++) {         //Outer Loop
		string patient_name;
		char patient_status;
		int num_visits;

		myfile >> patient_name >> patient_status >> num_visits;

		if (myfile.eof()) {  //Break out of loop if no data is left in file
			cout << "You have exceeded the file limit." << endl;
			break;
		}
		
		cout << endl;
		switch (patient_status) {  //Switch statement to deetermine patient status
		case 'C': 
			cout << "Current ";
			break;
		case 'N':
			cout << "New ";
			break;
		case 'F':
			cout << "Referral ";
			break;
		case 'R':
			cout << "Returning ";
			break;
		default:
			cout << "Switch case does not exist." << endl;
			break;
		}

		cout << "Patient's Name: " << patient_name << endl;
		
		int j;
		for (j = 1; j <= num_visits; j++) {           //Inner Loop

			int patient_HDL_level;
			int patient_LDL_level;
			int patient_systolic_blood_pressure_value;
			int patient_diastolic_blood_pressure_value;
			string HDL_evaluation;
			string LDL_evaluation;
			string systolic_evaluation;
			string diastolic_evaluation;

			myfile >> patient_HDL_level >> patient_LDL_level
				>> patient_systolic_blood_pressure_value >> patient_diastolic_blood_pressure_value;

			cout << "*********************** DATA SET " << j << " ************************" << endl;
			evaluate_cholesterol(patient_HDL_level, patient_LDL_level, HDL_evaluation, LDL_evaluation);
			cout << '\t' << "Ratio: " << setprecision(4) << evaluate_ratio(patient_HDL_level, patient_LDL_level) << endl;
			if (evaluate_ratio(patient_HDL_level, patient_LDL_level) > 0.3) {
				cout << '\t' << "Ratio of HDL to LDL is good" << endl;
			}
			else {
				cout << '\t' << "Ratio of HDL to LDL is not good" << endl;
			}
			evaluate_blood_pressure(patient_systolic_blood_pressure_value, patient_diastolic_blood_pressure_value, systolic_evaluation, diastolic_evaluation);

		}
	}
	myfile.close();
	system("pause");
	return 0;      //Return 0 if all runs as expected
}

float evaluate_ratio(int HDL_reading, int LDL_reading) {
	float HDL_to_LDL_ratio = (float(HDL_reading) / LDL_reading);
	return HDL_to_LDL_ratio;
}
void evaluate_cholesterol(int HDL_reading, int LDL_reading, string& HDL_evaluation, string& LDL_evaluation) { //Function to obtain HDL and LDL evaluations by reference
	cout << "Cholestrol Profile: " << endl;
	cout << '\t' << "HDL: " << HDL_reading << '\t' << '\t' << "LDL: " << LDL_reading << endl;
	if (HDL_reading < 40) {
		HDL_evaluation = "too low";
	}
	else if (HDL_reading < 60) {
		HDL_evaluation = "is okay";
	}
	else {
		HDL_evaluation = "excellent";
	}
	cout << '\t' << "HDL is " << HDL_evaluation << endl;
	if (LDL_reading < 100) {
		LDL_evaluation = "optimal";
	}
	else if (LDL_reading < 130) {
		LDL_evaluation = "near optimal";
	}
	else if (LDL_reading < 160) {
		LDL_evaluation = "borderline high";
	}
	else if (LDL_reading < 190) {
		LDL_evaluation = "high";
	}
	else {
		LDL_evaluation = "very high" ;
	}
	cout << '\t' << "LDL is " << LDL_evaluation << endl;
	return;
}

void evaluate_blood_pressure(int systolic_reading, int diastolic_reading, string& systolic_evaluation, string& diastolic_evaluation) {
	cout << endl << "Blood Pressure Profile: " << endl;    //Function to obtain systolic and diastolic evaluations by reference
	cout << '\t' << "Systolic: " << systolic_reading << '\t' << "Diastolic: " << diastolic_reading << endl;
	if (systolic_reading < 120) {
		systolic_evaluation = "optimal";
	}
	else if (systolic_reading < 130) {
		systolic_evaluation = "normal";
	}
	else if (systolic_reading < 140) {
		systolic_evaluation = "normal high";
	}
	else if (systolic_reading < 160) {
		systolic_evaluation = "Stage 1 Hypertension";
	}
	else if (systolic_reading < 180) {
		systolic_evaluation = "Stage 2 Hypertension";
	}
	else {
		systolic_evaluation = "Stage 3 Hypertension";
	}
	cout << '\t' << "Systolic reading is " << systolic_evaluation << endl;

	if (diastolic_reading < 80) {
		diastolic_evaluation = "optimal";
	}
	else if (diastolic_reading < 85) {
		diastolic_evaluation = "normal";
	}
	else if (diastolic_reading < 90) {
		diastolic_evaluation = "high normal";
	}
	else if (diastolic_reading < 100) {
		diastolic_evaluation = "Stage 1 Hypertension";
	}
	else if (diastolic_reading < 110) {
		diastolic_evaluation = "Stage 2 Hypertension";
	}
	else{
		diastolic_evaluation = "Stage 3 Hypertension";
	}
	cout << '\t' << "Diastolic reading is " << diastolic_evaluation << endl << endl;
	return;
}

void heading()
{
	cout << "***********************************************************" << endl;     //Header Function for my output
	cout << "Chijioke E Kamanu" << endl;
	cout << "@02840667" << endl;
	cout << "March 26, 2018" << endl;
	cout << "Lab 8" << endl;
	cout << "Program to display data from patient file" << endl;
	cout << "***********************************************************" << endl;
}
