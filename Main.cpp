/*
Brett Allen
Stephen Eide
CMSY-141/181
10/12/2015

This program is designed to receive input from a text file containing student names and class averages.
First this program will determine each students' letter grade and it will compute the highest and lowest grades.
Finally the program will determine the entire class' average and display everything to the console.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Prototypes
void highestGrade(string name[], double classAvg[], int size);
void lowestGrade(string name[], double classAvg[], int size);
void classAverage(double classAvg[], int size);
void letterGrade(string name[], double classAvg[], char letterGrade[], int size);

const int SIZE = 30;

int main()
{
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

void classAverage(double classAvg[], int size)
{
	double sum = 0.0;
	double avg = 0.0;

	for (int i = 0; i < size; i++)
	{
		sum += classAvg[i];
	}

	cout << "The class average is a " << fixed << setprecision(1) << sum / size << "%\n";
}

void letterGrade(string name[], double classAvg[], char letterGrade[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (classAvg[i] >= 89.5 && classAvg[i] <= 100)
		{
			cout << name[i] << " has a(n) " << letterGrade[0] << " at a " <<
				classAvg[i] << "%\n\n"; //Student has an 'A'
		}
		else if (classAvg[i] >= 79.5)
		{
			cout << name[i] << " has a(n) " << letterGrade[1] << " at a " <<
				classAvg[i] << "%\n\n"; //Student has a 'B'
		}
		else if (classAvg[i] >= 69.5)
		{
			cout << name[i] << " has a(n) " << letterGrade[2] << " at a " <<
				classAvg[i] << "%\n\n"; //Student has a 'C'
		}
		else if (classAvg[i] >= 59.5)
		{
			cout << name[i] << " has a(n) " << letterGrade[3] << " at a " <<
				classAvg[i] << "%\n\n"; //Student has a 'D'
		}
		else if (classAvg[i] >= 0)
		{
			cout << name[i] << " has a(n) " << letterGrade[4] << " at a " <<
				classAvg[i] << "%\n\n"; //Student has an 'E'
		}
	}
}
