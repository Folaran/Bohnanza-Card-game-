#include "discard_pile.h"

DiscardPile& DiscardPile::operator+=(Card* _c) {
	d_cards.push_back(_c);
	return *this;
}

Card* DiscardPile::pickUp() {
	Card* topCard = d_cards.back();
	d_cards.pop_back();
	return topCard;
}

Card* DiscardPile::top() const {
	return d_cards.back();
}

void DiscardPile::print(std::ostream& _os) const {
	for (auto card : d_cards) {
		card->print(_os);
		_os << " " << std::endl;
	}
	return;
}

DiscardPile::DiscardPile(std::istream& _is, CardFactory* _cf) {
	char c;
	this->d_cards.clear();
	if (!_is)   // Test for error.
	{
		std::cerr << "Error opening file:\n";
		exit(1);
	}
	while (!_is.eof()) {
		_is >> std::skipws >> c;
		this->d_cards.push_back(_cf->getCard(c)); // needs to be implemented in CardFactory
	}
}