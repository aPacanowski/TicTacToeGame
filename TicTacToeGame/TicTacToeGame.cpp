// TicTacToeGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "MainGame.h"

using namespace std;

int main()
{
	MainGame game;
	game.play();
	cout << endl;
	printf("Press any key to continue . . .");
	_getch();
	return 0;
}

