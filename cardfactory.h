#ifndef cardfactory_h
#define cardfactory_h

#include "deck.h"
#include "gemstones.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "hand.h"

class Deck;
class CardFactory {
private:
	static CardFactory* onlyInstance;

	std::vector<Quartz> quartzCards;
	std::vector<Hematite> hematiteCards;
	std::vector<Obsidian> obsidianCards;
	std::vector<Malachite> malachiteCards;
	std::vector<Turquoise> turquoiseCards;
	std::vector<Ruby> rubyCards;
	std::vector<Amethyst> amethystCards;
	std::vector<Emerald> emeraldCards;

	CardFactory()
	{
		const std::vector<Quartz> quartzCards(20);
		const std::vector<Hematite> hematiteCards(18);
		const std::vector<Obsidian> obsidianCards(16);
		const std::vector<Malachite> malachiteCards(14);
		const std::vector<Turquoise> turquoiseCards(12);
		const std::vector<Ruby> rubyCards(10);
		const std::vector<Amethyst> amethystCards(8);
		const std::vector<Emerald> emeraldCards(6);
	}

public:

	//friend Hand(std::ostream& _os, CardFactory* _s);
	//friend Hand(std::ostream& _is, CardFactory* _l);
	//friend bool legal(Card* _l);//no scoping???....Amir is doing this now
	//CardFactory() = default;
	CardFactory* cardFactoryPtr;
	Deck getDeck();
	static CardFactory* getFactory(); // static cos even when not created, getter can be accessed
	~CardFactory();
	Card* getCard(char gemstone);

};
#endif