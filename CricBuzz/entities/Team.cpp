#include "Player.hpp"
#include "Team.hpp"

Team::Team(const string& name, const string& id):name(name),id(id){

}

void Team::addPlayer(Player* player){
	players[player->getId()] = player;
}

void Team::removePlayer(Player* player){
	players.erase(player->getId());
}

// getter setter
Player* Team::getPlayerById(const string& playerId){
	if(players.find(playerId) != players.end()){
		return players[playerId];
	}else{
		throw invalid_argument("Player not found in team");
	}
}

string Team::getName() const{
	return name;
}

string Team::getId() const{
	return id;
}

vector<Player*> Team::getPlayers() const{
	vector<Player*> playerList;
	for(auto& it: players){
		playerList.push_back(it.second);
	}
	return playerList;
}