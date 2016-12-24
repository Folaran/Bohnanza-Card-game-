#include "cardfactory.h"
#include "chain.h"
#include "deck.h"
#include "discard_pile.h"
#include "gemstones.h"
#include "hand.h"
#include "players.h"
#include "table.h"
#include "trade_area.h"

int main() {
	
	CardFactory* cardFactory = CardFactory::getFactory();
	Deck gameDeck = cardFactory->getDeck();
	TradeArea gameTradeArea = *new TradeArea();
	DiscardPile gameDiscardPile = *new DiscardPile();
	Player* p1;  
	Player* p2;
	Hand p1Hand = *p1->getHand();
	Hand p2Hand = *p2->getHand();
	string choice;
	
	while (choice != "y" || choice != "n") {
		cout << "Load paused game from file? (y/n): ";
		cin >> choice;
		cout << endl;
	}
	
	if (choice == "n") {
		string p1Name, p2Name;
		cout << "Enter the name of the first player : ";
		cin >> p1Name;
		cout << endl;
		cout << "Enter the name of the second player: ";
		cin >> p2Name;
		cout << endl;
		p1 = new Player(p1Name);
		p2 = new Player(p2Name);
		for (int i = 0; i < 5; ++i) {
			Card* card1 = gameDeck.getCurrentDeck.draw();
			Card* card2 = gameDeck.getCurrentDeck.draw();
			p1Hand.getHandQueue().push(card1);
			p2Hand.getHandQueue().push(card2);
		}
	}
	
	else {
		// load paused game from file
	}
	
	bool paused = false;

	while (!gameDeck.getCurrentDeck().empty()) {

		if (paused) {
			// save game to file and exit
		}

		// player 1 gameplay

		Table* gameTable = new Table();
		gameTable->print(cout);

		string chainChoice1;

		while (chainChoice1 != "y" || chainChoice1 != "n") {
			cout << "Player 1: buy a third chain? (y/n): ";
			cin >> chainChoice1;
			cout << endl;
		}

		if (chainChoice1 == "y" && p1->getNumCoins() >= 3) {
			p1->buyThirdChain();
		}

		else if (chainChoice1 == "y" && p1->getNumCoins() < 3) {
			throw NotEnoughCoins();
		}


		Card* drawCard1 = gameDeck.getCurrentDeck.draw();
		p1Hand.getHandQueue().push(drawCard1);

		std::vector<Chain<Card*>> p1chains = p1->getChains();

		if (gameTradeArea.numCards > 0) {
			std::vector<Card*> tradeAreaCards = gameTradeArea.getTradeAreaCards;
			for (auto card : tradeAreaCards) {
				for (auto chain : p1chains) {
					bool exceptionThrown = false;
					try {
						chain += (card);
					}
					catch (std::exception& e) {
						exceptionThrown = true;
					}
					if (!exceptionThrown) break;
				}
				gameDiscardPile += (card);
			}
		}

		for (auto chain : p1chains) {
			bool exceptionThrown = false;
			try {
				chain += (p1Hand.top);
			}
			catch (std::exception& e) {
				exceptionThrown = true;
			}
			if (!exceptionThrown) break;
		}

		for (auto chain : p1chains) {
			int coinsReceived = chain.sell;
			if (coinsReceived > 0) {
				p1 += (coinsReceived);
				for (auto card : chain.getChainArray) {
					gameDiscardPile += (card);
				}
			}
		}

		string decision;
		while (decision != "y" || decision != "n") {
			cout << "Player 1: Play topmost card again? (y/n): ";
			cin >> decision;
			cout << endl;
		}
		
		if (decision == "y") {
			for (auto chain : p1chains) {
				int coinsReceived = chain.sell;
				if (coinsReceived > 0) {
					p1 += (coinsReceived);
					for (auto card : chain.getChainArray) {
						gameDiscardPile += (card);
					}
				}
			}
		}

		string showHand;
		while (showHand != "y" || showHand != "n") {
			cout << "Player 1: Show full hand? (y/n): ";
			cin >> showHand;
			cout << endl;
		}
		if (showHand == "y") {
			int index;
			cout << p1Hand;
			while (index < 0 || index > p1Hand.getHandQueue.size()) {
				cout << "Index of card to remove? ";
				cin >> index;
			}
			gameDiscardPile += (p1Hand[index]);
		}

		for (int i = 0; i < 3; ++i) {
			gameTradeArea += gameDeck.getCurrentDeck.draw();
		}

		while (gameTradeArea.legal(gameDiscardPile.top)) {
			gameTradeArea += gameDiscardPile.pickUp();
		}

		for (auto card : gameTradeArea.getTradeAreaCards) {
			string chainCard;
			while (chainCard != "y" || chainCard != "n") {
				cout << "Player 1: Chain the card? (y/n): ";
				cin >> chainCard;
				cout << endl;
			}
			if (chainCard == "y") {
				for (auto chain : p1chains) {
					bool exceptionThrown = false;
					try {
						chain += (card);
					}
					catch (std::exception& e) {
						exceptionThrown = true;
					}
					if (!exceptionThrown) break;
				}
				
				for (auto chain : p1chains) {
					int coinsReceived = chain.sell;
					if (coinsReceived > 0) {
						p1 += (coinsReceived);
						for (auto card : chain.getChainArray) {
							gameDiscardPile += (card);
						}
					}
				}
			}
		}

		for (int i = 0; i < 2; ++i) {
			p1Hand += (gameDeck.getCurrentDeck.draw);
		}

		// copy above for player 2

	}
	
	return 0;
}