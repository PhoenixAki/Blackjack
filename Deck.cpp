#include "Deck.hpp"

Deck::Deck(){
	//Relatively simple nested for loop to initialized 52 cards (13 per suit).
	//Worth noting, Aces are initialized into the deck with a value of 1 by default, even though they can also be 11.
	//When the hand total is calculated (in Player.cpp), the value of an Ace in the hand is dynamically determined.
	for(int a = 0; a < 4; a++){
		for(int b = 0; b < 13; b++){
			deck.push_back(new Card(suits[a], faces[b], b+1));
		}
	}

	std::random_shuffle(deck.begin(), deck.end());
}

Card* Deck::Draw(){
	Card* card = deck[deck.size()-1];
	deck.pop_back();
	return card;
}