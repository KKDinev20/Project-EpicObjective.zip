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
enum PlayerDirection { Still = 0, Left, Right, Up, Down };//user defined data type where we specify a set of values for a variable and the variable can only take one out of a small set of possible values
struct Player
{
	int X;
	int Y;
	PlayerDirection direction;
};

struct Help
{
	int HelpX;
	int HelpY;
};

struct Map
{
	const int MapWidth = 20;
	const int MapHeight = 20;
};

int score = 0;
Player player;
Help help;
Map map;
bool GameOn = false;

void Setup()
{
	srand(time(NULL));
	player.direction = Still;
	player.X = map.MapWidth / 2;
	player.Y = map.MapHeight / 2;
	help.HelpX = rand() % map.MapWidth;
	help.HelpY = rand() % map.MapHeight;
}

void Border()
{
	system("CLS");
	for (int i = 0; i < map.MapWidth + 2; i++)
	{
		cout << "#";
	}

	cout << endl;

	for (int i = 0; i < map.MapHeight; i++)
	{
		for (int j = 0; j < map.MapWidth; j++)
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
			if (j == map.MapWidth - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}


	for (int i = 0; i < map.MapWidth + 2; i++)
	{
		cout << "#";
	}

	cout << "\n People helped: " << score;
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

	if (player.X >= map.MapWidth)
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
	else if (player.Y >= map.MapHeight)
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
	case 2:
		PlanetSort();
	case 3:
		PlanetSort();
	case 4:
		PlanetSort();
	case 5:
		PlanetSort();
	}
}

void MissionsActivate()
{
	if (player.X == help.HelpX && player.Y == help.HelpY)
	{
		help.HelpX = rand() % map.MapWidth;
		help.HelpY = rand() % map.MapHeight;

		Missions();
		player.direction = Still;
	}
}

void PlanetSort()
{
	system("CLS");
	cout << "Help the little boy sort the planets \n";
	string Planets[8] = { "Saturn", "Venus", "Neptune", "Jupeter", "Mars", "Uranus", "Mercury", "Earth"};

	for (int i = 0; i < 8; i++)
	{
		cout << i+1 << ". " << Planets[i] << endl;
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

		swap(Planets[tries], Planets[Place-1]);
	}
	system("CLS");
	cout << "Let's se if the planets are on their place";
	for (int i = 0; i < 8; i++)
	{
		cout << i+1 << ". " << Planets[i];
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
		score++;
		cout << "Yay you helped sort the planets";
	}
	else
	{
		cout << "Oh no you couldn't help";
	}

	cout << "\nWhen you are ready press \"Enter\"";
	system("Pause");
}

int main()
{
	srand(time(NULL));
	Setup();

	while (!GameOn)
	{
		Border();//draws border
		PlayerInput();//checks for player input
		MovementNLogic();//Moves the player and stops you at the border
		MissionsActivate();//activates missions
		sleep_for(7ms);//sleep
	}

	return 0;
}