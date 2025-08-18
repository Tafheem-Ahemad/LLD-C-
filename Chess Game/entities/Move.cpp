#include "Move.hpp"

Move::Move(const Position source, const Position destination, const Player* player)
	: source(source), destination(destination), player(const_cast<Player*>(player)) {}

Position Move::getSource() const {
	return source;
}

Position Move::getDestination() const {
	return destination;
}

Player* Move::getPlayer() const {
	return player;
}