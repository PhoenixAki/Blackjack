#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <vector>
#include <algorithm>

class Deck {
public:
	Deck();
	Card* Draw();
private:
	std::vector<Card*> deck;
	std::string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	std::string faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
};

#endif

/*
	* Deck is one of the 2 main classes used in the game's function, alongside Player. Holds a vector of pointers to Card objects that act as a deck of 52 cards.
	* Draw() pops (removes) the last Card* object from the vector and returns it. 
	* Technically this isn't a real life "draw" of the deck since it pulls from the end of the vector instead of the top.
	* suits and faces are initialized here and used in the constructor to apply the appropriate suit/face information to the cards created.
*/