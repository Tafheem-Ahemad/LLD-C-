
#include "Board.hpp"

Board(const int &size) : size(size), moveCount(0) {
	initialize();
}

Board::~Board() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			delete board[i][j];
		}
	}
}

Symbol getCell(const int &x,const int &y) const{
	if (x < 0 || x >= size || y < 0 || y >= size) {
		throw out_of_range("Coordinates out of bounds");
	}
	return board[x][y]->getSymbol();
}

bool isFull() const{
	return moveCount == size * size;
}

bool placeSymbol(const int &x,const int &y,const Symbol &symbol){
	Symbol curSymbol= getCell(x, y);

	if(curSymbol != Symbol::EMPTY) {
		return false;
	}

	board[x][y]->setSymbol(symbol);
	moveCount++;
	return true;
}

void printBoard() const{
	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << board[i][j]->getSymbol() << " ";
		}
		cout << endl;
	}
}

void reset(){
	for(int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			delete board[i][j];
			board[i][j] = new Cell(Symbol::EMPTY);
		}
	}
}

void initialize() {
	board.resize(size, vector<Cell*>(size, nullptr));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = new Cell(Symbol::EMPTY);
		}
	}
}