#include <stdio.h>
#include "cardfactory.h"
#include "gemstones.h"
#include "deck.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

CardFactory* CardFactory::getFactory()//make sure it only makes it once...make local variable and check if its null
{
	if (onlyInstance == NULL)
	{
		onlyInstance = new CardFactory();
		CardFactory* cardFactoryPtr;
		cardFactoryPtr = onlyInstance;
		return cardFactoryPtr;
	}
}

Deck CardFactory::getDeck()//push back by pointers not to duplicate
{
	Deck testing;
	//Deck<Card*> *testing;
	testing.resize(104);
	//testing.originalDeck.resize(104);
	for (auto a : quartzCards)
		testing.push_back(&a);
	for (auto b : hematiteCards)
		testing.push_back(&b);
	for (auto c : obsidianCards)
		testing.push_back(&c);
	for (auto d : malachiteCards)
		testing.push_back(&d);
	for (auto e : turquoiseCards)
		testing.push_back(&e);
	for (auto f : rubyCards)
		testing.push_back(&f);
	for (auto g : amethystCards)
		testing.push_back(&g);
	for (auto h : emeraldCards)
		testing.push_back(&h);
	testing.shuffle();
	return testing;

}

Card* CardFactory::getCard(char gemStone) {
	if (gemStone == 'Q') {
		Quartz* q = &quartzCards.front();
		return q;
	}
	if (gemStone == 'H') {
		Hematite* h = &hematiteCards.front();
		return h;
	}
	if (gemStone == 'O') {
		Obsidian* o = &obsidianCards.front();
		return o;
	}
	if (gemStone == 'M') {
		Malachite* m = &malachiteCards.front();
		return m;
	}
	if (gemStone == 'T') {
		Turquoise* t = &turquoiseCards.front();
		return t;
	}
	if (gemStone == 'R') {
		Ruby* r = &rubyCards.front();
		return r;
	}
	if (gemStone == 'A') {
		Amethyst* a = &amethystCards.front();
		return a;
	}
	if (gemStone == 'E') {
		Emerald* e = &emeraldCards.front();
		return e;
	}
}

CardFactory::~CardFactory()
{
	delete onlyInstance;
	delete cardFactoryPtr;
}