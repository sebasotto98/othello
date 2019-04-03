#include "player.h"
static int players = 0;
Player::Player() {
	if (players == 0) {
		playerID = 1;
		players++;
	}
	else {
		playerID = 2;
		players++;
	}
};
Player::~Player() {
	players--;
}
int Player::playerGetID() {
	return playerID;
}