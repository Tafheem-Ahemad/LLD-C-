#include "Player.hpp"

Player::Player(const string &name, const Symbol &symbol) : name(name), symbol(symbol) {}

string Player::getName() const {
	return name;
}

Symbol Player::getSymbol() const {
	return symbol;
}