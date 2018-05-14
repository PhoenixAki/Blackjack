#include "Card.hpp"

Card::Card(std::string suit, std::string face, int value){
	this->suit = suit;
	this->face = face;

	//For Jack/Queen/King, the value is passed in as 11/12/13 as a result of Deck being created in a for loop - this resets their values back to 10.
	if(value > 10)
		value = 10;

	this->value = value;
}

int Card::GetValue(){
	return value;
}

std::string Card::PrintInfo(){
	return this->face + " of " + this->suit;
}