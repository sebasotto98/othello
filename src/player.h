#pragma once
#ifndef _PLAYER
#define _PLAYER
#include "othello.h"
//---------------------------------------- class Player ----------------------------------------
/*! It is the class that represents the player of the game which will later be converted to AI or human accordingly.
*
*It has a variable that stores the player's ID.
*/
class Player {
	protected:
		int playerID;
	public:
		/*! Default Constructor
		*/
		Player();
		/*! Default Destructor
		*/
		~Player();
		/*! Function that returns the player's ID
		*/
		int playerGetID();
};
#endif