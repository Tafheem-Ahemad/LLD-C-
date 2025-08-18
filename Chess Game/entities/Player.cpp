#include "Player.hpp"

Player::Player(const string &id, const string name, PieceType pieceType)
	: id(id), name(name), pieceType(pieceType) {}

PieceType Player::getPieceType() const {
	return pieceType;
}

string Player::getName() const {
	return name;
}
string Player::getId() const {
	return id;
}