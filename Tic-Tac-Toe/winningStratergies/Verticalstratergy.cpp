#include "HorizontalStatergy.hpp"

bool HorizontalStratergy::checkStratergy(const Board* board, const Symbol symbol, const int &x, const int &y) {

	int boardSize=board->getSize();
	if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) {
		return false;
	}

	for (int j = 0; j < boardSize; j++) {
		if (board->getCell(x, j) != symbol) {
			return false;
		}
	}
	return true;
}