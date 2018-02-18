#pragma once
class MainGame
{
	enum class Player
	{
		none = '-',
		human = 'X',
		computer = 'O'
	};

	struct Move {
		unsigned gameField;
		bool turn; //which player's turn 0: human, 1: computer
		int score;
	};

	Player board[9];

public:
	/*Constructior which fill all game board's fiels with empty values*/
	MainGame();
	~MainGame();

	/*Print game board into the console, with current board*/
	void printBoard();

	/*Verify that there is no empty fields, and there is no winner*/
	bool isRemis();

	/*Verify the winner exists on current board*/
	bool verifyPalyerWin(Player player);

	/*Get char from console, and verify the value is correct, after that save move into game board*/
	void getHumanMove();

	/*Main method which looping wole game algorithms, and quit when the game is over*/
	void play();

	int getBestPossibleMove(Player boardm, Player & player);

	/*For MinMax algorithm*/
	int getBestPossibleMove();
	int maxSearch(int level);
	int minSearch(int level);

};

