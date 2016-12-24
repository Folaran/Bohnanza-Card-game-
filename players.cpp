#include "players.h"

Player::Player(std::string& _name) : name(_name), coins(0) {
	Hand* hand = new Hand();
}

std::string Player::getName() const {
	return name;
}

int Player::getNumCoins() const {
	return coins;
}

Hand* Player::getHand() {
	return hand;
}

Player& Player::operator+=(int _coins) {
	coins += _coins;
	return *this;
}

int Player::getMaxNumChains() const {
	int maxNumChains = 2;
	if (chains.size() == 3) maxNumChains = 3;
	return maxNumChains;
}

int Player::getNumChains() const {
	int numChains = 0;
	for (auto chain : chains) {
		if (chain.getChainArray().empty()) ++numChains;
	}
	return numChains;
}

Chain<Card*>& Player::operator[](int i) {
	return chains.at(i);
}

void Player::buyThirdChain() {
	if (this->getMaxNumChains() == 3) return; // throw exception?
	NotEnoughCoins ex;
	try {
		if (coins < 2) throw ex;
		else {
			Chain<Card*>* thirdChain = new Chain<Card*>(); // need to check
			chains.push_back(*thirdChain);
			delete thirdChain;
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

void Player::printHand(std::ostream& _os, bool arg) {
	if (!arg) {
		Card* topCard = hand->top();
		topCard->print(_os);
	}
	else {
		_os << hand;
	}
}

Player::Player(std::istream& _is, CardFactory* _cf) : coins(0) {
	/*string _name;
	if (!_is)   // Test for error.
	{
		std::cerr << "Error opening file:\n";
		exit(1);
	}
	while (!_is.eof()) {
		_is >> std::skipws >> _name;
		name = _name;
	}
	hand = new Hand(_is, _cf); */
}

Player::~Player() {
	delete hand;
}