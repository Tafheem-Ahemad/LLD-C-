#include "Board.hpp"

Board::Board(int size, CellColor color1, CellColor color2)
	: size(size), color1(color1), color2(color2) {
	initializeBoard();
}

Board::~Board() {
	for (auto& row : board) {
		for (auto& cell : row) {
			if(cell.isEmpty()) {
				delete cell.getPiece();
			}
		}
	}
	for (auto& piece : deadPieces) {
		delete piece;
	}
}

void Board::initializeBoard() {
	board.resize(size, vector<Cell*>(size, nullptr));
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			Color cellColor = (i + j) % 2 == 0 ? color1 : color2;
			board[i][j] = new Cell(cellColor);
		}
	}

	// some logic to place pieces on the board
}

void Board::makeMove(Position source, Position destination) {
	if (!isValidPosition(source) || !isValidPosition(destination)) {
		throw runtime_error("Invalid move: Position out of bounds.");
	}

	Piece* sourcePiece = getPiece(source);
	if (sourceCell == nullptr) {
		throw runtime_error("Invalid move: Source cell is empty.");
	}
	Piece* destPiece = getPiece(destination);

	vector<PlayingStatergy*> strategies = sourceCell->getAllPlayingStatergies();
	bool canMove = isvalidMove(source, destination);

	if(!canMove) {
		throw runtime_error("Invalid move: Move not allowed by piece's playing strategy.");
	}

	if(destPiece != nullptr) {
		addDeadPiece(destPiece);
	}
	destCell->setPiece(piece);
	sourceCell->makeEmpty();

}

vector<Position> Board::getAllValidPosiotion(const Position source) const{
	if (!isValidPosition(source)) {
		throw runtime_error("Invalid position: Position out of bounds.");
	}

	Piece* piece = getPiece(source);
	if (piece == nullptr) {
		throw runtime_error("Invalid position: No piece at the source position.");
	}

	set<Position> validPositions;
	vector<PlayingStatergy*> strategies = piece->getAllPlayingStatergies();
	for (const auto& strategy : strategies) {
		vector<Position> possibleMoves = strategy->getPossibleMoves(source, this);
		for (const auto& pos : possibleMoves) {
			validPositions.insert(pos);
		}
	}
	return vector<Position>(validPositions.begin(), validPositions.end());
}

bool Board::isvalidMove(Position source, Position destination) const {
	if (!isValidPosition(source) || !isValidPosition(destination)) {
		return false;
	}

	Piece* piece = getPiece(source);
	if (piece == nullptr) {
		return false;
	}

	vector<PlayingStatergy*> strategies = piece->getAllPlayingStatergies();
	for (const auto& strategy : strategies) {
		if (strategy->isValidMove(source, destination, this)) {
			return true;
		}
	}
	return false;
}

bool Board::isValidPosition(const Position &position) const{
	return position.x >= 0 && position.x < size && position.y >= 0 && position.y < size;
}

bool Board::isDrawn() const {
	// Implement logic to check if the game is drawn
	return false; // Placeholder
}

bool Board::isCheckMate() const {
	// Implement logic to check if the game is in checkmate
	return false; // Placeholder
}

Piece* Board::getPiece(Position position) const{
	if (!isValidPosition(position)) {
		throw runtime_error("Invalid position: Position out of bounds.");
	}
	return board[position.x][position.y]->getPiece();
}

int Board::getSize() const{
	return size;
}

Piece* Board::getPiece(Position position) const{
	return board[position.x][position.y].isEmpty() ? nullptr : board[position.x][position.y]->getPiece();
}

void Board::setPiece(Position position){
	if (!isValidPosition(position)) {
		throw runtime_error("Invalid position: Position out of bounds.");
	}
	if (board[position.x][position.y]->isEmpty()) {
		throw runtime_error("Invalid operation: Cell is empty.");
	}
	board[position.x][position.y]->setPiece(piece);
}

vector<Piece*> Board::getDeadPieces() const{
	return deadPieces;
}