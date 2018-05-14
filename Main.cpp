#include "Deck.hpp"
#include "Player.hpp"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));

	bool playerDone = false, dealerDone = false;

	//Creating deck of 52 cards before game starts. Deck is shuffled at the end of the Deck constructor.
	Deck* deck = new Deck();
	//Creating default player with an empty hand. Dealer is also of type Player as their functions are identical.
	Player* player = new Player("Player");
	Player* dealer = new Player("Dealer");

	//Drawing the first 2 cards for the player's hand.
	std::cout << "Welcome to Blackjack!" << std::endl << std::endl << "Drawing cards to the player's hand..." << std::endl;
	player->AddCard(deck->Draw(), true);
	player->AddCard(deck->Draw(), true);

	//Drawing the first 2 cards for the dealer's hand (only the second one is displayed to the player).
	std::cout << "\nDrawing cards to the dealer's hand..." << std::endl;
	dealer->AddCard(deck->Draw(), true);
	dealer->AddCard(deck->Draw(), true);
	std::cout << std::endl;


	//Player's turn - will continue to loop until the player opts to Stay (or until they either bust or go over 21), at which point it moves to the Dealer's turn.
	do{
		std::cout << "Choose your move!\n1) Display your hand\n2) Display dealer's hand\n3) Hit\n4) Stay\n5) Exit\nChoice: ";
		char choice;
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice){
			case '1':
				std::cout << "Player's hand:\n" << player->DisplayHand(true) << std::endl << "Hand Value: " << player->GetTotal(true) << "\n\n";
				break;
			case '2':
				std::cout << "Dealer's hand:\n" << dealer->DisplayHand(true) << std::endl << "Hand Value: " << dealer->GetTotal(true) << "\n\n";
				break;
			case '3':
				{
					Card* newCard = deck->Draw();
					std::cout << "Drawing a card...";
					player->AddCard(newCard, true);
					std::cout << "\n";
				}
				break;
			case '4':
				{
					//Sets playerDone to be true to force the player's turn to be done after this iteration of the do-while.
					std::cout << "Staying - your final hand total is " << player->GetTotal(true) << ".\n\n";
					playerDone = true;
				}
				break;
			case '5':
				std::cout << "Exiting game." << std::endl;
				return 0;
			default:
				std::cout << "Invalid choice - must be 1-5." << std::endl << std::endl;
				break;
		}

		//If the player stayed, this check won't happen. Checks that if the player's total is 21+, their turn is automatically finished.
		if(!playerDone && player->GetTotal(true) >= 21){
			std::cout << "Your hand total is 21 or higher, so your turn is now over.\n\n";
			playerDone = true;
		}
	}while(playerDone == false);


	std::cout << "Dealer's hand (including the hidden card) is:\n" << dealer->DisplayHand(false) << "\nHand Value: " << dealer->GetTotal(false);
	std::cout << "\nDealer will now take their turn.\n\n";

	//Dealer's turn - will continue to draw while their score is >= 17, at which point they are required to stay. Results will be determined then.
	while(dealer->GetTotal(false) < 17){
		dealer->AddCard(deck->Draw(), false);
		if(dealer->GetTotal(false) >= 17){
			std::cout << "Dealer's hand total is " << dealer->GetTotal(false) << ", so they must now Stay.\n";
			dealerDone = true;
		}else if(dealer->GetTotal(false) < 17){
			std::cout << "Dealer's hand total is " << dealer->GetTotal(false) << ", so they must now Hit again.\n";
		}
	}


	//Determining outcome based on the player and dealer's hands.
	std::cout << "Your final hand total is " << player->GetTotal(false) << " and the dealer's final hand total is " << dealer->GetTotal(false) << ".\n";

	//Cases where both the player and dealer have legitimate hand totals (under 21), or when both are over 21.
	if(player->GetTotal(false) < 21 && dealer->GetTotal(false) < 21){
		if(player->GetTotal(false) > dealer->GetTotal(false)){
			std::cout << "You win! Thanks for playing!\n";
			return 0;
		}else if(player->GetTotal(false) < dealer->GetTotal(false)){
			std::cout << "Dealer wins! Thanks for playing!\n";
			return 0;
		}else{
			std::cout << "Tie! Thanks for playing!\n";
			return 0;
		}
	}else if(player->GetTotal(false) > 21 && dealer->GetTotal(false) > 21){
		std::cout << "Tie! Thanks for playing!\n";
		return 0;
	}

	//Cases where either the player or dealer have exactly 21 points.
	if(player->GetTotal(false) == 21){
		if(dealer->GetTotal(false) == 21){
			std::cout << "Tie! Thanks for playing!\n";
			return 0;
		}else if(dealer->GetTotal(false) != 21){
			std::cout << "You win! Thanks for playing!\n";
			return 0;
		}
	}else if(dealer->GetTotal(false) == 21 && player->GetTotal(false) != 21){
		std::cout << "Dealer wins! Thanks for playing!\n";
		return 0;
	}

	//Cases where either the player or dealer have more than 21 points while the other has less than 21 points.
	if(player->GetTotal(false) > 21 && dealer->GetTotal(false) < 21){
		std::cout << "Dealer wins! Thanks for playing!\n";
		return 0;
	}else if(player->GetTotal(false) < 21 && dealer->GetTotal(false) > 21){
		std::cout << "You win! Thanks for playing!\n";
		return 0;
	}

	std::cout << "\n\nRuh-roh";
}