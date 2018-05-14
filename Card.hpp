#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

class Card {
public:
	Card(std::string suit, std::string face, int value);
	std::string PrintInfo();
	int GetValue();
private:
	std::string suit;
	std::string face;
	int value;
};

#endif

/*
	* Card is the basic class used for the program - the Deck is filled with 52 Card objects. Constructor takes in the suit, face, and an integer value for the card.
	* Direct access to suit and face is never needed, so there is no need for getter functions to do so. 
	* PrintInfo() returns a string including the suit and face of the card for output in Main.
*/