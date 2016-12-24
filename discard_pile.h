/** The DiscardPile holds cards in a std::vector and is similar to Deck. */

#ifndef discard_pile_h
#define discard_pile_h

#include <iostream>
#include <vector>
#include <string>

#include "gemstones.h"
#include "CardFactory.h"

using namespace std;

class DiscardPile;
ostream& operator<<(ostream&, const DiscardPile&);
class DiscardPile {
	std::vector<Card*> d_cards;
public:
	DiscardPile() = default;
	/** discards the card to the pile */
	DiscardPile& operator+=(Card*);
	/** returns and removes the top card from the discard pile */
	Card* pickUp();
	/** returns but does not remove the top card from the discard pile */
	Card* top() const;
	/** inserts all the cards in the DiscardPile to an std::ostream */
	void print(std::ostream&) const;
	/** inserts only the top card of of the discard pile to an std::ostream */
	friend ostream& operator<<(ostream&, const DiscardPile&);
	/** constructor reconstructs the DiscardPile from file */
	DiscardPile(std::istream&, CardFactory*);
	std::vector<Card*> getDiscardPileCards() { return d_cards; }
};

ostream& operator<<(ostream& _os, const DiscardPile& _dp) {
	Card* topCard = _dp.d_cards.back();
	topCard->print(_os);
	return _os;
}

#endif