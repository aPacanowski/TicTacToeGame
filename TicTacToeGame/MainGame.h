#pragma once
class MainGame
{
	enum class Player
	{
		none = '-',
		human = 'X',
		computer = 'O'
	};

	Player board[9];

public:
	/*Constructior which fill all game board's fiels with empty values*/
	MainGame();
	~MainGame();

	/*Main method which looping wole game algorithms, and quit when the game is over*/
	void play();

private:
	/*Print game board into the console, with current board*/
	void printBoard();

	/*Verify that there is no empty fields, and there is no winner*/
	bool isDraw();

	/*Verify the winner exists on current board*/
	bool verifyPalyerWin(Player player);

	/*Get char from console, and verify the value is correct, after that save move into game board*/
	void getHumanMove();

	/*Get best possible move for computer, and set it on board*/
	void setComputerMove();

	/*Method which return free filed number, only when last filed left for win*/
	int getFieldIfNearWin(Player player);
	/*				  
	 *MinMax algorithm
	 */

	/*Check the best move, and return the number of field (0-8)*/
	int getBestPossibleMove();

	/*Recursive functions, which calculate best score, maxSearch() callcualte best possible computer move,
	the minSearch() callculate best possible way to prevent human's win. Both return best score*/
	int maxSearch(int level);
	int minSearch(int level);

};

