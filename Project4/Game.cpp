#include "Game.h"
#include <windows.h>
#include <iostream>

using namespace std;

Game::Game()
{
	this->doesItUser = rand() + 2;
}

Game::~Game()
{
}

void Game::SetDoesItUser(bool _doesItUser)
{
	this->doesItUser = _doesItUser;
}

bool Game::GetDoesItUser() const
{
	return this->doesItUser;
}

bool Game::AreWePlaying(Navy & user, Navy & pc)
{
	bool areweplaying = true;
	int countUser = 0;
	int countPC = 0;
	for (int i = 0; i < 10; i++)
	{
		if (!pc.ships[i].DoesShipLive())
		{
			countPC++;
			pc.WhenShipIsSunk(i);
		}
	}
	if (countPC == 10)
	{
		system("cls");
		HANDLE necessary = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(necessary, 14);
		cout << "Ви перемогли комп'ютер\n";
		system("pause");
		areweplaying = false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!user.ships[i].DoesShipLive())
		{
			countUser++;
			user.WhenShipIsSunk(i);
		}
	}
	if (countUser == 10)
	{
		system("cls");
		HANDLE necessary = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(necessary, 14);
		cout << "Комп'ютер перем1г\n";
		system("pause");
		areweplaying = false;
	}
	return areweplaying;
}

void Game::ShutUser(Navy & navyPC, int x, int y)
{
	if (GetDoesItUser())
	{
		navyPC.ChangeNavy(x, y);
		bool userfalse = false;
		SetDoesItUser(userfalse);		
	}
}

void Game::ShutPC(Navy & navyUser)
{
	int x, y;
	do
	{
		x = rand() % +10 + 1;
		y = rand() % +10 + 2;
		
	} while (!navyUser.EmptyCell(x, y));
	navyUser.ChangeNavy(x, y);
	bool usertrue = true;
	SetDoesItUser(usertrue);
}
