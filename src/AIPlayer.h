#pragma once
#ifndef _AIPLAYER
#define _AIPLAYER
#include "othello.h"
#include "player.h"
//---------------------------------------- class AIPlayer ----------------------------------------
/*! It is the class that represents the AI player of the game and inherits from the Player class.
*
*It has a variable that stores the AI player's minimax depth.
*/
class AIPlayer : public Player {
	private:
		int AIDepth;
	public:
		/*! Default Constructor
		*/
		AIPlayer() = default;
		/*! Default Constructor
		*/
		~AIPlayer() = default;
		/*! Function that sets the AI's depth
		*/
		void AISetDepth(int depth);
		/*! Function that lets the AI player add a piece to the board
		*/
		void addPiece(Othello &othello, int playerID);
		/*! Function that returns the best value using the recursive minimax algorithm and a-b pruning
		*/
		int minimax(Othello &othello, int originalID, int currentID, int a, int b, int depth, int value);
		/*! Function that returns the value of the othello heuristic
		*/
		int heuristic(Othello &othello, int value, int playerID);
		/*! Function that returns true if the player has available moves or else returns false
		*/
		bool hasMoves(Othello &othello, int playerID);
};
#endif