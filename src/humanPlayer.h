#pragma once
#ifndef _HUMANPLAYER
#define _HUMANPLAYER
#include "othello.h"
#include "player.h"
//---------------------------------------- class HumanPlayer ----------------------------------------
/*! It is the class that represents the human player of the game and inherits from the Player class.
*/
class HumanPlayer : public Player {
	public:
		/*! Default Constructor
		*/
		HumanPlayer() = default;
		/*! Default Destructor
		*/
		~HumanPlayer() = default;
		/*! Function that lets the human player add a piece to the board
		*/
		void addPiece(Othello &othello, int playerID);
};
#endif