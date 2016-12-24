#ifndef chain_h
#define chain_h

/////////////////////////////////
#include <stdio.h>
#include <iostream>
#include "gemstones.h"
#include "cardfactory.h"
#include <vector>

template <class T>
class Chain {

private:
	std::vector<Card*> chainArray;
	int array_length;

public:
	
	Chain<Card*>() = default;

	Chain<Card*>(istream&, CardFactory*);

	Chain<Card*>& operator+=(Card* newCard);

	int sell();

	friend std::ostream& operator<<(ostream&, const Chain&);

	std::vector<Card*> getChainArray() {
		return chainArray;
	}

};

std::ostream& operator<<(std::ostream& _os, const Chain<Card*>& _c) { //2nd arguement mountain bike???
	Card* frontCard = _c.chainArray.front();
	_os << frontCard->getName() << " ";
	int szOfChain = static_cast<int>(_c.chainArray.size());
	for (int i = 0; i < szOfChain; ++i) {
		frontCard->print(_os);
		_os << " ";
	}
	return _os;

}
#endif