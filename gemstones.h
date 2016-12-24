/**
* Card Hierarchy:
* The gemstone card hierarchy. A gamestone card can be printed to console
* with its first character of its name. The base class Card is abstract,
* derived classes Quartz, Hematite, Obsidian, Malachite, Turquoise, Ruby,
* Amethyst, and Emerald are concrete classes.
*/

#ifndef gemstones_h
#define gemstones_h
#include <iostream>
#include <string>
using namespace std;

enum Gemstone { Q, H, O, M, T, R, A, E };

class Card;
std::ostream& operator<<(std::ostream&, const Card*);
class Card {
/** Card has the following pure virutal functions: */
public:
	/** 
	* returns how many cards are necessary to receive
	* the corresponding number of coins 
	*/
	virtual int getCoinsPerCard(int nCards) const = 0;
	/** returns the full name of the card */
	virtual string getName() const = 0;
	/** 
	* inserts the first character of the card into
	* the output stream supplied as argument
	* will also need to create a global stream insertion
	* operator for printing any objects of such a class
	* which implements the "virtual friend function idiom"
	* with the class hierarchy
	*/
	virtual void print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream&, const Card*);
};

std::ostream& operator<<(std::ostream& _os, const Card* _c) {
	_c->print(_os);
	return _os;
}

class Quartz;
std::ostream& operator<<(std::ostream&, const Quartz*);
class Quartz : public Card {
private:
	string name{ "Quartz" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Quartz*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Quartz* _q) {
	_q->print(_os);
	return _os;
}

class Hematite;
std::ostream& operator<<(std::ostream&, const Hematite*);
class Hematite : public Card {
private:
	string name{ "Hematite" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Hematite*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Hematite* _h) {
	_h->print(_os);
	return _os;
}

class Obsidian;
std::ostream& operator<<(std::ostream&, const Obsidian*);
class Obsidian : public Card {
private:
	string name{ "Obsidian" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Obsidian*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Obsidian* _o) {
	_o->print(_os);
	return _os;
}

class Malachite;
std::ostream& operator<<(std::ostream&, const Malachite*);
class Malachite : public Card {
private:
	string name{ "Malachite" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Malachite*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Malachite* _m) {
	_m->print(_os);
	return _os;
}

class Turquoise;
std::ostream& operator<<(std::ostream&, const Turquoise*);
class Turquoise : public Card {
private:
	string name{ "Turquoise" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Turquoise*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Turquoise* _t) {
	_t->print(_os);
	return _os;
}

class Ruby;
std::ostream& operator<<(std::ostream&, const Ruby*);
class Ruby : public Card {
private:
	string name{ "Ruby" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Ruby*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Ruby* _r) {
	_r->print(_os);
	return _os;
}

class Amethyst;
std::ostream& operator<<(std::ostream&, const Amethyst*);
class Amethyst : public Card {
private:
	string name{ "Amethyst" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Amethyst*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Amethyst* _a) {
	_a->print(_os);
	return _os;
}

class Emerald;
std::ostream& operator<<(std::ostream&, const Emerald*);
class Emerald : public Card {
private:
	string name{ "Emerald" };
public:
	int getCoinsPerCard(int nCards) const;
	string getName() const;
	friend std::ostream& operator<<(std::ostream&, const Emerald*);
	void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& _os, const Emerald* _e) {
	_e->print(_os);
	return _os;
}
#endif