// Program counts frequency of each alphabetic 
//   character in text file.

#include <fstream>
#include <iostream>
#include <cctype>
#include <iomanip>

const int SIZE = 91;
void PrintOccurrences(const  int[], float[]); // Prototype 

using  namespace  std;
int  main()
{
	ifstream dataFile;
	int  freqCount[SIZE];
	char ch;
	char index;
	float percentageDistribution[SIZE];

	dataFile.open("infile.txt");  // Open 
	if (!dataFile)                // Verify success
	{
		cout << "CAN’T OPEN INPUT FILE!" << endl;
		return  1;
	}
	for (int m = 0; m < SIZE; m++) { // Zero array 
		freqCount[m] = 0;
		percentageDistribution[m] = 0.0;
		// Read file one character at a time
	}
	
	dataFile.get(ch);     // Priming read
	while (dataFile)	  // While read successful
	{
		if (isalpha(ch))
		{
			if (islower(ch))
				ch = toupper(ch);

			freqCount[ch] = freqCount[ch] + 1;
		}
		dataFile.get(ch); // Get next character
	}
	PrintOccurrences(freqCount, percentageDistribution);
	system("pause");
	return  0;
}
void PrintOccurrences(
	/* in */ const int  freqCount[], float percentageDistribution[])
	// Prints each alphabet character and its frequency
	// Precondition:
	//	freqCount[‘A’ . . ‘Z’] are assigned
	// Postcondition:
	//	freqCount[‘A’ . . ‘Z’] have been printed
{
	char  index;
	cout << "File contained" << endl;
	cout << "LETTER      OCCURRENCES     PERCENTAGE DISTRIBUTION" << endl;
	int count = 0;

	for (index = 'A'; index <= 'Z'; index++) {
		count += freqCount[index];
	}

	for (index = 'A'; index <= 'Z'; index++) {
		percentageDistribution[index] = (float(freqCount[index]) / count) * 100;
	}

	cout << fixed << showpoint;
	for (index = 'A'; index <= 'Z'; index++) {
		cout << setw(4) << index << setw(10)
			 << freqCount[index] << setw(25) << setprecision(2) << percentageDistribution[index] << "%" << endl;
	}
}
