#include "Cell.hpp"

Cell::Cell(const Color color) : piece(nullptr), Empty(true), color(color) {}

Cell::~Cell() {
	delete piece; // Clean up the piece if it exists
}

bool Cell::isEmpty() const {
	return Empty;
}

void Cell::makeEmpty() {
	piece = nullptr;
	Empty = true;	
}

Piece* Cell::getPiece() const {
	return piece;
}
void Cell::setPiece(Piece* piece) {
	if (this->piece != nullptr) {
		throw runtime_error("Cell already contains a piece.");
	}
	this->piece = piece;
	Empty = false;
}

Color Cell::getColor() const {
	return color;
}