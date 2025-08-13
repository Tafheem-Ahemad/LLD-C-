#include "DrawState.hpp"

void DrawState::handleMove(const Game* game,const int &x,const int &y,const Symbol symbol) override{
	throw runtime_error("Game is already in a draw state. No further moves can be made.");
}