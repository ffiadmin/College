#include "player.h"

Player::Player(string playerName, int playerColor, Deck* playerCards) : turnCard(0) {
	allCards = playerCards;
	name = playerName;
	color = playerColor;
	isActive = true;
}

bool operator == (Player& left, Player& right)
{
	return (left.getColor() == right.getColor());
}

bool operator != (Player& left, Player& right)
{
	return (left.getColor() != right.getColor());
}
	