/*
* Authors
* |AM	  |NAME										  |
* |3160004|ΣΕΜΠΑΣΤΙΑΝ ΚΡΙΣΤΟ ΑΛΜΠΕΡΝΑΖ ΝΤΕ ΣΟΤΤΟ ΜΑΙΟΡ|
* |3160072|ΜΙΧΑΗΛ ΚΩΝΣΤΑΝΤΑΚΟΣ					      |
* |3160111|ΟΡΦΕΑΣ ΜΠΟΥΣΟΥΛΑΣ-ΡΑΪΚΙΔΗΣ			      |
*
* Desc: Othello game with PvP, PvE and EvE modes using the recursive minimax algorithm with a-b pruning.
*/
#include "othello.h"
#include "humanPlayer.h"
#include "AIPlayer.h"
#include <chrono>
#include <thread>
/*! Function that gives the turn to the next player
*
* When a player does not have any moves he skips a turn.
* When both players no longer have any moves the game ends and the winner is decided.
*/
template <class T, class U>
void nextTurn(T *player1, U *player2, Othello othello, int playerID) {
	bool playerHasMoves = false;
	bool anyoneHasMoves = false;
	int skip = 0;
	while (skip < 2) {
		if (playerID == 1) playerID = 2;
		else playerID = 1;
		othello.othelloChecker(playerID);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (othello.moveTable[i][j] != 0) {
					playerHasMoves = true;
					break;
				}
			}
			if (playerHasMoves) break;
		}
		if (!playerHasMoves) {
			skip++;
			if (skip == 1) anyoneHasMoves = true;
		}
		else {
			if (anyoneHasMoves) {
				cout << "---------------------------------------- NO POSSIBLE MOVES. ----------------------------------------" <<endl;
				anyoneHasMoves = false;
			}
			skip = 0;
			playerHasMoves = false;
			othello.othelloPrinter();
			if (playerID == 1) {
				cout << "It's your turn player X." << endl;
				player1 -> addPiece(othello, 1);
			}
			else {
				cout << "It's your turn player O." << endl;
				player2 -> addPiece(othello, 2);
			}
		}
	}
	othello.othelloChecker(playerID);
	othello.othelloPrinter();
	if (othello.othelloWinChecker() == 0) cout << "It's a draw." << endl;
	else cout << "Congratulations player " << othello.othelloWinChecker() << "! You won." << endl;
	return;
}
/*! Function that lets the player choose the game mode
*/
char message() {
	cout << "Please enter an option: (Select 0-3)" << endl;
	cout << "1. Player vs AI" << endl;
	cout << "2. Player vs Player" << endl;
	cout << "3. AI vs AI" << endl;
	cout << "0. Exit Game" << endl;
	char selection;
	cin >> selection;
	while (selection < 48 || selection > 51) {
		cout << "Invalid input. Please enter a valid option." << endl;
		cin >> selection;
	}
	return selection;
}
/*! Function that checks the player's selected game mode
*
* If the user inputs 1,2 or 3 it creates the othello board and the players and starts the selected mode by converting the players accordingly.
* If the user inputs 0 the game ends.
*/
void playGame() {
	cout << "Welcome to the Othello game" << endl;
	char selection = message();
	while (selection != 48) {
		Othello othello;
		if (selection == 49) {
			unique_ptr<HumanPlayer> human (new HumanPlayer);
			unique_ptr<AIPlayer> AI (new AIPlayer);
			int depth;
			char answer;
			cout << "Choose AI's depth: (Select 1-10)" << endl;
			cin >> depth;
			while (depth < 1 || depth > 10) {
				cout << "Invalid input. Please enter a valid depth." << endl;
				cin >> depth;
			}
			AI.get() -> AISetDepth(depth);
			cout << "Do you want to play first? (Y/N)" << endl;
			cin >> answer;
			answer = toupper(answer);
			while (answer != 'Y' && answer != 'N') {
				cout << "Invalid input. Please enter a valid answer." << endl;
				cin >> answer;
				answer = toupper(answer);
			}
			if (answer == 'Y') {	
				othello.othelloChecker(1);
				othello.othelloPrinter();
				cout << "You play first player X." << endl;
				human -> addPiece(othello, 1);
				nextTurn(human.get(), AI.get(), othello, 1);
			}
			else {
				othello.othelloChecker(2);
				othello.othelloPrinter();
				AI -> addPiece(othello, 1);
				nextTurn(human.get(), AI.get(), othello, 2);
			}
		}
		else if (selection == 50) {
			unique_ptr<HumanPlayer> human1 (new HumanPlayer);
			unique_ptr<HumanPlayer> human2 (new HumanPlayer);
			othello.othelloChecker(1);
			othello.othelloPrinter();
			cout << "You play first player X." << endl;
			human1 -> addPiece(othello, 1);
			nextTurn(human1.get(), human2.get(), othello, 1);
		}
		else {
			unique_ptr<AIPlayer> AI1 (new AIPlayer);
			unique_ptr<AIPlayer> AI2 (new AIPlayer);
			int depth1, depth2;
			cout << "Choose first AI's depth: (Select 1-10)" << endl;
			cin >> depth1;
			while (depth1 < 1 || depth1 > 10) {
				cout << "Invalid input. Please enter a valid depth." << endl;
				cin >> depth1;
			}
			cout << "Choose second AI's depth: (Select 1-10)" << endl;
			cin >> depth2;
			while (depth2 < 1 || depth2 > 10) {
				cout << "Invalid input. Please enter a valid depth." << endl;
				cin >> depth2;
			}
			AI1.get() -> AISetDepth(depth1);
			AI2.get() -> AISetDepth(depth2);
			othello.othelloChecker(1);
			othello.othelloPrinter();
			AI1 -> addPiece(othello, 1);
			nextTurn(AI1.get(), AI2.get(), othello, 1);
		}
		cout << "Do you want to play again?" << endl;
		selection = message();
	}
	cout << "See you!" << endl;
}
int main(int argc, char *argv[]) {
	playGame();
	this_thread::sleep_for(2s);
	return 0;
}