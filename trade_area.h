/** 
** Holds cards openly and supports random access insertion and removal.
** The TradeArea holds cards in a std::list.
*/

#ifndef trade_area_h
#define trade_area_h

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "gemstones.h"
#include "CardFactory.h"

using namespace std;

class TradeArea;
ostream& operator<<(ostream&, const TradeArea&);
class TradeArea {
	std::list<Card*> t_cards;
public:
	TradeArea() = default;
	/** adds the card to the trade area but it does not check if
	** it is legal to place the card
	*/
	TradeArea& operator+=(Card*);
	/** 
	** returns true if the card can be legally added to the 
	** TradeArea, i.e. a card of the same gemstone is already in
	** the TradeArea
	*/
	bool legal(Card*) const;
	/** removes a card of the corresponding gemstone name from the
	** trade area
	*/
	Card* trade(string);
	/** returns the number of cards currently in the trade area */
	int numCards() const;
	/** inserts all the cards of the trade area to an std::ostream*/
	friend ostream& operator<<(ostream&, const TradeArea&);
	/** constructor which reconstructs the TradeArea from file */
	TradeArea(std::istream&, CardFactory*);
	std::list<Card*> getTradeAreaCards() { return t_cards; }
};

ostream& operator<<(ostream& _os, const TradeArea& _ta) {
	for (auto card : _ta.t_cards) {
		card->print(_os);
		_os << " ";
	}
	return _os;
}

#endif