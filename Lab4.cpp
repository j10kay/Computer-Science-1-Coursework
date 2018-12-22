#include <iostream>
using namespace std;

int main() {
	int score;
	cin >> score;
	if (score > 100) {
		cout << "Duffer.";
	}

	else if (score <= 100 && score> 80) {
		cout << "Weekend regular.";
	}
	else if (score <= 80 && score> 72) {
		cout << "Competitive player.";
	}
	else if (score <= 72 && score> 68) {
		cout << "Turn pro!";
	}
	else if (score <= 68) {
		cout << "Time to go on tour!";
	}
	system("pause");
	return 0;
}
