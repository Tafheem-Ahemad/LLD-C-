#include "Game.hpp"

Game::Game(const string id,const string name,vector<Player*> players)
:id(id),name(name),players(players){
	this->dice = new Dice();
	this->gameState = NOT_STARTED;
	this->winner = nullptr;
}

Game::~Game(){
	delete this->dice;
}

void Game::startGame(){
	this->gameState = ONGOING;
	this->curIndex = 0;
	this->board->InitBoard();
}

void Game::makeNextMove(){
	if(this->gameState != ONGOING){
		throw runtime_error("Game is not in progress");
	}

	int diceValue = this->getNewDiceValue();
	Player* currentPlayer = this->getCurrentPlayer();

	// make move on board
	// check if current player is winner
	// if winner then set game state to end and set winner
	// else set next player as current player

	if(this->board->isWinner(currentPlayer)){
		this->gameState = END;
		this->winner = currentPlayer;
	}

	curIndex = (curIndex + 1) % players.size();
}
int Game::getNewDiceValue(){
	return this->dice->getNewValue();
}

Player* Game::getCurrentPlayer() const{
	return this->players[curIndex];
}

//getter setter;
string Game::getId() const{
	return this->id;
}

string Game::getName() const{
	return this->name;
}

vector<Player*> Game::getPlayers() const{
	return this->players;
}

Player* Game::getWinner() const{
	if(this->gameState != END){
		throw runtime_error("Game is not ended yet");
	}
	return this->winner;
}

GameState Game::getGameState() const{
	return this->gameState;
}
