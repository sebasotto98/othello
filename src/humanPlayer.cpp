#include "humanPlayer.h"
#include "othello.h"
void HumanPlayer::addPiece(Othello &othello, int playerID) {
	int i, j;
	char input[3];
	cout << "Please enter a move." << endl;
	cin >> input;
	input[2] = '\0';
	if (isupper(input[0])) j = input[0] - 65;
	else j = input[0] - 97;
	i = input[1] - 49;
	while (othello.othelloValidity(i, j) == false) {
		cout << "Invalid input. Please enter a valid move." << endl;
		cin >> input;
		input[2] = '\0';
		if (isupper(input[0])) j = input[0] - 65;
		else j = input[0] - 97;
		i = input[1] - 49;
	}
	othello.othelloMoveRegister(i, j, playerGetID());
	othello.moveMemoryTranscript(i, j);
	othello.TranscriptPrinter();
	return;
}