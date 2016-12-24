#include "deck.h"
#include "gemstones.h"

Card* Deck::draw() {
	Card* top;
	top = currentDeck.back();
	currentDeck.pop_back();
	return top;
}


void Deck::shuffle()
{
	if (!currentDeck.empty()) {
		std::random_shuffle(currentDeck.begin(), currentDeck.end());
	}
}

Deck::Deck(istream& _is, CardFactory* _cf) {
	char c;
	currentDeck.clear();
	if (!_is)   // Test for error.
	{
		std::cerr << "Error opening file:\n";
		exit(1);
	}
	while (!_is.eof()) {
		_is >> std::skipws >> c;
		currentDeck.push_back(_cf->getCard(c));
	}
}

//Also add the insertion operator to insert all the cards in the deck to an std::ostream.