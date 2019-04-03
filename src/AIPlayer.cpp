#include "AIPlayer.h"
#include "othello.h"
void AIPlayer::AISetDepth(int depth) {
	AIDepth = depth;
}
void AIPlayer::addPiece(Othello &othello, int playerID) {
	int opponentID = 2;
	if (playerID == 2) opponentID = 1;
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (othello.moveTable[i][j] != 0) {
				k++;
			}
		}
	}
	int(*possibleMoves)[2] = new int[k][2];
	k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (othello.moveTable[i][j] != 0) {
				possibleMoves[k][0] = i;
				possibleMoves[k][1] = j;
				k++;
			}
		}
	}
	int bestValue = -99999;
	int bestX = possibleMoves[0][0], bestY = possibleMoves[0][1];
	for (int i = 0; i < k; i++) {
		Othello tempOthello = othello;
		tempOthello.othelloMoveRegister(possibleMoves[i][0], possibleMoves[i][1], playerID);
		int value = othello.moveTable[possibleMoves[i][0]][possibleMoves[i][1]];
		int currentValue = minimax(tempOthello, playerID, opponentID, -99999, 99999, 1, value);
		if (currentValue > bestValue) {
			bestValue = currentValue;
			bestX = possibleMoves[i][0];
			bestY = possibleMoves[i][1];
		}
	}
	int i = bestX;
	int j = bestY;
	othello.othelloMoveRegister(i, j, playerGetID());
	othello.moveMemoryTranscript(i, j);
	othello.TranscriptPrinter();
	return;
}
int AIPlayer::minimax(Othello &othello, int originalID, int currentID, int a, int b, int depth, int value) {
	bool flag = hasMoves(othello, 1); //Variable to check if the player has moves
	if (!flag) hasMoves(othello, 2);
	othello.othelloChecker(currentID);
	if (depth == AIDepth || !flag) return heuristic(othello, value, originalID);
	int opponentID = 2;
	if (currentID == 2) opponentID = 1;
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (othello.moveTable[i][j] != 0) {
				k++;
			}
		}
	}
	int(*possibleMoves)[2] = new int[k][2];
	k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (othello.moveTable[i][j] != 0) {
				possibleMoves[k][0] = i;
				possibleMoves[k][1] = j;
				k++;
			}
		}
	}
	if(k==0) return minimax(othello, originalID, opponentID, a, b, depth + 1, value);
	for (int i = 0; i < k; i++) {
		Othello tempOthello = othello;
		tempOthello.othelloMoveRegister(possibleMoves[i][0], possibleMoves[i][1], currentID);
		int currentValue = minimax(tempOthello, originalID, opponentID, a, b, depth + 1, value);
		if (originalID == currentID) {
			if (currentValue > a) a = currentValue;
			else if (currentValue <= b) return currentValue;
		}
		else {
			if (currentValue < b) b = currentValue;
			else if (currentValue >= a) return currentValue;
		}
	}
	return a;
}
int AIPlayer::heuristic(Othello &othello, int value, int playerID) {
	int ourScore, opponentScore;
	othello.scoreCounter();
	if (playerID == 1) {
		ourScore = othello.black;
		opponentScore = othello.white;
	}
	else if (playerID == 2) {
		ourScore = othello.white;
		opponentScore = othello.black;
	}
	return ourScore - opponentScore + value;
}
bool AIPlayer::hasMoves(Othello &othello, int playerID) {
	othello.othelloChecker(playerID);
	bool flag = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (othello.moveTable[i][j] != 0) {
				flag = true;
				break;
			}
		}
	}
	return flag;
}