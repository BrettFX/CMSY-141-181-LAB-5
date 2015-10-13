/*
This program is designed to receive input from a text file containing student names and class averages.
First this program will determine each students' letter grade and it will compute the highest and lowest grades.
Finally the program will determine the entire class' average and display everything to the console.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Constants
const int SIZE = 30;

//Prototypes
void highestGrade(string name[], double classAvg[], int size);
void lowestGrade(string name[], double classAvg[], int size);
void classAverage(double classAvg[], int size);
void letterGrade(string name[], double classAvg[], char letterGrade[], int size);
void showStudents(int tally[], string marker[][SIZE], char letterGrade[]);

int main()
{
	//Setting color scheme to white on black for readability
	system("color F0");

	ifstream inputFile;
	inputFile.open("lab5.txt");	

	string name[SIZE];
	double classAvg[SIZE];
	char grade[] = { 'A', 'B', 'C', 'D', 'F' };	

	//Reading data
	while (!inputFile.eof())
	{
		//Creating the name and classAvg arrays as parallel arrays
		for (int i = 0; i < SIZE; i++)
		{
			inputFile >> name[i] >> classAvg[i];					
		}
	}

	letterGrade(name, classAvg, grade, SIZE);
	highestGrade(name, classAvg, SIZE);
	cout << endl;
	lowestGrade(name, classAvg, SIZE);
	cout << endl;
	classAverage(classAvg, SIZE);
	cout << endl;

	inputFile.close();
	cout << "Done. \a";
	system("pause");
	return 0;
}

//Function Definitions

//Searching the parallel arrays name and classAvg for the student w/highest average
void highestGrade(string name[], double classAvg[], int size)
{
	double hGrade = classAvg[0];
	string hName = "";

	for (int i = 0; i < size; i++)
	{
		//Step through both arrays in a parallel manor
		if (classAvg[i] > hGrade)
		{
			hGrade = classAvg[i];
			hName = name[i];
		}
	}
	cout << hName << " has the highest class average with a " << hGrade  << "%" << endl;
}

//Searching the parallel arrays name and classAvg for the student w/lowest average
void lowestGrade(string name[], double classAvg[], int size)
{
	double lGrade = classAvg[0];
	string lName = "";

	for (int i = 0; i < size; i++)
	{
		//Step through both arrays in a parallel manor again
		if (classAvg[i] < lGrade)
		{
			lGrade = classAvg[i];
			lName = name[i];
		}
	}
	cout << lName << " has the lowest class average with a " << lGrade << "%" << endl;
}

//Using the classAvg array and its size to determine the entire class average
void classAverage(double classAvg[], int size)
{
	double sum = 0.0;
	double avg = 0.0;

	for (int i = 0; i < size; i++)
	{
		sum += classAvg[i];
	}

	cout << "Overall, the entire class average is a " << fixed << setprecision(1) << sum / size << "%\n";
}

//Determining how many students received each letter grade and naming each student that has
//each letter grade
void letterGrade(string name[], double classAvg[], char letterGrade[], int size)
{
	int tally[] = { 0, 0, 0, 0, 0 };	
	string marker[5][SIZE];

	//Determining letter grade based on student average
	for (int i = 0; i < size; i++)
	{
		if (classAvg[i] >= 89.5 && classAvg[i] <= 100)
		{			
			marker[0][tally[0]] = name[i];
			tally[0]++;
		}
		else if (classAvg[i] >= 79.5)
		{			
			marker[1][tally[1]] = name[i];
			tally[1]++;
		}
		else if (classAvg[i] >= 69.5)
		{
			marker[2][tally[2]] = name[i];
			tally[2]++;
		}
		else if (classAvg[i] >= 59.5)
		{
			marker[3][tally[3]] = name[i];
			tally[3]++;
		}
		else if (classAvg[i] >= 0)
		{
			marker[4][tally[4]] = name[i];
			tally[4]++;
		}
	}

	showStudents(tally, marker, letterGrade);	
}

//Displaying how man students have each individual letter grade along with a list
//of coinciding names
void showStudents(int tally[], string marker[][SIZE], char letterGrade[])
{
	for (int row = 0; row < 5; row++)
	{		
		cout << tally[row] << " students have " << letterGrade[row] << "\'s. They are:\n";

		for (int col = 0; col < SIZE; col++)
		{
			if (marker[row][col] != "")
			{
				cout << "\t" << marker[row][col] << endl;
			}
			else
			{
				//Terminating loop once a blank element is found in the 2D marker array 
				cout << endl;
				break;
			}
		}
	}
}
