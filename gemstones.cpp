#include "gemstones.h"

int Quartz::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 4) { numCoins = 0; }
	if (nCards == 4 || nCards == 5) { numCoins = 1; }
	if (nCards == 6 || nCards == 7) { numCoins = 2; }
	if (nCards == 8 || nCards == 9) { numCoins = 3; }
	if (nCards >= 10) { numCoins = 4; }
	return numCoins;
}

string Quartz::getName() const {
	return name;
}

void Quartz::print(std::ostream& out) const {
	out << Gemstone::Q;
	return;
}

int Hematite::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 3) { numCoins = 0; }
	if (nCards >= 3 && nCards <= 5) { numCoins = 1; }
	if (nCards == 6 || nCards == 7) { numCoins = 2; }
	if (nCards == 8) { numCoins = 3; }
	if (nCards >= 9) { numCoins = 4; }
	return numCoins;
}

string Hematite::getName() const {
	return name;
}

void Hematite::print(std::ostream& out) const {
	out << Gemstone::H;
	return;
}

int Obsidian::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 3) { numCoins = 0; }
	if (nCards == 3 || nCards == 4) { numCoins = 1; }
	if (nCards == 5 || nCards == 6) { numCoins = 2; }
	if (nCards == 7) { numCoins = 3; }
	if (nCards >= 8) { numCoins = 4; }
	return numCoins;
}

string Obsidian::getName() const {
	return name;
}

void Obsidian::print(std::ostream& out) const {
	out << Gemstone::O;
	return;
}

int Malachite::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 3) { numCoins = 0; }
	if (nCards == 3 || nCards == 4) { numCoins = 1; }
	if (nCards == 5) { numCoins = 2; }
	if (nCards == 6) { numCoins = 3; }
	if (nCards >= 7) { numCoins = 4; }
	return numCoins;
}

string Malachite::getName() const {
	return name;
}

void Malachite::print(std::ostream& out) const {
	out << Gemstone::M;
	return;
}

int Turquoise::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 2) { numCoins = 0; }
	if (nCards == 2 || nCards == 3) { numCoins = 1; }
	if (nCards == 4 || nCards == 5) { numCoins = 2; }
	if (nCards == 6) { numCoins = 3; }
	if (nCards >= 7) { numCoins = 4; }
	return numCoins;
}

string Turquoise::getName() const {
	return name;
}

void Turquoise::print(std::ostream& out) const {
	out << Gemstone::T;
	return;
}

int Ruby::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 2) { numCoins = 0; }
	if (nCards == 2 || nCards == 3) { numCoins = 1; }
	if (nCards == 4) { numCoins = 2; }
	if (nCards == 5) { numCoins = 3; }
	if (nCards >= 6) { numCoins = 4; }
	return numCoins;
}

string Ruby::getName() const {
	return name;
}

void Ruby::print(std::ostream& out) const {
	out << Gemstone::R;
	return;
}

int Amethyst::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 2) { numCoins = 0; }
	if (nCards == 2) { numCoins = 1; }
	if (nCards == 3) { numCoins = 2; }
	if (nCards == 4) { numCoins = 3; }
	if (nCards >= 5) { numCoins = 4; }
	return numCoins;
}

string Amethyst::getName() const {
	return name;
}

void Amethyst::print(std::ostream& out) const {
	out << Gemstone::A;
	return;
}

int Emerald::getCoinsPerCard(int nCards) const {
	int numCoins;
	if (nCards < 2) { numCoins = 0; }
	if (nCards == 2) { numCoins = 2; }
	if (nCards >= 3) { numCoins = 3; }
	return numCoins;
}

string Emerald::getName() const {
	return name;
}

void Emerald::print(std::ostream& out) const {
	out << Gemstone::E;
	return;
}