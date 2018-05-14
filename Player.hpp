#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Card.hpp"
#include <vector>

class Player {
public:
	Player(std::string name);
	void AddCard(Card* card, bool playerTurn);
	int GetTotal(bool playerTurn);
	std::string DisplayHand(bool playerTurn);
private:
	std::vector<Card*> hand;
	std::string name;
};

#endif

/*
	* Player is used to create both the player and dealer objects in main. It was a design choice to have the dealer also be a Player object, instead of having its own class.
	* The variations between how the functions differentiate for player/dealer were small enough that I felt it was redundant to make Dealer its own class instead of just working around it here.
	* Each function here takes in a bool playerTurn, which determines whether it is the player's turn - this only matters when it's the Dealer to hide/un-hide the first card in their hand.
	* Constructor only takes in a name value that is also used to determine whether the object is the player or the dealer.
*/