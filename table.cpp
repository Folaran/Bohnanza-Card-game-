#include "table.h"

bool Table::win(std::string& p) {
	if (_deck.getCurrentDeck().empty()) {
		if (p == p1.getName() && (p1.getNumCoins() > p2.getNumCoins())) {
			std::cout << p << std::endl;
			return true;
		}
		else if (p == p2.getName() && (p1.getNumCoins() < p2.getNumCoins())) {
			std::cout << p << std::endl;
			return true;
		}
	}
}

void Table::print(std::ostream& _os) {
	_os << *this; // ok...
}

Table::Table(std::istream& _is, CardFactory* _cf) { // ok...
	/*p1 = Player(_is, _cf);
	p2 = Player(_is, _cf);
	_deck = Deck(_is, _cf);
	discard = DiscardPile(_is, _cf);
	trade = TradeArea(_is, _cf);*/
}