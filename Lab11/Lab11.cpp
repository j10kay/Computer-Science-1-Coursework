#include <iostream> 
#include <fstream> 
#include <string>
#include <iomanip>

using namespace std;
void heading();

int main()
{
	heading();
	string first_name;
	string last_name;
	int num_classes;
	string course_id;
	ifstream myfile;

	myfile.open("infile.txt");
	myfile >> first_name >> last_name;  //Priming Read

	while (!myfile.eof())            //Termination Test
	{ 
		myfile >> num_classes;
		int cnt;
		cout << first_name << " " << last_name << endl;
		for (cnt = 0; cnt < num_classes; cnt++)   //Initialize Inner Loop
		{ 
			myfile >> course_id;
			cout << '\t' << course_id << endl;
		}
		cout << "Number of classes: " << num_classes << endl;
		cout << "--------------------------------------------------------------------" << endl << endl;
	myfile >> first_name >> last_name;    //Read next record
	}
	system("pause");
	return 0;                //Return 0 if all executes as planned
}

void heading() {                       //Header Function for my output
	cout << "******************************************************************" << endl;
	cout << "Chijioke Enyinnaya Kamanu" << endl;
	cout << "Student ID: @02840667" << endl;
	cout << "Program to register for classes" << endl;
	cout << "March 19, 2018" << endl;
	cout << "******************************************************************" << endl;
	return;
}
