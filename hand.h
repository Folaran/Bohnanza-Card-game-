#ifndef hand_h
#define hand_h
#include "gemstones.h"
#include <queue>
#include "cardfactory.h"

class CardFactory;

class Hand {
private:
	queue<Card*> handQueue;// ok...
public:
	Hand() = default;

	//constructor

	//destructor

	//include Hand(const std::istream&, Cardfactor*);

	Hand& operator+=(Card*);

	Card* play();

	Card* top();

	Hand(std::istream&, CardFactory*); //made this void, so I can declare it as friend in CardFactory, as it needs specifier. Also changed from hand to save cos costructor cant have return type

	//void print(std::ostream&);

	//Card discardCard(int index); //Card*
	
	Card* operator[](int);

	queue<Card*> getHandQueue() const { return handQueue; }


								 //should be sorted
};

std::ostream& operator<<(std::ostream& _os, const Hand& _h) {
	Card* frontCard = _h.getHandQueue().front();

	_os << frontCard->getName() << " ";
	int szOfQueue = static_cast<int>(_h.getHandQueue().size());
	for (int i = 0; i < szOfQueue; ++i) {
		frontCard->print(_os);
		_os << " ";

	}
	return _os;

}

#endif