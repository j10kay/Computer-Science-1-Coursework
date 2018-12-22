#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void get_tutor_data(ifstream&, string[], int[][13]); 
string lookup_tutors(string[], int[][13], string);
void display_tutor_list(string);

int main()
{
	ifstream myfile;
	myfile.open("infile.txt");
	string user_topic;
	string tutor_name_array[7];
	int tutoring_array[7][13];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 13; j++) {
			tutoring_array[i][j] = 0;
		}
	}
	get_tutor_data(myfile, tutor_name_array, tutoring_array);
	char user_choice = 'Y';
	do {
		cout << "Enter a topic you wish to be tutored in: ";
		cin >> user_topic;
		string eligible_tutors;
		eligible_tutors = lookup_tutors(tutor_name_array, tutoring_array, user_topic);
		display_tutor_list(eligible_tutors);
		cout << "Do you wish to look up another topic?";
		cin >> user_choice;
	} while (user_choice == 'Y');
	return 0;
}

void get_tutor_data(ifstream& myfile, string tutor_names[], int tutoring_array[][13]) {
	string first_name, last_name, selected_topic;
	int num_of_topics;
	for (int i = 0; i < 7; i++) {
		myfile >> first_name >> last_name >> num_of_topics;
		tutor_names[i] = (first_name + " " + last_name);
		for (int j = 0; j < num_of_topics; j++) {
			myfile >> selected_topic;
			if (selected_topic == "structs") {
				tutoring_array[i][0] = 1;
			}
			else if (selected_topic == "functions") {
				tutoring_array[i][1] = 1;
			}
			else if (selected_topic == "conditions") {
				tutoring_array[i][2] = 1;
			}
			else if (selected_topic == "expressions") {
				tutoring_array[i][3] = 1;
			}
			else if (selected_topic == "if_statements") {
				tutoring_array[i][4] = 1;
			}
			else if (selected_topic == "switch_stataments") {
				tutoring_array[i][5] = 1;
			}
			else if (selected_topic == "parameters") {
				tutoring_array[i][6] = 1;
			}
			else if (selected_topic == "strings") {
				tutoring_array[i][7] = 1;
			}
			else if (selected_topic == "for_loops") {
				tutoring_array[i][8] = 1;
			}
			else if (selected_topic == "input_output") {
				tutoring_array[i][9] = 1;
			}
			else if (selected_topic == "coercion") {
				tutoring_array[i][10] = 1;
			}
			else if (selected_topic == "casting") {
				tutoring_array[i][11] = 1;
			}
			else if (selected_topic == "debugging") {
				tutoring_array[i][12] = 1;
			}
		}
	}
}

string lookup_tutors(string tutor_names[], int tutoring_array[][13], string selected_topic) {
	string eligible_tutors = "";
	int col_variable;
		if (selected_topic == "structs") {
			col_variable = 0;
		}
		else if (selected_topic == "functions") {
			col_variable = 1;
		}
		else if (selected_topic == "conditions") {
			col_variable = 2;
		}
		else if (selected_topic == "expressions") {
			col_variable = 3;
		}
		else if (selected_topic == "if_statements") {
			col_variable = 4;
		}
		else if (selected_topic == "switch_stataments") {
			col_variable = 5;
		}
		else if (selected_topic == "parameters") {
			col_variable = 6;
		}
		else if (selected_topic == "strings") {
			col_variable = 7;
		}
		else if (selected_topic == "for_loops") {
			col_variable = 8;
		}
		else if (selected_topic == "input_output") {
			col_variable = 9;
		}
		else if (selected_topic == "coercion") {
			col_variable = 10;
		}
		else if (selected_topic == "casting") {
			col_variable = 11;
		}
		else if (selected_topic == "debugging") {
			col_variable = 12;
		}

	for (int i = 0; i < 7; i++) {
		if (tutoring_array[i][col_variable] == 1) {
			eligible_tutors += (tutor_names[i] + " ");
		}
	}
	return eligible_tutors;
}

void display_tutor_list(string eligible_tutors) {
	cout << "You can choose your tutor from this list: " << eligible_tutors << endl;
}
