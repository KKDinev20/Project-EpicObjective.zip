#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <random>
#include <time.h>

using namespace std;
using namespace std::this_thread; //allows the usage of "sleep_for" function
using namespace std::chrono_literals; //allows the use of ns, us, ms, s, h, etc.
void PlanetSort();
void WhatFloats();
void CalculateSpeed();
void Breakfast();
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

void Setup()
{
	srand(time(NULL));
	player.direction = Still;
	player.X = game.gameWidth / 2;
	player.Y = game.gameHeight / 2;
	player.Power = 0;
	player.Health = 100;
	boss.Power = 10;
	boss.Health = 100;
	help.HelpX = rand() % game.gameWidth;
	help.HelpY = rand() % game.gameHeight;
}

void Border()
{
	system("CLS");
	for (int i = 0; i < game.gameWidth + 2; i++)
	{
		cout << "#";
	}

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
				cout << "O";
			}
			else if (i == help.HelpY && j == help.HelpX)
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
	else if (player.X < 0)
	{
		player.direction = Still;
		player.X += 1;
	}
	else if (player.Y < 0)
	{
		player.direction = Still;
		player.Y += 1;
	}
	else if (player.Y >= game.gameHeight)
	{
		player.direction = Still;
		player.Y -= 1;
	}
}

void Missions()
{
	system("CLS");
	int Mission = rand() % 5 + 1;

	switch (Mission)
	{
	case 1:
		PlanetSort();
		break;
	case 2:
		WhatFloats();
		break;
	case 3:
		CalculateSpeed();
	case 4:
		Breakfast();
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
	cout << "Help the little boy sort the planets \n";
	string Planets[8] = { "Saturn", "Venus", "Neptune", "Jupeter", "Mars", "Uranus", "Mercury", "Earth" };

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

		if (Place <= 8)
		{
			swap(Planets[tries], Planets[Place - 1]);
		}
		else
		{
			cout << "pleace enter a valid planet";
		}
	}
	system("CLS");
	cout << "Let's se if the planets are on their place \n";
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
		cout << "Yay you helped sort the planets";
	}
	else
	{
		cout << "Oh no you couldn't help";
	}

	cout << "\nWhen you are ready press \"Enter\"";
	system("Pause");
}

void CalculateSpeed()
{
	system("CLS");

	cout << "Oh no that poor woman is going to be late for work \n";
	cout << "Lets use our super speed to help, but you will have to calculate it before we use it \n";
	int Time = 20; //20 minutes = 0.3hours
	int Distance = 30; //30km
	int Speed;
	cout << "She has " << Time << " minutes to go to work " << endl;
	cout << "And the distance we need to travel is" << Distance << endl;
	cout << "So, what should our speed be? \n";
	cin >> Speed;

	for (int i = 0; i < 30; i++)
	{
		for (int i = 0; i < 30; i++)
		{
			cout << "flying to woman's office" << endl;
			for (int j = 0; j < i; j++)
			{
				cout << " ";
			}
			cout << "o";
			//cout << character; 
			system("CLS");
		}
	}

	if (Speed >= 100)
	{
		cout << "Yay, she is there on time!\n";
	}
	else
	{
		cout << "Ohh no!, she is late for work!\n";
	}
}

void Breakfast()
{
	system("CLS");
	cout << "There is one of your biggest fans. AND HE OFFERS U FOOD\n";
	cout << "Would you accept it?\n";

	string answer;
	while (answer != "YES" && answer != "NO")
	{
		cin >> answer;
		if (answer == "YES")
		{
			cout << "Yay! We you made him happy!\n";
		}
		else if(answer == "NO")
		{
			cout << "AW, u made him sad.\n";
		}
		else
		{
		cout << "Please enter with capital letters\n";
		}
	}

	cout << "OHH NO!! Look ut, there is a big monster over there?\n";
	cout << "Would you save the city?\n";

	cin >> answer;
	while (answer != "YES" && answer != "NO")
	{
		cin >> answer;
		if (answer == "YES")
		{
			cout << "SAVED\n";
		}
		else if(answer == "NO")
		{
			cout << "NOT SAVED\n";
		}
		else
		{
			cout << "Please enter with capital letters\n";
		}
	}
}

void WhatFloats()
{
	system("CLS");
	int Answer;
	cout << "The old fisherman's boat is broken. He has a hole in his boat \n";
	cout << "There are three different materials \n";
	cout << "1. Wood\n2. Metal\n3. Aluminum\n";
	cout << "So what material should we use 1, 2 or 3\n";
	cin >> Answer;

	if (Answer == 3)
	{
		cout << "\nYay the boat is ready to go\n";
	}
	else if (Answer == 2 || Answer == 1)
	{
		cout << "\nOh no the boat sank\n";
	}
	else
	{
		cout << "\nPlease enter a valid number\n";
	}

	cout << "\nWhen you are ready press \"Enter\"";
	system("Pause");
}

int main()
{
	Setup();

	while (game.GameOn)
	{
		Border();//draws border
		PlayerInput();//checks for player input
		MovementNLogic();//Moves the player and stops you at the border
		MissionsActivate();//activates missions
		sleep_for(7ms);//sleep
	}

	return 0;
}