#include "Player.hpp"

Player::Player(std::string name){
	this->name = name;
}

void Player::AddCard(Card* card, bool playerTurn){
	//Differentiating output for player or dealer.
	
	if(name == "Player"){
		std::cout << card->PrintInfo() << " added to player's hand.\n";
	}else if(name == "Dealer" && hand.size() == 0 && playerTurn){
		std::cout << "First card drawn to dealer's hand (hidden until your turn is done).\n";
	}else{
		std::cout << card->PrintInfo() << " added to dealer's hand.\n";
	}

	this->hand.push_back(card);
}

std::string Player::DisplayHand(bool playerTurn){
	std::string handString;

	for(int i = 0; i < hand.size(); ++i){
		//Increment i to 1 if the first (hidden) card of the Dealer's hand would be displayed, while on the player's turn.
		if(name == "Dealer" && i == 0 && playerTurn)
			++i;

		//Adjusting formatting (ending with a comma or not) depending on if there are more cards in the hand).
		i == hand.size()-1 ? handString += hand[i]->PrintInfo() : handString+= hand[i]->PrintInfo() + ", ";
	}

	return handString;
}

int Player::GetTotal(bool playerTurn){
	int total = 0;

	for(int i = 0; i < hand.size(); ++i){
		//Similar to above, incrementing i to skip adding the first (hidden) card of the Dealer's hand to the total, if it's the player's turn.
		if(name == "Dealer" && i == 0 && playerTurn)
			++i;

		//Aces are default created with a value of 1. If an Ace is found to be in the player/dealer's hand, its value is dynamically determined here to adjust to 11 if it would be beneficial.
		if(hand[i]->GetValue() != 1){
			total += hand[i]->GetValue();
		}else if(total + 11 > 21){
				total += 1;
		}else{
			total += 11;
		}
	}

	return total;
}