#include "BowlingPlayerStatistics.hpp"	
#include "Player.hpp"
#include "Team.hpp"
#include "Over.hpp"



BowlingPlayerStatistics::BowlingPlayerStatistics(Player* player):player(player),ballThrow(0),getWickets(0),runsGiven(0){

}

Player* BowlingPlayerStatistics::getPlayer() const{
	return player;
}

int BowlingPlayerStatistics::getBallThrow() const{
	return ballThrow;
}

int BowlingPlayerStatistics::getWickets() const{
	return getWickets;
}

int BowlingPlayerStatistics::addBallThrow(){
	this->ballThrow += 1;
	return this->ballThrow;
}

void BowlingPlayerStatistics::addWicket(Player* player){
	this->getWickets += 1;
	wicketedPlayers.push_back(player);
}

vector<Player*> BowlingPlayerStatistics::getWicketedPlayers() const{
	return wicketedPlayers;
}

int BowlingPlayerStatistics::getRunsGiven() const{
	return runsGiven;
}


int BowlingPlayerStatistics::addRunsGiven(int runs){
	this->runsGiven += runs;
	return this->runsGiven;
}

void BowlingPlayerStatistics::printStatistics() {
	cout<<"Player: "<<player->getName()<<endl;
	cout<<"Balls Thrown: "<<ballThrow<<endl;
	cout<<"Wickets Taken: "<<getWickets<<endl;
	cout<<"Runs Given: "<<runsGiven<<endl;
	if(!wicketedPlayers.empty()){
		cout<<"Wicketed Players: ";
		for(const auto& p:wicketedPlayers){
			cout<<p->getName()<<" ";
		}
		cout<<endl;
	}else{
		cout<<"No Wickets Taken Yet"<<endl;
	}
}