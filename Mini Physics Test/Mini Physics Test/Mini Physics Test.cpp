//code made by ShadowCode007
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>

using namespace std;
void StartOfProgram();
void Question1();
void Question2();
void Question3();

int points = 0;
int questionCounter = 0;

bool EndOfProgrm()
{
	if (questionCounter >= 10)
	{
		cout << "Congratualation! You finished the test \n";
		cout << "Score: " << questionCounter;
		system("pause");
		return false;
	}
}

void StartOfProgram()
{
	srand(time(NULL));
	//makes random choose diferent number everytime
	//this is a mini physics test with random variants

	cout << "Welcome to the mini physics test \n";
	cout << "When you are ready to start press \"Entet\" \n";
	system("pause");

	int testVariant = rand() % 3 + 1;

	switch (testVariant)
	{
	case 1:
		Question1();
	case 2:
		Question2();
	case 3:
		Question3();
	}
}

void Question1()
{
	//In these question you have to enter the answer;

	system("CLS");
	cout << "Question \n";
	int /*string*/ answer = 0 /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	'\n';
	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points \n";
		points++;
		system("pause");
		int choose = rand() % 3 + 1;
		switch (choose)
		{
		case 1:
			questionCounter++;
			Question2();
		case 2:
			questionCounter++;
			Question3();
		}
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "YES NO:";
		string retry;
		cin >> retry;

		if (retry == "YES")
		{
			Question1();
		}
		else
		{
			int choose = rand() % 3 + 1;

			switch (choose)
			{
			case 1:
				questionCounter++;
				Question2();
			case 2:
				questionCounter++;
				Question3();
			}
		}
	}
}

void Question2()
{
	//in these questions you will have to answer with true or false

	system("CLS");
	cout << "Question \n";
	cout << "True of False:";
	string answer = "Answer";
	string InputAnswer; //basiacally input True or False
	cin >> InputAnswer;
	'\n';

	if (answer == InputAnswer)
	{
		cout << "Good Job +1 Points \n";
		points++;
		system("pause");
		int choose = rand() % 3 + 1;

		switch (choose)
		{
		case 1:
			questionCounter++;
			Question1();
		case 2:
			questionCounter++;
			Question3();
		}
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "YES NO:";
		string retry;
		cin >> retry;

		if (retry == "YES")
		{
			Question2();
		}
		else
		{
			int choose = rand() % 1 + 3;

			switch (choose)
			{
			case 1:
				questionCounter++;
				Question1();
			case 2:
				questionCounter++;
				Question3();
			}
		}
	}
}

void Question3()
{
	//in these questions you wil have to answer with a,b,c,d

	system("CLS");
	cout << "A) Answer \nB) Answer \nC) Answer \nD) Answer \n";
	char answer = 'A';
	char InputAnswer;
	cin >> InputAnswer;

	if (answer == InputAnswer)
	{
		cout << "Good Job +1 Points \n";
		points++;
		system("pause");
		int choose = rand() % 1 + 3;

		switch (choose)
		{
		case 1:
			questionCounter++;
			Question1();
		case 2:
			questionCounter++;
			Question2();
		}
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "YES NO:";
		string retry;
		cin >> retry;

		if (retry == "YES")
		{
			Question3();
		}
		else
		{
			int choose = rand() % 1 + 3;

			switch (choose)
			{
			case 1:
				questionCounter++;
				Question1();
			case 2:
				questionCounter++;
				Question2();
			}
		}
	}
}

int main()
{
	StartOfProgram();
	return 0;
}