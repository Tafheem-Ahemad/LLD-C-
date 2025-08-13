#include "Game.hpp"

Game::Game(const string &id,Player* player1,Player* player2,const int size) : id(id), player1(player1), player2(player2), gameStatus(GameStatus::IN_PROGRESS), moveCount(0) {
	board = new Board(size);
	curPlayer = player1;
	WinnerPlayer = nullptr;
	curState = new InProgressState();
	stratergies.push_back({
		new HorizontalStatergy(),
		new VerticalStatergy(),
		new DiagonalStatergy()
	});
}

Game::~Game() {
	delete board;
	for (auto strategy : stratergies) {
		delete strategy;
	}
	delete curState;
}

void Game::swapPlayer(){
	if(curPlayer == player1) {
		curPlayer = player2;
	} else {
		curPlayer = player1;
	}
}
void Game::makeMove(Player* player,const  &int x,const &int y){
	curState->handleMove(this, x, y, player->getSymbol());
}
bool Game::checkWinner(Player* player,const  &int x,const &int y){
	for(auto& strategy : stratergies) {
		if(strategy->checkStratergy(board, player->getSymbol(), x, y)) {
			return true;
		}
	}
	return false;
}

void Game::reset(){
	board->reset();
	gameStatus = GameStatus::IN_PROGRESS;
	curPlayer = player1;
	WinnerPlayer = nullptr;
	curState = new InProgressState();
}

Board* Game::getBoard() const{
	return board;
}
GameStatus Game::getGameStatus() const{
	return gameStatus;
}
Player* Game::getCurrentPlayer() const{
	return curPlayer;
}
Player* Game::getWinnerPlayer() const{
	return WinnerPlayer;
}
void Game::setGameStatus(GameStatus status){
	gameStatus = status;
}
void Game::setCurState(GameState* state){
	if(curState) {
		delete curState;
	}
	curState = state;
}
void Game::setWinnerPlayer(Player* player){
	WinnerPlayer = player;
}