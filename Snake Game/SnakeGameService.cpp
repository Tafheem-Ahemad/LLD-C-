#include "SnakeGameService.hpp"

SnakeGameService& getIntance(){
	static SnakeGameService instance;
	return instance;
}

SnakeGameService::~SnakeGameService(){
	for(auto &it:players){
		delete it.second;
	}
	for(auto &it:games){
		delete it.second;
	}
}
void SnakeGameService::createGame(const string name,vector<Player*> players){
	string gameId = getRandom(6);
	Game* game = new Game("GAME:"+gameId,name,players);
	games[gameId] = game;
	game->startGame();
}

void SnakeGameService::createPlayer(const string name){
	string playerId = getRandom(6);
	Player* player = new Player("PLAYER:"+playerId,name);
	players[playerId] = player;
}

void SnakeGameService::makeMove(const string &gameId){
	
	Game* game = getGame(gameId);
	game->makeNextMove();
}

// getter && setter
Game* SnakeGameService::getGame(const string &gameId) const{
	if(games.find(gameId) == games.end()){
		throw runtime_error("Game not found");
	}
	return games.at(gameId);
}
Player* SnakeGameService::getPlayer(const string &playerId) const{
	if(players.find(playerId) == players.end()){
		throw runtime_error("Player not found");
	}
	return players.at(playerId);
}

Player* SnakeGameService::getwinner(const string &gameId) const{
	Game* game = getGame(gameId);
	return game->getWinner();
}

GameStatus SnakeGameService::getGameStatus(const string &gameId) const{
	Game* game = getGame(gameId);
	return game->getGameState();
}

string SnakeGameService::getRandom(int lengh){
	const string str="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string newstr="";
	int pos;
	while(newstr.size()!=lengh) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos,1);
	}
	return newstr;
}
