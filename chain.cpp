#include "chain.h"
#include "IllegalTypeException.h"
#include "gemstones.h"
#include <iostream>
#include <fstream>
#include <iterator>


template <class T>
Chain<Card*>& Chain<T>::operator+=(Card* newCard)
{
	//const std::type_info& newCardType = typeid(*newCard);
	//const std::type_info& chainType = typeid(chainArray.front());


	if (chainArray.empty()) {
		chainArray.push_back(newCard);

		T* derivedClassCard = dynamic_cast<T*>(newCard);
		if (derivedClassCard == NULL) { // same as saying if (!derivedClassCard){ ???
			IllegalTypeExcpetion illegal;
			throw illegal;
		}
	}
	else {
		chainArray.push_back(newCard);
	}
	return *this;
}


/*
//make method for each card type....check parameter T with inclass definition of template vs type of template!
template <class T>
int Chain<T>::sell(){ //make template function for each card type
int count;
int coins;
for (auto x: chainArray){
count += 1;
}
if (count < 4){ coins = 0;}
else if (count > 3 && count < 6){ coins = 1;}
else if (count > 5 && count < 8){coins = 2;}
else if (count > 7 && count < 10){coins = 3;}
else if (count >= 10) { coins = 4;}
return coins;
//redundant.....jjust call from card
}*/

/*template <class T>
int Chain<T>::sell(){
Card::getCoins

}*/

template <>
int Chain<Card*>::sell() {
	int nCards = static_cast<int>(chainArray.size());
	Card* frontCard = chainArray.front();
	return frontCard->getCoinsPerCard(nCards);
}

template<>
Chain<Card*>::Chain<Card*>(istream& _is, CardFactory* _cf) {
	char c;
	chainArray.clear();
	if (!_is)   // Test for error.
	{
		std::cerr << "Error opening file:\n";
		exit(1);
	}
	while (!_is.eof()) {
		_is >> std::skipws >> c;
		chainArray.push_back(_cf->getCard(c)); // needs to be implemented in CardFactory
	}
}

/*istream& operator>>( istream& _is, Person& _p) {
_is >> _p.d_firstName >> _p.d_lastName >> _p.d_sin;
// check for failure
if ( !_is ) _p = Person();
return _is;
}
*/

/*template <> // full specialization, we are going to be getting cardpointer types
Chain<Card*>::Chain(const istream& _is, CardFactory* _p){ // check again
//_is >> _p->print();
for(auto c : _p) {

}
return _is;
}
*/
