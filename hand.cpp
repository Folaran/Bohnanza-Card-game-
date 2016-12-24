#include <stdio.h>
#include "hand.h"
#include "gemstones.h"
#include "cardfactory.h"
#include <iostream>
#include <fstream>
#include <string>


Card* Hand::operator[](int i) 
{
	std::vector<Card*> handVector;
	while (!handQueue.empty()) { //empty queue
		handVector.push_back(handQueue.front());
		handQueue.pop();
	}
	/*for (std::vector<Card>::iterator it = handVector.begin(); it != handVector.end(); ++it) { //put queue back in place
		handQueue.push(*it);
	}*/
	for (auto card : handVector) {
		handQueue.push(card);
	}
	return handVector[i];
}


Card* Hand::play()
{
	Card* playedHand = handQueue.front();
	handQueue.pop();
	return playedHand;
}


Card* Hand::top()
{
	Card* topCard = handQueue.front();
	return topCard;
}


Hand& Hand::operator+=(Card* rearCard)
{
	handQueue.push(rearCard);
	return *this;
}

Hand::Hand(std::istream& _is, CardFactory* _cf)// load
{
	char c;
	while (!handQueue.empty()) {
		handQueue.pop();
	}
	if (!_is)   // Test for error.
	{
		std::cerr << "Error opening file:\n";
		exit(1);
	}
	while (!_is.eof()) {
		_is >> std::skipws >> c;
		handQueue.push(_cf->getCard(c)); // needs to be implemented in CardFactory
	}
}