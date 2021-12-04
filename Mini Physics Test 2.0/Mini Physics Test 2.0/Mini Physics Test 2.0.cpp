#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>

using namespace std;

void StartOfProgram();
void EndOfProgram();
void Question1();
void Question2();
void Question3();
void Question4();
void Question5();
void Question6();
void Question7();
void Question8();
void Question9();
void Question10();
void Question11();
void Question12();
void Question13();
void Question14();
void Question15();
void ChooseNextQuestion();
void Reatempt(string retry, int quest);

int points = 0;
int QuestionsCounter = 0;
int QuestionsOrder[16];
int Question;

void EndOfProgram()
{
	if (QuestionsCounter >= 10)
	{
		cout << "Congratualation! You finished the test \n";
		cout << "Score: " << points << "\n";
		cout << "When you are ready to go back press \"Entet\" \n";
		points = 0;
		QuestionsCounter = 0;
		system("pause");
		StartOfProgram();
	}
}

void StartOfProgram()
{
	srand(time(NULL));
	system("CLS");
	//makes random choose diferent number everytime
	//this is a mini physics test with random variants

	cout << "Welcome to the mini physics test \n";
	cout << "When you are ready to start press \"Entet\" \n";
	system("pause");

	int testVariant = rand() % 14 + 0;

	switch (testVariant)
	{
	case 1:
		Question1();
	case 2:
		Question2();
	case 3:
		Question3();
	case 4:
		Question4();
	case 5:
		Question5();
	case 6:
		Question6();
	case 7:
		Question7();
	case 8:
		Question8();
	case 9:
		Question9();
	case 10:
		Question10();
	case 11:
		Question11();
	case 12:
		Question12();
	case 13:
		Question13();
	case 14:
		Question14();
	case 15:
		Question15();
	}
}

void ChooseNextQuestion()
{
	int choose = rand() % 14 + 0;

	//Checking if the question has been asked before
	for (int i = 0; i < QuestionsCounter; i++)
	{
		if (QuestionsOrder[i] == choose)
		{
			choose = rand() % 14 + 0;
			i = -1;
		}
	}
	QuestionsCounter++;
	QuestionsOrder[QuestionsCounter] = choose;

	switch (choose)
	{
	case 1:
		Question1();
	case 2:
		Question2();
	case 3:
		Question3();
	case 4:
		Question4();
	case 5:
		Question5();
	case 6:
		Question6();
	case 7:
		Question7();
	case 8:
		Question8();
	case 9:
		Question9();
	case 10:
		Question10();
	case 11:
		Question11();
	case 12:
		Question12();
	case 13:
		Question13();
	case 14:
		Question14();
	case 15:
		Question15();
	}
}

void Reatempt(string retry, int quest)
{
	string r = retry;
	int q = quest;
	if (retry == "YES")
	{
		switch (quest)
		{
		case 1:
			Question1();
		case 2:
			Question2();
		case 3:
			Question3();
		case 4:
			Question4();
		case 5:
			Question5();
		case 6:
			Question6();
		case 7:
			Question7();
		case 8:
			Question8();
		case 9:
			Question9();
		case 10:
			Question10();
		case 11:
			Question11();
		case 12:
			Question12();
		case 13:
			Question13();
		case 14:
			Question14();
		case 15:
			Question15();
		}
	}
	else if (retry == "NO")
	{
		int choose = rand() % 15 + 1;

		//Checking if the question has been asked before
		for (int i = 0; i < QuestionsCounter; i++)
		{
			if (QuestionsOrder[i] == choose)
			{
				choose = rand() % 15 + 1;
				i = -1;
			}
		}
		QuestionsCounter++;
		QuestionsOrder[QuestionsCounter] = choose;

		switch (choose)
		{
		case 1:
			Question1();
		case 2:
			Question2();
		case 3:
			Question3();
		case 4:
			Question4();
		case 5:
			Question5();
		case 6:
			Question6();
		case 7:
			Question7();
		case 8:
			Question8();
		case 9:
			Question9();
		case 10:
			Question10();
		case 11:
			Question11();
		case 12:
			Question12();
		case 13:
			Question13();
		case 14:
			Question14();
		case 15:
			Question15();
		}
	}
	else
	{
		cout << "Please enter YES or NO";
		Reatempt(r, q);
	}
}

void Question1()
{
	//In these question you have to enter the answer;
	Question = 1;
	system("CLS");

	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "Compared to thin wires, electrical resistance in thick wires is \n";
	cout << "(Answer only with a number)  \n";
	int /*string*/ answer = 4 /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	cout << "\n";
	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question2()
{
	//in these questions you will have to answer with true or false

	Question = 2;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "A closed circuit is a circuit in which charge can flow.\n";
	cout << "True of False: ";
	string answer = "True";
	string InputAnswer; //basiacally input True or False
	cin >> InputAnswer;
	cout << "\n";

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question3()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 3;
	system("CLS");

	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "Electrical resistance in a wire depends on the wire's\n";
	cout << "A) thickness. \nB) conductivity. \nC) length. \nD) all of the above \n";
	char answer = 'D';
	char InputAnswer;
	cin >> InputAnswer;

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question4()
{
	//In these question you have to enter the answer;

	Question = 4;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "The resistance of your dry skin is usually around \n";
	cout << "(Answer only with a number) \n";
	int /*string*/ answer = 100000  /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	cout << "\n";
	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question5()
{
	//in these questions you will have to answer with true or false

	Question = 5;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "While you are standing on the ground in your running shoes, the greatest resistance between you and the ground is in the running shoes.\n";
	cout << "True or False: ";
	string answer = "True";
	string InputAnswer; //basiacally input True or False
	cin >> InputAnswer;
	cout << "\n";

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question6()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 6;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "The primary reason a bird can perch harmlessly on bare high voltage wires is that \n";
	cout << "A) a bird's feet are close together. \nB) a bird has a very large electrical resistance. \nC) there is no potential difference across the bird's feet. \nD) all of the above \n";
	char answer = 'C';
	char InputAnswer;
	cin >> InputAnswer;

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question7()
{
	//In these question you have to enter the answer;

	Question = 7;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "The current through a 5-ohm resistor connected to a 150-V power supply is \n";
	cout << "(Answer only with a number) \n";
	int /*string*/ answer = 30  /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question8()
{
	//in these questions you will have to answer with true or false

	Question = 8;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "If you plug an electric toaster rated at 110 V into a 220-V outlet, current in the toaster will be more than twice what it should be.\n";
	cout << "True of False: ";
	string answer = "False";
	string InputAnswer; //basiacally input True or False
	cin >> InputAnswer;
	cout << "\n";

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question9()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 9;
	system("CLS");;
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "Electric power is defined as:\n";
	cout << "A) current times voltage.\nB) current divided by voltage.\nC) current times resistance.\nD) resistance times voltage. \n";
	char answer = 'A';
	char InputAnswer;
	cin >> InputAnswer;

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question10()
{
	//In these question you have to enter the answer;

	Question = 10;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "If you accidentally grabbed the prongs of a partially plugged-in 120-V electrical plug on a day when your skin resistance was 130, 000 ohms, how much current would pass through your body?\n";
	cout << "(Answer only with a number)  \n";
	double /*string*/ answer = 0.0009  /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	cout << "\n";
	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question11()
{
	//in these questions you will have to answer with true or false

	Question = 11;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "In solid conductors, electric current is the flow of positive and negative charges. \n";
	cout << "True of False: ";
	string answer = "False";
	string InputAnswer; //basiacally input True or False
	cin >> InputAnswer;
	cout << "\n";

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question12()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 12;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "When one light bulb in a parallel circuit containing several light bulbs burns out, the other light bulbs\n";
	cout << "A) do not burn at all. \nB) burn brighter. \nC) burn the same as before. \nD) None of above \n";
	char answer = 'C';
	char InputAnswer;
	cin >> InputAnswer;

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question13()
{
	//In these question you have to enter the answer;

	Question = 13;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "The total resistance of a 10-ohm resistor and a 7-ohm resistor in series is\n";
	cout << "(Answer only with a number)  \n";
	int /*string*/ answer = 17 /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	cout << "\n";

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question14()
{
	//in these questions you will have to answer with true or false

	Question = 14;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "Compared to the filament thickness on a 60-W light bulb, the filament thickness of a 100-W light bulb will greater \n";
	cout << "True of False: ";
	string answer = "True";
	string InputAnswer; //basiacally input True or False
	cin >> InputAnswer;
	cout << "\n";

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

void Question15()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 15;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfProgram();
	}
	cout << "In order for current to flow in a circuit, you must have \n";
	cout << "A) a switch that is open. \nB) complete path for the current \nC) two light bulbs in parallel. \nD) two light bulbs in series. \n";
	char answer = 'B';
	char InputAnswer;
	cin >> InputAnswer;

	if (answer == InputAnswer)
	{
		cout << "Good Joob +1 Points";
		points++;
		system("pause");
		int choose = rand() % 14 + 0;

		ChooseNextQuestion();
	}
	else
	{
		cout << "Ah mate got that one wrong \n";
		cout << "want to try this question again \n";
		cout << "(*Note:* use caps) \n";
		cout << "YES NO: ";
		string retry;
		cin >> retry;

		Reatempt(retry, Question);
	}
}

int main()
{
	StartOfProgram();
	return 0;
}
