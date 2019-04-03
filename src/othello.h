#pragma once
#ifndef _OTHELLO
#define _OTHELLO
#include <iostream>
using namespace std;
//---------------------------------------- class Othello ----------------------------------------
/*! It is the class that represents the state of the game.
*
* It holds the board of the game with each player's move up to now. There is a table which holds all the possible moves of a player depending on his ID.
* The transcript is stored in a seperate array and its index in a seperate variable. Lastly black and white hold the number of pieces on the board for each color.
*
* The board is stored in a 8 * 8 2D array that has 0 in every empty position and 1 or 2 for black or white respectively. The 2D array that holds the moves is also 8 * 8,
* has 0 in every position that the player can not play and a value from -1000 to 1000 depending on the move's value.
*/
class Othello {
	private:
		int othelloTable[8][8], transcriptIndex;
		char *Transcript = new char[128];
	public:
		int moveTable[8][8];
		int black, white;
		/*! Default constructor
		*
		* By default, the game initializes the board according to initializeTable().
		*/
		Othello();
		/*! Default destructor
		*/
		~Othello() = default;
		/*! Function to initiate the whole table with 0 apart from the first 4 pieces on the OthelloTable
		*/
		void initializeTable();
		/*! Fuction that applies movement given by the player to the OthelloTable
		*
		* This step is always done after we make sure the player can make a move in the given position so it is safe to search and apply the move without checking if it is valid.
		* It checks in one direction if it is out of bounds or if the next piece is empty, an opponents' or the current player's.
		* If it is an opponent's it moves forward until it goes out of bounds or finds an empty piece, an opponent's or the current player's.
		* Otherwise it tries a different direction until the above conditions are met.
		* As long as it finds the opponent's piece, it keeps moving forward. If it finds a piece of the current player's it stops and moves backwards flipping all the pieces
		* until it finds the position it started.
		* Otherwise it again tries a different until the above conditions are met.
		*
		* \param row is the number of rows of player input
		* \param col is the number of columns of player input
		* \param playerID is the ID of the player that made the move
		*/
		void othelloMoveRegister(int row, int col, int playerID);
		/*! Funtion that prints the table to main stream
		*
		* X = black color for player 1
		* O = white color for player 2
		*/
		void othelloPrinter();
		/*! Function that writes data to the Transcipt (move memory) registering every valid move made from to the game and updates the index of the array
		*
		* \param row is x coordinates of the move that has just been made
		* \param col is y coordinates of the move that has just been made
		*/
		void moveMemoryTranscript(int row, int col);
		/*! Function that prints the transcript taking into account the value of its index
		*/
		void TranscriptPrinter();
		/*! Function that checks if the player's move is valid depending on the moveTable array created by othelloChecker
		*
		* \param row is x coordinates of the move that the player wants to make
		* \param col is y coordinates of the move that the player wants to make
		* \return true if the player can make this move, otherwise false
		*/
		bool othelloValidity(int row, int col);
		/*! Function that decides the winner depending on who has the most pieces
		*
		* \return the winner's ID
		*/
		int othelloWinChecker();
		/*! Function that counts all piecies on the othelloTable by color
		*/
		void scoreCounter();
		/*! Function that checks all directions to find all of the player's possible moves with the same logic as othelloMoveRegister()
		*
		* The possible moves are stored in moveTable array with the help of movePoints().
		*
		* \param playerID = the ID of the player whose turn is next
		*/
		void othelloChecker(int playerID);
		/*! Function that checks the position of the possible move and gives points based on its value as described below:
		*
		* Corners = 1000 points
		* Side = 100 points
		* Inside moves = 1 point
		* Adjacent to corner field = -100 points
		* "X-Squares" = -1000 points
		*
		* These points were inspired from this guide: https://bonaludo.com/2017/01/04/how-to-win-at-othello-part-1-strategy-basics-stable-discs-and-mobility/
		* The guide better explains what Adjacent to corner fields are and what "X-Squares" are.
		*
		* \param row is the row of the move that can be played and needs points
		* \param col is the column of the move that can be played and needs points
		*/
		void movePoints(int row, int col);
};
#endif