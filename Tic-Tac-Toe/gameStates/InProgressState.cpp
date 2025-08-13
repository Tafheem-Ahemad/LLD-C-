#include "InProgressState.hpp"

void InProgressState::handleMove(const Game* game,const int &x,const int &y,const Symbol symbol) override{
	if(game->getGameStatus() != GameStatus::IN_PROGRESS) {
		throw runtime_error("Game is not in progress. Cannot make a move.");
	}

	if(game->getCurrentPlayer()->getSymbol() != symbol) {
		throw runtime_error("It's not your turn. Wait for your turn to make a move.");
	}

	game->makeMove(game->getCurrentPlayer(), x, y);

	if(game->checkWinner(game->getCurrentPlayer(), x, y)) {
		game->setGameStatus(symbol == Symbol::X ? GameStatus::WINNER_X : GameStatus::WINNER_Y);
		game->getWinnerPlayer() = game->getCurrentPlayer();
		game->setCurState(new WinState());
	} else if (game->getBoard()->isFull()) {
		game->setGameStatus(GameStatus::DRAW);
		game->setCurState(new DrawState());
	} else {
		game->swapPlayer();
	}
}