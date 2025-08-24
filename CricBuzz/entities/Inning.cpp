#include "Player.hpp"
#include "Team.hpp"
#include "Over.hpp"
#include "PlayerStatistics.hpp"
#include "Ball.hpp"
#include "Inning.hpp"


Inning::Inning(const Team* battingTeam,const Team* bowlingTeam):battingTeam(battingTeam),bowlingTeam(bowlingTeam),score(0),numberOfWickets(0),currentBatsman(nullptr),currentBowler(nullptr){

}

Inning::~Inning(){
	for(auto& it:BattingPlayerStats){
		delete it.second;
	}
	for(auto& it:BowlingPlayerStats){
		delete it.second;
	}
	for(auto& over:overs){
		delete over;
	}
}

void Inning::startInning(Player* batsman1,Player* batsman2,Player* bowler){
	currentBatsman1 = batsman1;
	currentBatsman2 = batsman2;
	currentBowler = bowler;
	currentBatsmanONStrike = batsman1;

	// create batting stats for both batsman
	battingPlayerStats[batsman1->getId()] = new BattingPlayerStatistics(batsman1);
	battingPlayerStats[batsman2->getId()] = new BattingPlayerStatistics(batsman2);

	// create bowling stats for bowler
	bowlingPlayerStats[bowler->getId()] = new BowlingPlayerStatistics(bowler);
}

void Inning::addNewBall(Ball ball){
	if(currentBatsman1 == nullptr && currentBatsman2 == nullptr){
		throw runtime_error("Both batsman are out. Cannot add more balls");
	}
	if(overs.empty() || overs.back()->isOverComplete()){
		Over* newOver = new Over(ball.getBowler());
		overs.push_back(newOver);
		currentBowler = ball.getBowler();

		// if bowler stats not present then create new
		if(BowlingPlayerStats.find(currentBowler->getId()) == BowlingPlayerStats.end()){
			BowlingPlayerStats[currentBowler->getId()] = new BowlingPlayerStatistics();
		}
	}

	overs.back()->addNewBall(ball);
	BattingPlayerStatistics* batsmanStats = battingTeamStats[ball.getBatsman()->getId()];
	BowlingPlayerStatistics* bowlerStats = bowlingTeamStats[ball.getBowler()->getId()];

	batsmanStats->addBallPlayed();
	bowlerStats->addBallBowled();

	BallOutput output = ball.getBallOutput();
	if(output== BallOutput::WICKET){
		addWicket(ball.getBatsman());
		batsmanStats->setWicketBy(ball.getBowler());
		bowlerStats->addWicket(ball.getBatsman());

		if(currentBatsman1 == ball.getBatsman()){
			currentBatsman1 = nullptr;
		}else if(currentBatsman2 == ball.getBatsman()){
			currentBatsman2 = nullptr;
		}
	}else if(output == BallOutput::NO_BALL || output == BallOutput::WIDE){
		addRun(1);
		bowlerStats->addRunsConceded(1);
	}else{
		addRun(output.runs);
		batsmanStats->addRuns(output.runs);
		bowlerStats->addRunsConceded(output.runs);

		// may be change strike
	}
}

void Inning::addWicket(Player* player){
	wickets.push_back(player);
	numberOfWickets++;
}

void Inning::addRun(int run){
	score += run;
}

PlayerStatistics* Inning::getPlayerStats(Player* player){
	if(battingTeam->getPlayerById(player->getId())){
		return battingPlayerStats[player->getId()];
	}else if(bowlingTeam->getPlayerById(player->getId())){
		return bowlingPlayerStats[player->getId()];
	}else{
		throw invalid_argument("Player does not belong to this inning OR player did not perform any action in this inning till now");
	}
}

vector<PlayerStatistics*> Inning::getAllPlayerStatistics() const{
	vector<PlayerStatistics*> allStats;
	for(const auto& it:battingPlayerStats){
		allStats.push_back(it.second);
	}
	for(const auto& it:bowlingPlayerStats){
		allStats.push_back(it.second);
	}
	return allStats;
}

PlayerStatistics* Inning::getPlayerStatisticsById(const string& playerId){
	if(battingPlayerStats.find(playerId) != battingPlayerStats.end()){
		return battingPlayerStats[playerId];
	}else if(bowlingPlayerStats.find(playerId) != bowlingPlayerStats.end()){
		return bowlingPlayerStats[playerId];
	}else{
		throw invalid_argument("Player does not belong to this inning OR player did not perform any action in this inning till now");
	}
}
void Inning::addnewBatsman(Player* newBatsman){

	// may be check if player belong to batting team
	// also some check if player is already in stats
	// with some other checks

	if(currentBatsman1 == nullptr){
		currentBatsman1 = newBatsman;
		currentBatsmanONStrike = newBatsman;
	}else if(currentBatsman2 == nullptr){
		currentBatsman2 = newBatsman;
	}else{
		throw runtime_error("Both batsman are already present");
	}
	// create batting stats for new batsman
	battingPlayerStats[newBatsman->getId()] = new BattingPlayerStatistics(newBatsman);
}

//getter setter
const Team* Inning::getBattingTeam() const{
	return battingTeam;
}

const Team* Inning::getBowlingTeam() const{
	return bowlingTeam;
}

int Inning::getScore() const{
	return score;
}

int Inning::getWickets() const{
	return numberOfWickets;
}

vector<Over*> Inning::getOvers() const{
	return overs;
}

int Inning::getTotalBalls() const{
	int totalBalls = 0;
	for(const auto& over:overs){
		totalBalls += over->getTotalBalls();
	}
	return totalBalls;
}

vector<Player*> Inning::getWickets() const{
	return wickets;
}

vector<Player*> Inning::getPlayers() const{
	vector<Player*> players;
	for(const auto& it:battingPlayerStats){
		players.push_back(it.second->getPlayer());
	}
	for(const auto& it:bowlingPlayerStats){
		players.push_back(it.second->getPlayer());
	}
	return players;
}

Player* Inning::getCurrentBatsman() const{
	return currentBatsmanONStrike;
}

Player* Inning::getCurrentBowler() const{
	return currentBowler;
}

void Inning::setCurrentBatsman(Player* player){
	if(player != currentBatsman1 && player != currentBatsman2){
		throw invalid_argument("Player is not one of the current batsman");
	}
	currentBatsmanONStrike = player;
}

void Inning::setCurrentBowler(Player* player){
	if(bowlingTeam->getPlayerById(player->getId()) == nullptr){
		throw invalid_argument("Player does not belong to bowling team");
	}
	currentBowler = player;

	// if bowler stats not present then create new
	if(bowlingPlayerStats.find(currentBowler->getId()) == bowlingPlayerStats.end()){
		bowlingPlayerStats[currentBowler->getId()] = new BowlingPlayerStatistics(currentBowler);
	}
}

