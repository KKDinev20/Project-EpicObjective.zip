#include <iostream>
#include <io.h>
#include <stdio.h>

using namespace std;
void StartOfProgram();
void Formulas();
void Convertion();

void StartOfProgram()
{
	//clears console
	system("CLS");

	cout << "Physics Calculator \n";
	cout << "Choose between formulas(1) and convertion(2) \n";
	cout << "Enter 1 for the formulas and 2 for the convertion: ";
	int chooseFC;
	cin >> chooseFC;

	switch (chooseFC)
	{
	case 1:
		void Formulas();
	case 2:
		Convertion();
	default:
		cout << "Please enter 1 or 2 \n";
		system("pause");
		StartOfProgram();
	}
}

void Formulas()
{
	system("CLS");
	cout << "Choose a formulas between:\n";
	cout << "1. Calculate Speed\n";
	cout << "2. Calculate Pressure\n";
	cout << "3. Calculate Density\n";
	cout << "4. Calculate Kinetic\n";
	cout << "5. Calculate Force\n";
	cout << "6. Return to begining\n";

	cout << "Enter a number (between 1 and 6): ";
	int chooseCalculation;
	cin >> chooseCalculation;

	double RoadLength, TravelTime, Force, Area, Mass, Volume, Acceleration, Velocity;
	switch (chooseCalculation)
	{
	case 1:
		system("CLS");

		cout << "Enter the length of the road: ";
		cin >> RoadLength;
		'\n';
		cout << "Enter the travel time: ";
		cin >> TravelTime;
		'\n';
		cout << RoadLength / TravelTime << endl;
		system("pause");

		Formulas();
	case 2:
		system("CLS");

		cout << "Enter the force: ";
		cin >> Force;
		'\n';
		cout << "Enter the area: ";
		cin >> Area;
		'\n';
		cout << Force / Area << endl;
		system("pause");

		Formulas();
	case 3:
		system("CLS");

		cout << "Enter the force: ";
		cin >> Mass;
		'\n';
		cout << "Enter the volume: ";
		cin >> Volume;
		'\n';
		cout << Mass / Volume << endl;
		system("pause");

		Formulas();
	case 4:
		system("CLS");

		cout << "Enter the mass of the body: ";
		cin >> Mass;
		cout << '\n';
		cout << "Enter the velocity with which the body is traveling: ";
		cin >> Velocity;
		cout << '\n';
		cout << Mass / Velocity;
		system("pause");

		Formulas();
	case 5:
		system("CLS");

		cout << "Enter the mass of the body: ";
		cin >> Mass;
		cout << '\n';
		cout << "Enter the acceleration in velocity available: ";
		cin >> Acceleration;
		cout << '\n';
		cout << Mass / Acceleration;
		system("pause");

		Formulas();
	case 6:

	default:
		cout << "Please choose a valid number";
		system("pause");
		Formulas();
	}
}

void Convertion()
{
	system("CLS");
	cout << "Choose a convertion between:\n";
	cout << "1. k/h to m/s\n";
	cout << "2. m/s to k/h\n";
	cout << "3. minutes to hours\n";
	cout << "4. hours to minutes\n";
	cout << "5. minutes to seconds\n";
	cout << "6. seconds to minutes\n";
	cout << "7. kilograms to grams\n";
	cout << "8. grams to kilograms\n";
	cout << "9. grams to milligrams\n";
	cout << "10. milligrams to grams\n";
	cout << "11. cm to m\n";
	cout << "12. cm to km\n";
	cout << "13. m to cm\n";
	cout << "14. m to km\n";
	cout << "15. km to cm\n";
	cout << "16. km to m\n"; 
	cout << "17. Retrun to start";

	cout << "Enter a number (between 1 and 11): ";
	int chooseConvertion;
	cin >> chooseConvertion;

	double VarToBeConverted;

	switch (chooseConvertion)
	{
	case 1:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 0.277777778 << " m/s";
		system("pause");
		Convertion();
	case 2:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 0.277777778 << " k/h;";
		system("pause");
		Convertion();
	case 3:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 60 << "min";
		system("pause");
		Convertion();
	case 4:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 60 << "hours";
		system("pause");
		Convertion();
	case 5:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 60 << "seconds";
		system("pause");
		Convertion();
	case 6:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 60 << "min";
		system("pause");
		Convertion();
	case 7:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 60 << "hours";
		system("pause");
		Convertion();
	case 8:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 1000 << " kilograms";
		system("pause");
		Convertion();
	case 9:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 1000 << " milligrams";
		system("pause");
		Convertion();
	case 10:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 1000 << " grams";
		system("pause");
		Convertion();
	case 11:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 100 << "m";
		system("pause");
		Convertion();
	case 12:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 1000000 << "km";
		system("pause");
		Convertion();
	case 13:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 100 << "cm";
		system("pause");
		Convertion();
	case 14:
		cin >> VarToBeConverted;
		cout << VarToBeConverted / 1000 << "km";
		system("pause");
		Convertion();
	case 15:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 1000000 << "cm";
		system("pause");
		Convertion();
	case 16:
		cin >> VarToBeConverted;
		cout << VarToBeConverted * 1000 << "m";
		system("pause");
		Convertion();
	case 17:
		StartOfProgram();
	default:
		cout << "Please enter a valid number \n";
		system("pause");
		Convertion();
	}
}

int main()
{
	StartOfProgram();
	return 0;
}
