#ifndef table_h
#define table_h

#include "players.h"
#include "trade_area.h"
#include "discard_pile.h"
#include "deck.h"

class Table {
private:

public:
	Player p1;
	Player p2;
	Deck _deck;
	DiscardPile discard;
	TradeArea trade;

	Table() = default;

	bool win(std::string& p);

	void print(std::ostream&);

	Table(std::istream&, CardFactory*);

	friend std::ostream& operator<<(ostream&, const Chain<Card*>&);

};

std::ostream& operator<<(std::ostream& _os, const Table& _table) {

	_os << _table.p1;//.getName();//_table.p1???
	_os << _table.p2; // not needed since each class has its insertion operator???
	_os << _table._deck;
	_os << _table.discard;
	_os << _table.trade;

	return _os;
}
#endif