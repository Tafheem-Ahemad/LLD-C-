#include "PlayerRepository.hpp"

PlayerRepository::PlayerRepository(){
}

PlayerRepository::~PlayerRepository(){
	for(auto& playerPair : players){
		delete playerPair.second;
	}
}

PlayerRepository& PlayerRepository::getInstance(){
	static PlayerRepository instance;
	return instance;
}

Player* PlayerRepository::createNewPlayer(const string& name, const year_month_day& dob, double height, double weight){
	string playerId = generatePlayerId();
	Player* newPlayer = new Player(playerId,name,dob,height,weight);
	players[playerId] = newPlayer;
	return newPlayer;
}

Player* PlayerRepository::getPlayerById(const string& playerId){
	if(players.find(playerId) == players.end()){
		throw runtime_error("Player with given id does not exist");
	}
	return players[playerId];
}

vector<Player*> PlayerRepository::getAllPlayers() const{
	vector<Player*> allPlayers;
	for(const auto& playerPair : players){
		allPlayers.push_back(playerPair.second);
	}
	return allPlayers;
}

string PlayerRepository::generatePlayerId(){
	static int playerIdCounter = 1;
	return "PLAYER" + to_string(playerIdCounter++);
}