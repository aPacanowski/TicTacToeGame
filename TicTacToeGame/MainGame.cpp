#include "stdafx.h"
#include "MainGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

MainGame::MainGame()
{
	//clean board after game intialize
	for (int i = 0; i < 9; i++) {
		board[i] = Player::none;
	}
}

MainGame::~MainGame()
{
}

void MainGame::printBoard() {
	system("cls");
	cout << "\n\n\tTic Tac Toe" << endl; 
	cout << "Player 1 (X)  -  Computer (O)" << endl << endl;
	cout << endl;

	for (int i = 0; i < 9; i++) {

			if (i % 3 == 0) {
				cout << endl;
			}
			cout << "  " << static_cast<char>(board[i]) << "  |  ";
	}
}

bool MainGame::isDraw() {
	int CounterEmptyFileds = 0;
	if (verifyPalyerWin(Player::human) || verifyPalyerWin(Player::computer)) {
		return false;
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (board[i] == Player::none)
				CounterEmptyFileds++;
		}
		return (CounterEmptyFileds > 0) ? false : true;
	}

}

bool MainGame::verifyPalyerWin(Player player) {
	for (int i = 0; i < 3; i++) {
		//verify vertical
		if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
			return true;
		}
	}
	for (int i = 0; i < 9; i+=3) {
		//verify horizontal
		if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
			return true;
		}
		
	}
	//verify cross wins
	if (board[0] == player && board[4] == player && board[8] == player) {
		return true;
	}
	if (board[2] == player && board[4] == player && board[6] == player) {
		return true;
	}

	return false;
}

void MainGame::getHumanMove() {
	int choosenField = -1;
	bool wrongMove = true;
	char move;
	//get field number and verify that move is possible
	do {
		cout << "Make Move! : ";
		cin >> move;
		if (isdigit(move)) {
			choosenField = move - 48;
			if ((choosenField <= 9 && choosenField >= 1) && board[choosenField-1] == Player::none) {
				wrongMove = false;
			}
			else {
				cout << "wrong number! No field with this number or spot is taken";
				wrongMove = true;
			}
		}
		else {
			cout << "ITS NOT A NUMBER!";
			wrongMove = true;
		}
		cout << endl;
	} while (wrongMove);

	board[choosenField-1] = Player::human; //minus 1 because of iteration from 0;
}

void MainGame::play() {
	bool turn = 0;
	bool exit = false;
	std::string winner = "";
	printBoard();

	do {

		if (turn == 0) {
			getHumanMove();
			turn = 1;
			if (verifyPalyerWin(Player::human)) {
				winner = "Human";
				exit = true;
			}
		}
		else { //computer turn

			int bestMove = getBestPossibleMove();
			board[bestMove] = Player::computer;

			if (verifyPalyerWin(Player::computer)) {
				winner = "Computer";
				exit = true;
			}
			turn = 0;
		}

		if (isDraw()) {
			winner = "no one, its just a draw";
			exit = true;
		}
		printBoard();

		if (winner.length() > 2)
		{
			cout << "THE WINNER IS : " << winner;
		}
	} while (!exit);
}


int MainGame::getBestPossibleMove()
{
	int score = std::numeric_limits<int>::max();
	int temp = 0;
	int result = 0;
	for (int i = 0; i < 9; i++) {
		if (board[i] == Player::none) {

			board[i] = Player::computer;
			temp = maxSearch(i);

			if (temp < score) {
				score = temp;
				result = i;
			}
			
			board[i] = Player::none; //clear field, without this gameBoard will be corrupted
		}
	}

	return result;
}

int MainGame::maxSearch(int level) {
	if (verifyPalyerWin(Player::human)) { return 10; }
	else if (verifyPalyerWin(Player::computer)) { return -10; }
	else if (isDraw()) { return 0; }

	int score = std::numeric_limits<int>::min();
	for (int i = 0; i < 9; i++) {
		if (board[i] == Player::none) {
			board[i] = Player::human;
			score = std::max(score, minSearch(level-1)+level);
			board[i] = Player::none;
		}
	}
	return score;
}

int MainGame::minSearch(int level) {
	if (verifyPalyerWin(Player::human)) { return 10; }
	else if (verifyPalyerWin(Player::computer)) { return -10; }
	else if (isDraw()) { return 0; }

	int score = std::numeric_limits<int>::max();

	for (int i = 0; i < 9; i++)
	{
		if (board[i] == Player::none)
		{
			board[i] = Player::computer;
			score = std::min(score, maxSearch(level+1)-level);
			board[i] = Player::none;
		}
	}
	return score;
}

