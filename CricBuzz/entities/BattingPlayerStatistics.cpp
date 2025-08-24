#include "Player.hpp"
#include "Team.hpp"
#include "Over.hpp"
#include "PlayerStatistics.hpp"
#include "BattingPlayerStatistics.hpp"

BattingPlayerStatistics::BattingPlayerStatistics(Player* player):player(player),runs(0),ballPlayed(0),wicketBy(nullptr){

}

int BattingPlayerStatistics::getRuns() const{
	return runs;
}
int BattingPlayerStatistics::getBallPlayed() const{
	return ballPlayed;
}

int BattingPlayerStatistics::addRuns(int runs){
	if(wicketBy != nullptr){
		throw runtime_error("Player is already out. Cannot add more runs");
	}
	this->runs += runs;
	return this->runs;
}
int BattingPlayerStatistics::addBallPlayed(){
	if(wicketBy != nullptr){
		throw runtime_error("Player is already out. Cannot add more balls");
	}
	this->ballPlayed += 1;
	return this->ballPlayed;
}

void BattingPlayerStatistics::setWicketBy(const Player* player){
	if(wicketBy != nullptr){
		throw runtime_error("Player is already out. Cannot set wicket again");
	}
	wicketBy = player;
}

Player* BattingPlayerStatistics::getWicketBy() const{
	if(wicketBy == nullptr){
		throw runtime_error("Player is not out yet. No wicket by");
	}
	return wicketBy;
}

Player* BattingPlayerStatistics::getPlayer() const{
	return player;
}

void BattingPlayerStatistics::printStatistics() {
	cout<<"Player: "<<player->getName()<<endl;
	cout<<"Runs: "<<runs<<endl;
	cout<<"Balls Played: "<<ballPlayed<<endl;
	if(wicketBy != nullptr){
		cout<<"Wicket By: "<<wicketBy->getName()<<endl;
	}else{
		cout<<"Not Out"<<endl;
	}
}