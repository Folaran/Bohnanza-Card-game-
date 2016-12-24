#ifndef deck_h
#define deck_h


#include <iostream>
#include <vector>
#include "gemstones.h"
#include "cardfactory.h"


//template <class T>//shouldnt be a template...omly chain
class Deck : public std::vector<Card*> {

private:
	//std::vector<Card*> originalDeck;
	std::vector<Card*> currentDeck;
	Card* cardPtr;

public:
	friend ostream& operator<<(ostream&, const Deck&);

	//friend Deck<Card> getDeck();

	friend class CardFactory;

	Deck() {
		//Card* cardPtr;
		cardPtr = nullptr;

	}

	//Deck(T originalDeck){
	//    cardPtr = &originalDeck;
	//}

	void shuffle();

	Card* draw();

	//ostream& operator<<(ostream& _os, const Chain& _c);

	Deck(istream&, CardFactory*);

	bool empty() const
	{
		return currentDeck.empty();
	}

	int size() const //recheck
	{
		return currentDeck.size();
	}

	friend std::ostream& operator<<(ostream&, const Deck&);

	std::vector<Card*> getCurrentDeck() { return currentDeck; }

};

std::ostream& operator<<(std::ostream& _os, const Deck& _c) {
	Card* frontCard = _c.currentDeck.front();

	_os << frontCard->getName() << " ";
	int szOfDeck = static_cast<int>(_c.currentDeck.size());
	for (int i = 0; i < szOfDeck; ++i) {
		frontCard->print(_os);
		_os << " ";

	}
	return _os;

}

#endif