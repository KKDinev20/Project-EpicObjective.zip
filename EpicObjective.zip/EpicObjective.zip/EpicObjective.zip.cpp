#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <random>
#include <iomanip>
#include <time.h>
#include <limits>

#define elif else if
#undef max

using namespace std;
using namespace std::this_thread; //allows the usage of "sleep_for" function
using namespace std::chrono_literals; //allows the use of ns, us, ms, s, h, etc.

void Menu();

void CalculatorMenu();
void Formulas();
void Convertion();

void Adventure();
void AdventureSetup();
void Border();
void PlayerInput();
void MovementNLogic();
void Missions();
void MissionsActivate();
void PlanetSort();
void CalculateSpeed();
void Breakfast();
void WhatFloats();
void BossBattle();
void StartOfAdvebture();
void MakeCharacter();

void StartOfTest();
void EndOfTest();
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

void Menu()
{
	system("CLS");
	int choice;

	cout << "Welcome to the VR teacher made by \" EpicObjective.zip\"\n";
	cout << "Choose what you would like to do:\n";
	cout << "1. Calculations \n2. Test\n3. Adventure\n";
	cout << "Enter Calculations(1), Test(2) or Adventure(3)\n";
	cin >> choice;
	while (true)
	{
		if (cin.fail())
		{
			cout << "Enter a number between 1, 2 or 3\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin >> choice;
		}
		elif(!cin.fail())
		{
			if (choice == 1)
			{
				CalculatorMenu();
				break;
			}
			elif(choice == 2)
			{
				StartOfTest();
				break;
			}
			elif(choice == 3)
			{
				StartOfAdvebture();
				break;
			}
			else
			{
				cout << "Please enter 1, 2 or 3\n";
				cin.clear();
				cin >> choice;
			}
		}
	}
}

void CheckCinInt(int Info)
{
	while (true)
	{
		if (cin.fail())
		{
			cout << "Enter a number: ";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin >> Info;
		}
		elif(!cin.fail())
		{
			break;
		}
	}
}

void CheckCinDouble(double Info)
{
	while (true)
	{
		if (cin.fail())
		{
			cout << "Enter a number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> Info;
		}
		elif(!cin.fail())
		{
			break;
		}
	}
}

//Adventure code ↓
enum PlayerDirection { Still = 0, Left, Right, Up, Down };//user defined data type where we specify a set of values for a variable and the variable can only take one out of a small set of possible values
struct Player
{
	int X;
	int Y;
	int Power;
	int Health;
	PlayerDirection direction;
};

struct Boss
{
	int Power;
	int Health;
};

struct Help
{
	int HelpX;
	int HelpY;
};

struct Game
{
	int score = 0;
	const int gameWidth = 20;
	const int gameHeight = 20;
	bool GameOn = true;
};

Player player;
Help help;
Game game;
Boss boss;

bool PlanetSortRepeat = false;
bool WhatFloatsRepeat = false;
bool CalculateSpeedRepeat = false;
bool BreakfastRepeat = false;
char character;
string nickname;

void StartOfAdvebture()
{
	system("CLS");
	cout << "Hi there buddy!\n";
	cout << "There are 3 things you might need to know before starting the adventure:\n\n";
	cout << "1. Your answers will have an impact on the story\n";
	cout << "2.The maximum character you can use for the character is 1 \n";
	cout << "3. You will have fun while playing :D\n";
	cout << endl;
	cout << endl;
	cout << "And 5 more about the map:\n\n";
	cout << "1. You have to get to the H (it stands foe HELP) to start your mission\n";
	cout << "2. Use \"W\" to move forward\n";
	cout << "3. Use \"S\" to move backward\n";
	cout << "4. Use \"A\" to move leftward\n";
	cout << "5. Use \"D\" to move rightwards\n";
	cout << endl;
	cout << endl;
	cout << "When you are ready to start press \"Enter\" \n";
	system("pause");

	MakeCharacter();
}

void MakeCharacter()
{
	system("CLS");
	cout << "Enter a symbol to be your character:\n";
	cout << "(Note: It must be only ONE symbol)\n";
	cin >> character;
	cout << "Enter a nickname for it:\n";
	cin >> nickname;

	cout << "Are you sure that you want to keep " << character << " as your character and " << nickname << " as it`s nickname until the end of the story?\n";
	cout << "(YES OR NO)\n";
	string ConfirmName;
	cin >> ConfirmName;
	while (ConfirmName != "YES" && ConfirmName != "NO")
	{
		cout << "Please enter \"YES\" or \"NO\" as an answer\n";
		cin >> ConfirmName;
	}
	if (ConfirmName == "YES")
	{
		system("CLS");
		Adventure();
	}
	if (ConfirmName == "NO")
	{
		system("CLS");
		MakeCharacter();
	}
}

void Adventure()
{
	AdventureSetup();

	while (game.GameOn)
	{
		Border();//draws border
		PlayerInput();//checks for player input
		MovementNLogic();//Moves the player and stops you at the border
		MissionsActivate();//activates missions
		sleep_for(7ms);//sleep
	}

	system("CLS");
	if (boss.Health <= 0)
	{
		cout << "            |   _   _\n";
		cout << "      . | . x .|.|-|.|\n";
		cout << "   |\\ ./.\\-/.\\-|.|.|.|\n";
		cout << "~~~|.|_|.|_|.|.|.|_|.|~~~\n";
		cout << "YAY we saved the city";

		
	}
	elif(player.Health)
	{
		cout << "    .-\"\"\"\"\"\"-.\n";
		cout << "   .'          '.\n";
		cout << " /   O      O   \\\n";
		cout << " :           `    :\n";
		cout << " |                |\n";
		cout << " :    .------.    :\n";
		cout << "  \\  '        '  /\n";
		cout << "   '.          .'\n";
		cout << "     '-......-'\n";
		cout << "Oh no the whole city is destroyed";
	}

	int choice;
	cout << "What would you like to do now\n";
	cout << "Play again(1) or go back(2)\n";
	cin >> choice;
	while (true)
	{
		if (cin.fail())
		{
			cout << "Enter a number between 1 and 2\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin >> choice;
		}
		elif(!cin.fail())
		{
			if (choice == 1)
			{
				break;
			}
			elif(choice == 2)
			{
				Menu();
				break;
			}
			else
			{
				cout << "Please enter 1 or 2\n";
				cin.clear();
				cin >> choice;
			}
		}
	}
}

void AdventureSetup()
{
	srand(time(NULL));
	player.direction = Still;
	player.X = game.gameWidth / 2;
	player.Y = game.gameHeight / 2;
	player.Power = 5;
	player.Health = 100;
	boss.Power = 10;
	boss.Health = 100;
	help.HelpX = rand() % game.gameWidth;
	help.HelpY = rand() % game.gameHeight;
}

void setPosition(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}

void Border()
{
	setPosition(0, 0);
	for (int i = 0; i < game.gameWidth + 2; i++)
	{
		cout << "#";
	}

	cout << setfill(' ') << setw(60) << " ";
	cout << endl;

	for (int i = 0; i < game.gameHeight; i++)
	{
		for (int j = 0; j < game.gameWidth; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == player.Y && j == player.X)
			{
				cout << character;
			}
			elif(i == help.HelpY && j == help.HelpX)
			{
				cout << "H";
			}
			else
			{
				cout << " ";
			}
			if (j == game.gameWidth - 1)
			{
				cout << "#";
			}
		}
		cout << setfill(' ') << setw(60) << " ";
		cout << endl;
	}

	for (int i = 0; i < game.gameWidth + 2; i++)
	{
		cout << "#";
	}

	cout << "\n People helped: " << game.score;
}

void PlayerInput()
{
	if (_kbhit())//checks if keyboard is being pressed;
	{
		switch (_getch())//to hold the output screen for some time until the user passes a key from the keyboard to exit the console screen
		{
		case 'a':
			player.direction = Left;
			break;
		case 'd':
			player.direction = Right;
			break;
		case 's':
			player.direction = Down;
			break;
		case 'w':
			player.direction = Up;
			break;
		}
	}
}

void MovementNLogic()
{
	switch (player.direction)
	{
	case Left:
		player.X--;
		break;
	case Right:
		player.X++;
		break;
	case Up:
		player.Y--;
		break;
	case Down:
		player.Y++;
		break;
	default:
		break;
	}

	if (player.X >= game.gameWidth)
	{
		player.direction = Still;
		player.X -= 1;
	}
	elif(player.X < 0)
	{
		player.direction = Still;
		player.X += 1;
	}
	elif(player.Y < 0)
	{
		player.direction = Still;
		player.Y += 1;
	}
	elif(player.Y >= game.gameHeight)
	{
		player.direction = Still;
		player.Y -= 1;
	}
}

void Missions()
{
	system("CLS");
	int Mission = rand() % 4 + 1;

	switch (Mission)
	{
	case 1:
		if (PlanetSortRepeat == false)
		{
			PlanetSort();
			break;
		}
		else
		{
			Missions();
			PlanetSortRepeat = false;
		}
		break;
	case 2:
		if (WhatFloatsRepeat == false)
		{
			WhatFloats();
		}
		else
		{
			Missions();
			WhatFloatsRepeat = false;
		}
		break;
	case 3:
		if (CalculateSpeedRepeat == false)
		{
			CalculateSpeed();
		}
		else
		{
			Missions();
			CalculateSpeedRepeat = false;
		}
		break;
	case 4:
		if (BreakfastRepeat == false)
		{
			Breakfast();
		}
		else
		{
			BreakfastRepeat = false;
		}
		break;
	}
}

void MissionsActivate()
{
	if (player.X == help.HelpX && player.Y == help.HelpY)
	{
		help.HelpX = rand() % game.gameWidth;
		help.HelpY = rand() % game.gameHeight;

		Missions();
		player.direction = Still;
	}
}

void PlanetSort()
{
	system("CLS");
	cout << "Help the little boy to sort the planets \n";
	string Planets[100] = { "Saturn", "Venus", "Neptune", "Jupeter", "Mars", "Uranus", "Mercury", "Earth" };

	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << ". " << Planets[i] << endl;
	}
	system("pause");
	for (int tries = 0; tries < 8; tries++)
	{
		system("CLS");
		cout << "1." << Planets[0] << endl;
		cout << "2." << Planets[1] << endl;
		cout << "3." << Planets[2] << endl;
		cout << "4." << Planets[3] << endl;
		cout << "5." << Planets[4] << endl;
		cout << "6." << Planets[5] << endl;
		cout << "7." << Planets[6] << endl;
		cout << "8." << Planets[7] << endl;

		cout << "Which planets goes to " << tries + 1 << " place? \n";
		int Place;
		cin >> Place;
		CheckCinInt(Place);
		while (true)
		{
			if (Place <= 8)
			{
				swap(Planets[tries], Planets[Place - 1]);
				break;
			}
			else
			{
				cout << "Please enter a valid planet\n";
				cin >> Place;
				CheckCinInt(Place);
			}
		}

	}
	system("CLS");
	cout << "Let's see if the planets are on their place \n";
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << ". " << Planets[i] << endl;
	}
	int tempPoints = 0;
	if (Planets[0] == "Mercury")
	{
		tempPoints++;
	}
	if (Planets[1] == "Venus")
	{
		tempPoints++;
	}
	if (Planets[2] == "Earth")
	{
		tempPoints++;
	}
	if (Planets[3] == "Mars")
	{
		tempPoints++;
	}
	if (Planets[4] == "Jupiter")
	{
		tempPoints++;
	}
	if (Planets[5] == "Saturn")
	{
		tempPoints++;
	}
	if (Planets[6] == "Uranus")
	{
		tempPoints++;
	}
	if (Planets[7] == "Neptune")
	{
		tempPoints++;
	}

	if (tempPoints >= 6)
	{
		game.score++;
		cout << "Yay you helped to sort the planets! Good job " << nickname << "!";
	}
	else
	{
		cout << "Oh no you couldn't help";
	}

	PlanetSortRepeat = true;
	cout << "\nWhen you are ready press \"Enter\"";
	system("Pause");
}

void CalculateSpeed()
{
	system("CLS");
	setPosition(0, 0);

	cout << "Oh no that poor woman is going to be late for work \n";
	cout << "Let's use our super speed to help, but you will have to calculate it before we use it \n";
	int Time = 20; //20 minutes = 0.3hours
	int Distance = 30; //30km
	int Speed;
	cout << "She has " << Time << " minutes to go to work " << endl;
	cout << "And the distance we need to travel is " << Distance << endl;
	cout << "So, what should our speed be? \n";
	cin >> Speed;
	CheckCinInt(Speed);
	system("CLS");
	for (int i = 0; i < 30; i++)
	{
		cout << nickname << " is flying to woman's office" << endl;
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << character;
		//cout << character; 
		setPosition(0, 0);
		sleep_for(50ms);
		system("CLS");
	}

	if (Speed >= 100)
	{
		game.score++;
		cout << "Yay, she is there on time!\n";
		system("pause");
	}
	else
	{
		cout << "Ohh no!, she is late for work!\n";
		system("pause");
	}
	CalculateSpeedRepeat = true;
}

void Breakfast()
{
	system("CLS");
	cout << "There is one of your biggest fans AND HE OFFERS U FOOD!!!\n";
	cout << "Would you accept it?\n";
	cout << "(YES or NO)\n";

	string answer;
	while (answer != "YES" && answer != "NO")
	{
		cin >> answer;
		if (answer == "YES")
		{
			cout << "Yay! We you made him happy!\n";
			system("pause");
		}
		elif(answer == "NO")
		{
			cout << "AW, u made him sad.\n";
			system("pause");
		}
		else
		{
			cout << "Please enter with capital letters\n";
		}
	}
	BreakfastRepeat = true;

	if (game.score >= 3)
	{
		cout << "OHH NO!! Look out, there is a big monster over there?\n";
		cout << "Will you go and fight the boss?\n";

		string answer;
		while (answer != "YES" && answer != "NO")
		{
			cin >> answer;
			if (answer == "YES")
			{
				BossBattle();
			}
			elif(answer == "NO")
			{
				cout << "NOT SAVED\n";
			}
			else
			{
				cout << "Please enter with capital letters\n";
			}
		}
	}
}

void WhatFloats()
{
	system("CLS");
	int Choice;
	cout << "The old fisherman's boat is broken. He has a hole in his boat \n";
	cout << "There are three different materials \n";
	cout << "1. Wood\n2. Metal\n3. Aluminum\n";
	cout << "So what material should we use 1, 2 or 3\n";
	cin >> Choice;
	CheckCinInt(Choice);
	while (true)
	{
		if (Choice == 3)
		{
			game.score++;
			cout << "\nYay the boat is ready to go\n";
			break;
		}
		elif(Choice == 2 || Choice == 1)
		{
			cout << "\nOh no the boat sank\n";
			break;
		}
		else
		{
			cout << "\nPlease enter a valid number\n";
			cin >> Choice;
			CheckCinInt(Choice);
		}
	}

	WhatFloatsRepeat = true;
	cout << "\nWhen you are ready press \"Enter\"";
	system("Pause");
}

void BossBattle()
{
	system("CLS");
	player.Power *= game.score;

	int turn = 1;
	int PlayerSuperMoveCharge = 0;
	int BossSuperMoveCharge = 0;

	while (player.Health > 0 && boss.Health > 0)
	{
		system("CLS");

		cout << "Boss health: " << boss.Health << endl;
		cout << nickname << "'s health: " << player.Health << endl;

		if (turn % 2 != 0)
		{
			cout << "Your turn\n";
			cout << "1.Attack\n2.Heal\n3.Super Physics Power\n";

			int PlayerChoice;
			cin >> PlayerChoice;
			CheckCinInt(PlayerChoice);
			while (true)
			{
				if (PlayerChoice == 1)
				{
					boss.Health -= player.Power;
					PlayerSuperMoveCharge++;
					break;
				}
				elif(PlayerChoice == 2)
				{
					player.Health += 10;
					PlayerSuperMoveCharge++;
					break;
				}
				elif(PlayerChoice == 3)
				{
					if (PlayerSuperMoveCharge >= 3)
					{
						boss.Health -= (2 * player.Power);
						PlayerSuperMoveCharge = 0;
						break;
					}
					else
					{
						cout << "Super move not ready\n";
						sleep_for(1s);
						cin >> PlayerChoice;
					}
				}
				else
				{
					cout << "Enter a valid action\n";
					cin >> PlayerChoice;
				}
			}
		}
		else
		{
			cout << "Boss's turn...\n";
			sleep_for(2s);

			int BossChoice;
			BossChoice = rand() % 3 + 1;

			while (true)
			{
				if (BossChoice == 1)
				{
					player.Health -= boss.Power;
					BossSuperMoveCharge++;
					break;
				}
				elif(BossChoice == 2)
				{
					boss.Health += 15;
					BossSuperMoveCharge++;
					break;
				}
				elif(BossChoice == 3)
				{
					if (BossSuperMoveCharge >= 3)
					{
						player.Health -= (2 * boss.Power);
						BossSuperMoveCharge = 0;
						break;
					}
					else
					{
						BossChoice = rand() % 3 + 1;
					}
				}
			}
		}

		turn++;
	}

	game.GameOn = false;
}
//Adventure code ↑

//Calculator code ↓
void CalculatorMenu()
{
	//clears console
	system("CLS");

	cout << "Physics Calculator \n";
	cout << "Choose between formulas(1), convertion(2) and go back(3)\n";
	int chooseFC;
	cin >> chooseFC;

	while (true)
	{
		if (cin.fail())
		{
			cout << "Enter a number between 1, 2 and 3\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin >> chooseFC;
		}
		elif(!cin.fail())
		{
			if (chooseFC == 1)
			{
				Formulas();
				break;
			}
			elif(chooseFC == 2)
			{
				Convertion();
				break;
			}
			elif(chooseFC == 3)
			{
				Menu();
				break;
			}
			else
			{
				cout << "Please enter 1, 2 or 3\n";
				cin.clear();
				cin >> chooseFC;
			}
		}
	}
}

void Convertion()
{
	system("CLS");
	cout << "Choose a convertion between:\n";
	cout << "1. km/h to m/s\n";
	cout << "2. m/s to km/h\n";
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
	cout << "17. Retrun to start\n";

	cout << "Enter a number (between 1 and 17): ";

	while (true)
	{
		int chooseConvertion;
		cin >> chooseConvertion;
		CheckCinInt(chooseConvertion);
		double VarToBeConverted;
		switch (chooseConvertion)
		{
		case 1:
			cout << "Enter number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 0.277777778 << " m/s";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 2:
			cout << "Enter number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 0.277777778 << " k/h;";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 3:
			cout << "Enter number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 60 << " min";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 4:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 60 << " hours";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 5:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 60 << " seconds";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 6:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 60 << " min";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 7:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 60 << "hours";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 8:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 1000 << " kilograms";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 9:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 1000 << " milligrams";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 10:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 1000 << " grams";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 11:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 100 << "m";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 12:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 1000000 << "km";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 13:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 100 << "cm";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 14:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted / 1000 << "km";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 15:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 1000000 << "cm";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 16:
			cout << "Enter a number to convert: ";
			cin >> VarToBeConverted;
			CheckCinDouble(VarToBeConverted);
			cout << VarToBeConverted * 1000 << "m";
			cout << endl;
			system("pause");
			Convertion();
			break;
		case 17:
			CalculatorMenu();
			break;
		default:
			cout << "Please enter a valid number: ";
			break;
		}
	}

}

void Formulas()
{
	system("CLS");
	cout << "Choose a formula between:\n";
	cout << "1. Calculate Speed\n";
	cout << "2. Calculate Pressure\n";
	cout << "3. Calculate Density\n";
	cout << "4. Calculate Kinetic\n";
	cout << "5. Calculate Force\n";
	cout << "6. Return to begining\n";

	cout << "Enter a number (between 1 and 6): ";
	int chooseCalculation;
	cin >> chooseCalculation;
	CheckCinInt(chooseCalculation);
	double RoadLength, TravelTime, Force, Area, Mass, Volume, Acceleration, Velocity;
	switch (chooseCalculation)
	{
	case 1:
		system("CLS");

		cout << "Enter the length of the road: ";
		cin >> RoadLength;
		CheckCinDouble(RoadLength);
		'\n';
		cout << "Enter the travel time: ";
		cin >> TravelTime;
		CheckCinDouble(TravelTime);
		'\n';
		cout << RoadLength / TravelTime << endl;
		system("pause");

		Formulas();
		break;
	case 2:
		system("CLS");

		cout << "Enter the force: ";
		cin >> Force;
		CheckCinDouble(Force);
		'\n';
		cout << "Enter the area: ";
		cin >> Area;
		CheckCinDouble(Area);
		'\n';
		cout << Force / Area << endl;
		system("pause");

		Formulas();
		break;
	case 3:
		system("CLS");

		cout << "Enter the force: ";
		cin >> Mass;
		CheckCinDouble(Mass);
		'\n';
		cout << "Enter the volume: ";
		cin >> Volume;
		CheckCinDouble(Volume);
		'\n';
		cout << Mass / Volume << endl;
		system("pause");

		Formulas();
		break;
	case 4:
		system("CLS");

		cout << "Enter the Mass of the body: ";
		cin >> Mass;
		CheckCinDouble(Mass);
		cout << '\n';
		cout << "Enter the velocity with which the body is traveling: ";
		cin >> Velocity;
		CheckCinDouble(Velocity);
		cout << '\n';
		cout << Mass / Velocity;
		system("pause");

		Formulas();
		break;
	case 5:
		system("CLS");

		cout << "Enter the Mass of the body: ";
		cin >> Mass;
		CheckCinDouble(Mass);
		cout << '\n';
		cout << "Enter the Acceleration in velocity available: ";
		cin >> Acceleration;
		CheckCinDouble(Acceleration);
		cout << '\n';
		cout << Mass / Acceleration;
		system("pause");

		Formulas();
		break;
	case 6:
		CalculatorMenu();
		break;
	default:
		cout << "Please choose a valid number";
		system("pause");
		Formulas();
		break;
	}
}
//Calculator code ↑

//Test code ↓
int points = 0;
int QuestionsCounter = 0;
int QuestionsOrder[16];
int Question;

void EndOfTest()
{
	if (QuestionsCounter >= 10)
	{
		cout << "Congratualation! You finished the test \n";
		cout << "Correctly answered questions: " << points << "\n";
		cout << "Grade: " << points/10 *100 << "%" << "\n";
		cout << "When you are ready to go back press \"Enter\" \n";
		system("pause");
		points = 0;
		QuestionsCounter = 0;

		string TryAgain;
		cin >> TryAgain;
		while (TryAgain != "YES" && TryAgain != "NO")
		{
			cout << "Please enter \"YES\" or \"NO\" as an answer: ";
			cin >> TryAgain;
		}
		if (TryAgain == "YES")
		{
			system("CLS");
			StartOfTest();
		}
		if (TryAgain == "NO")
		{
			system("CLS");
			Menu();
		}
	}
}

void StartOfTest()
{
	srand(time(NULL));
	system("CLS");
	//makes random choose diferent number everytime
	//this is a mini physics test with random variants

	cout << "Welcome to the mini physics test \n";
	cout << "Do you want to start the test(1) or go back(2) \n";
	int choice;
	cin >> choice;

	while (true)
	{
		if (cin.fail())
		{
			cout << "Enter a number between 1 and 2\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin >> choice;
		}
		elif(!cin.fail())
		{
			if (choice == 1)
			{
				break;
			}
			elif(choice == 2)
			{
				Menu();
				break;
			}
			else
			{
				cout << "Please enter 1 or 2\n";
				cin.clear();
				cin >> choice;
			}
		}
	}
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

void Reattempt(string retry, int quest)
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
	elif(retry == "NO")
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
		cout << "Please enter YES or NO: ";
		cin >> retry;
		Reattempt(retry, q);
	}
}

void Question1()
{
	//In these question you have to enter the answer;
	Question = 1;
	system("CLS");

	if (QuestionsCounter >= 10)
	{
		EndOfTest();
	}
	cout << "Compared to thin wires, electrical resistance in thick wires is \n";
	cout << "(Answer only with a number)  \n";
	int /*string*/ answer = 4 /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	CheckCinInt(InputAnswer);
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

		Reattempt(retry, Question);
	}
}

void Question2()
{
	//in these questions you will have to answer with true or false

	Question = 2;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question3()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 3;
	system("CLS");

	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question4()
{
	//In these question you have to enter the answer;

	Question = 4;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
	}
	cout << "The resistance of your dry skin is usually around \n";
	cout << "(Answer only with a number) \n";
	int /*string*/ answer = 100000  /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	CheckCinInt(InputAnswer);
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

		Reattempt(retry, Question);
	}
}

void Question5()
{
	//in these questions you will have to answer with true or false

	Question = 5;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question6()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 6;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question7()
{
	//In these question you have to enter the answer;

	Question = 7;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
	}
	cout << "The current through a 5-ohm resistor connected to a 150-V power supply is \n";
	cout << "(Answer only with a number) \n";
	int /*string*/ answer = 30  /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	CheckCinInt(InputAnswer);
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

		Reattempt(retry, Question);
	}
}

void Question8()
{
	//in these questions you will have to answer with true or false

	Question = 8;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question9()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 9;
	system("CLS");;
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question10()
{
	//In these question you have to enter the answer;

	Question = 10;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
	}
	cout << "If you accidentally grabbed the prongs of a partially plugged-in 120-V electrical plug on a day when your skin resistance was 130, 000 ohms, how much current would pass through your body?\n";
	cout << "(Answer only with a number)  \n";
	double /*string*/ answer = 0.0009  /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	CheckCinInt(InputAnswer);
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

		Reattempt(retry, Question);
	}
}

void Question11()
{
	//in these questions you will have to answer with true or false

	Question = 11;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question12()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 12;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question13()
{
	//In these question you have to enter the answer;

	Question = 13;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
	}
	cout << "The total resistance of a 10-ohm resistor and a 7-ohm resistor in series is\n";
	cout << "(Answer only with a number)  \n";
	int /*string*/ answer = 17 /*some answer that we have to guees*/;

	int /*string*/ InputAnswer;
	cin >> InputAnswer;
	CheckCinInt(InputAnswer);
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

		Reattempt(retry, Question);
	}
}

void Question14()
{
	//in these questions you will have to answer with true or false

	Question = 14;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}

void Question15()
{
	//in these questions you wil have to answer with a,b,c,d

	Question = 15;
	system("CLS");
	if (QuestionsCounter >= 10)
	{
		EndOfTest();
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

		Reattempt(retry, Question);
	}
}
//Test code ↑

int main()
{
	Menu();

	return 0;
}
