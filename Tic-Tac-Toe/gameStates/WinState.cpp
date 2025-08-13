#include "WinState.hpp"

void WinState::handleMove(const Game* game,const int &x,const int &y,const Symbol symbol) override{
	throw runtime_error("Game is already in a win state. No further moves can be made.");
}