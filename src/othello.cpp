#include "othello.h"
Othello::Othello(){
	initializeTable();
};
void Othello::initializeTable() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			othelloTable[i][j] = 0;
		}
	}
	othelloMoveRegister(3, 3, 2);
	othelloMoveRegister(3, 4, 1);
	othelloMoveRegister(4, 3, 1);
	othelloMoveRegister(4, 4, 2);
	transcriptIndex = 0;
	return;
}
void Othello::othelloMoveRegister(int row, int col, int playerID) {
	if (playerID == 1) othelloTable[row][col] = playerID;
	else if (playerID == 2) othelloTable[row][col] = playerID;
	int j, l;
	/*! 1st for loop checks downwards if the first disc belongs to the same player or does not exist (0 in othelloTable),
	otherwise it searches for a disc belonging to the opponent and if it finds one then it goes backwards and turns enemy discs to current player's
	*/
	for (int i = row + 1; i < 8; i++) {
		if (i == row + 1 && othelloTable[i][col] == playerID || othelloTable[i][col] == 0) break;
		else if (othelloTable[i][col] == playerID) {
			for (int k = i - 1; k > row; k--) {
				othelloTable[k][col] = playerID;
			}
			break;
		}
	}
	/*! 2nd for loop checks upwards with the same logic as 1st
	*/
	for (int i = row - 1; i >= 0; i--) {
		if (i == row - 1 && othelloTable[i][col] == playerID || othelloTable[i][col] == 0) break;
		else if (othelloTable[i][col] == playerID) {
			for (int k = i + 1; k < row; k++) {
				othelloTable[k][col] = playerID;
			}
			break;
		}
	}
	/*! 3rd for loop checks to the right with the same logic as the others
	*/
	for (int i = col + 1; i < 8; i++) {
		if (i == col + 1 && othelloTable[row][i] == playerID || othelloTable[row][i] == 0) break;
		else if (othelloTable[row][i] == playerID) {
			for (int k = i - 1; k > col; k--) {
				othelloTable[row][k] = playerID;
			}
			break;
		}
	}
	/*! 4th for loop checks to the left with the same logic as the others
	*/
	for (int i = col - 1; i >= 0; i--) {
		if (i == col - 1 && othelloTable[row][i] == playerID || othelloTable[row][i] == 0) break;
		else if (othelloTable[row][i] == playerID) {
			for (int k = i + 1; k < col; k++) {
				othelloTable[row][k] = playerID;
			}
			break;
		}
	}
	/*! 5th for loop checks diagonally upwards left with the same logic as the others
	*/
	j = col - 1;
	for (int i = row - 1; i >= 0; i--) {
		if (j >= 0) {
			if (i == row - 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0) break;
			else if (othelloTable[i][j] == playerID) {
				l = j + 1;
				for (int k = i + 1; k < row; k++) {
					othelloTable[k][l] = playerID;
					l++;
				}
				break;
			}
			if (j > 0) j--;
			else break;
		}
		else break;
	}
	/*! 6th for loop checks diagonally downwards left with the same logic as the others
	*/
	j = col - 1;
	for (int i = row + 1; i < 8; i++) {
		if (j >= 0) {
			if (i == row + 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0) break;
			else if (othelloTable[i][j] == playerID) {
				l = j + 1;
				for (int k = i - 1; k > row; k--) {
					othelloTable[k][l] = playerID;
					l++;
				}
				break;
			}
			if (j > 0) j--;
			else break;
		}
		else break;
	}
	/*! 7th for loop checks diagonally downwards right with the same logic as the others
	*/
	j = col + 1;
	for (int i = row + 1; i < 8; i++) {
		if (j < 8) {
			if (i == row + 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0) break;
			else if (othelloTable[i][j] == playerID) {
				l = j - 1;
				for (int k = i - 1; k > row; k--) {
					othelloTable[k][l] = playerID;
					l--;
				}
				break;
			}
			if (j < 7) j++;
			else break;
		}
		else break;
	}
	/*! 8th for loop checks diagonally upwards right with the same logic as the others
	*/
	j = col + 1;
	for (int i = row - 1; i >= 0; i--) {
		if (j < 8) {
			if (i == row - 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0) break;
			else if (othelloTable[i][j] == playerID) {
				l = j - 1;
				for (int k = i + 1; k < row; k++) {
					othelloTable[k][l] = playerID;
					l--;
				}
				break;
			}
			if (j < 7) j++;
			else break;
		}
		else break;
	}
	return;
}
void Othello::othelloPrinter(){
	scoreCounter();
	int i, j;
	for (i = 0; i < 10; i++) {
		if (i == 0 || i == 9) cout << "  A B C D E F G H" << endl;
		else {
			cout << i;
			for (j = 0; j < 8; j++) {
				if (othelloTable[i - 1][j] == 1) cout << "|X";
				else if (othelloTable[i - 1][j] == 2) cout << "|O";
				else if (moveTable[i - 1][j] != 0) cout << "|+";
				else cout << "| ";
			}
			if (i == 3) cout << "|" << i << "     X = " << black << endl;
			else if (i == 6) cout << "|" << i << "     O = " << white << endl;
			else cout << "|" << i << endl;
		}
	}
	return;
}
void Othello::moveMemoryTranscript(int row, int col){
	Transcript[transcriptIndex] = (char)(col + 65);
	Transcript[transcriptIndex + 1] = (char)(row + 49);
	transcriptIndex+= 2;
	return ;
}
void Othello::TranscriptPrinter() {
	cout <<endl<< "Transcript: ";
	for (int j = 0; j < transcriptIndex; j++) {
		cout  << Transcript[j];
	}
	cout << endl;
	return;
}
bool Othello::othelloValidity(int row, int col) {
	if (row < 0 || row > 7) return false;
	if (col < 0 || col > 7) return false;
	if (moveTable[row][col] != 0) return true;
	else return false;
}
int Othello::othelloWinChecker() {
	int winner = 0;
	scoreCounter();
	if (black > white) winner = 1;
	else if (black < white) winner = 2;
	return winner;
}
void Othello::scoreCounter() {
	white = 0;
	black = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (othelloTable[i][j] == 1) black++;
			else if (othelloTable[i][j] == 2) white++;
		}
	}
}
void Othello::othelloChecker(int playerID) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			moveTable[i][j] = 0;
		}
	}
	int row = 0;
	int col = 0;
	/*! j is used as the column later
	*/
	int j;
	while (row < 8) {
		if (othelloTable[row][col] == 0) {
			/*! 1st for loop checks downwards if the first disc belongs to the same player or does not exist (0 in othelloTable), otherwise it searches for a disc belonging to the opponent
			*/
			for (int i = row + 1; i < 8; i++) {
				if (i == row + 1 && othelloTable[i][col] == playerID || othelloTable[i][col] == 0) break;
				else if (othelloTable[i][col] == playerID) {
					movePoints(row, col);
					break;
				}
			}
			/*! 2nd for loop checks upwards with the same logic as 1st but also checks if the previous one found that the player can make a move in the current position
			*/
			for (int i = row - 1; i >= 0; i--) {
				if (i == row - 1 && othelloTable[i][col] == playerID || othelloTable[i][col] == 0 || moveTable[row][col] != 0) break;
				else if (othelloTable[i][col] == playerID) {
					movePoints(row, col);
					break;
				}
			}
			/*! 3rd for loop checks to the right with the same logic as the others
			*/
			for (int i = col + 1; i < 8; i++) {
				if (i == col + 1 && othelloTable[row][i] == playerID || othelloTable[row][i] == 0 || moveTable[row][col] != 0) break;
				else if (othelloTable[row][i] == playerID) {
					movePoints(row, col);
					break;
				}
			}
			/*! 4th for loop checks to the left with the same logic as the others
			*/
			for (int i = col - 1; i >= 0; i--) {
				if (i == col - 1 && othelloTable[row][i] == playerID || othelloTable[row][i] == 0 || moveTable[row][col] != 0) break;
				else if (othelloTable[row][i] == playerID) {
					movePoints(row, col);
					break;
				}
			}
			/*! 5th for loop checks diagonally upwards left with the same logic as the others
			*/
			j = col - 1;
			for (int i = row - 1; i >= 0; i--) {
				if (j >= 0) {
					if (i == row - 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0 || moveTable[row][col] != 0) break;
					else if (othelloTable[i][j] == playerID) {
						movePoints(row, col);
						break;
					}
					if (j > 0) j--;
					else break;
				}
				else break;
			}
			/*! 6th for loop checks diagonally downwards left with the same logic as the others
			*/
			j = col - 1;
			for (int i = row + 1; i < 8; i++) {
				if (j >= 0) {
					if (i == row + 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0 || moveTable[row][col] != 0) break;
					else if (othelloTable[i][j] == playerID) {
						movePoints(row, col);
						break;
					}
					if (j > 0) j--;
					else break;
				}
				else break;
			}
			/*! 7th for loop checks diagonally downwards right with the same logic as the others
			*/
			j = col + 1;
			for (int i = row + 1; i < 8; i++) {
				if (j < 8) {
					if (i == row + 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0 || moveTable[row][col] != 0) break;
					else if (othelloTable[i][j] == playerID) {
						movePoints(row, col);
						break;
					}
					if (j < 7) j++;
					else break;
				}
				else break;
			}
			/*! 8th for loop checks diagonally upwards right with the same logic as the others
			*/
			j = col + 1;
			for (int i = row - 1; i >= 0; i--) {
				if (j < 8) {
					if (i == row - 1 && othelloTable[i][j] == playerID || othelloTable[i][j] == 0 || moveTable[row][col] != 0) break;
					else if (othelloTable[i][j] == playerID) {
						movePoints(row, col);
						break;
					}
					if (j < 7) j++;
					else break;
				}
				else break;
			}
		}
		/*! When we finish checking the rows in a certain column then we check if we have more columns that their rows need to be checked. If so, we move forward a column and reset the rows
		*/
		if (row < 7) row++;
		else if (col < 7) {
			row = 0;
			col++;
		}
		else row++;
	}
}
void Othello::movePoints(int row, int col) {
	if ((row == 0 && col == 0) || (row == 0 && col == 7) || (row == 7 && col == 0) || (row == 7 && col == 7)) moveTable[row][col] = 1000;
	else if ( ( (row == 1 || row == 6) && (col == 0 || col == 7) ) || ( (row == 0 || row == 7) && (col == 1 || col == 6) ) ) moveTable[row][col] = -100;
	else if (row == 0 || col == 0 || row == 7 || col == 7) moveTable[row][col] = 100;
	else if ( ( row == 1 || row == 6)  && (col == 1 || col == 6) ) moveTable[row][col] = -1000;
	else moveTable[row][col] = 1;
	return;
}