#ifndef players_h
#define players_h

#include <string>
#include "chain.h"
#include "gemstones.h"
#include "hand.h"

using namespace std;
class Player;
ostream& operator<<(ostream&, const Player&);
class Player {
	string name;
	int coins;
	Hand* hand;
	std::vector<Chain<Card*>> chains;
public:
	Player() = default;
	/** creates player with a given name */
	Player(std::string&);
	/** get the name of the player */
	~Player();
	std::string getName() const;
	/** get the number of coins currently held by the player */
	int getNumCoins() const;
	/** get the player's hand */
	Hand* getHand();
	/** add a number of coins */
	Player& operator+=(int);
	/** returns either 2 or 3 */
	int getMaxNumChains() const;
	/** returns the number of non-zero chains */
	int getNumChains() const;
	/** returns the chain at position i */
	Chain<Card*>& operator[](int i);
	/** 
	** adds an empty third chain to the player for two coins
	** the functions reduces the coin count for the player by two
	** if the player does not have enough coins then an exception NotEnoughCoins is thrown
	*/
	void buyThirdChain();
	/** 
	** prints the top card of the player's hand (wuth argument false) 
	** or all of the player's hand (with argument true) to the supplied std::ostream
	*/
	void printHand(std::ostream&, bool);
	/**
	** insertion operator to print a Player to an std::ostream
	** player's name, the number of coins in the player's possession and each of the
	** chains (2 or 3, some possibly empty) are printed
	*/
	friend ostream& operator<<(ostream&, const Player&);
	Player(std::istream&, CardFactory*);
	std::vector<Chain<Card*>> getChains() { return chains; }
};

ostream& operator<<(ostream& _os, const Player& _p) {
	_os << _p.name << "\t" << _p.coins << "coins" << std::endl;
	for (auto chain : _p.chains) {
		_os << chain << std::endl;
	}
	return _os;
}

class NotEnoughCoins : public exception {
	virtual const char* what() const throw() {
		return "Not enough coins";
	}
};

#endif