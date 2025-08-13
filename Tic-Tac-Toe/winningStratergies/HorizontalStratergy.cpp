#include "HorizontalStatergy.hpp"

bool HorizontalStatergy::checkStratergy(const Board* board, const Symbol symbol, const int &x, const int &y) {

	int boardSize=board->getSize();
	if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) {
		return false;
	}

	for (int i = 0; i < boardSize; i++) {
		if (board->getCell(i,y) != symbol) {
			return false;
		}
	}
	return true;
}