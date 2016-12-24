#include "trade_area.h"

TradeArea& TradeArea::operator+=(Card* _c) {
	if (legal(_c)) t_cards.push_back(_c); // is this necessary?
	return *this;
}

bool TradeArea::legal(Card* _c) const {
	bool legal = (std::find(this->t_cards.begin(), this->t_cards.end(), _c) != this->t_cards.end());
	return legal;
	/*bool legal = false;
	for (auto card : t_cards) {
		Quartz* p1 = dynamic_cast<Quartz*>(_c);
		Quartz* p2 = dynamic_cast<Quartz*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Hematite* p1 = dynamic_cast<Hematite*>(_c);
		Hematite* p2 = dynamic_cast<Hematite*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Obsidian* p1 = dynamic_cast<Obsidian*>(_c);
		Obsidian* p2 = dynamic_cast<Obsidian*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Malachite* p1 = dynamic_cast<Malachite*>(_c);
		Malachite* p2 = dynamic_cast<Malachite*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Turquoise* p1 = dynamic_cast<Turquoise*>(_c);
		Turquoise* p2 = dynamic_cast<Turquoise*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Ruby* p1 = dynamic_cast<Ruby*>(_c);
		Ruby* p2 = dynamic_cast<Ruby*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Amethyst* p1 = dynamic_cast<Amethyst*>(_c);
		Amethyst* p2 = dynamic_cast<Amethyst*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;

		Emerald* p1 = dynamic_cast<Emerald*>(_c);
		Emerald* p2 = dynamic_cast<Emerald*>(card);
		if (p1 != NULL && p2 != NULL) legal = true;
		break;
	}*/
}

Card* TradeArea::trade(string _name) {
	Card* removed;
	for (auto card : t_cards) {
		if (card->getName().compare(_name) > 0) {
			removed = card;
			t_cards.remove(card);
		}
		break;
	}
	return removed;
}

int TradeArea::numCards() const {
	return t_cards.size();
}

TradeArea::TradeArea(std::istream& _is, CardFactory* _cf) {
	char c;
	t_cards.clear();
	if (!_is)   // Test for error.
	{
		std::cerr << "Error opening file:\n";
		exit(1);
	}
	while (!_is.eof()) {
		_is >> std::skipws >> c;
		t_cards.push_back(_cf->getCard(c));
	}
}