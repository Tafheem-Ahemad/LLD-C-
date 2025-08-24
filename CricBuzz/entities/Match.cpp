#include "Match.hpp"
#include "Inning.hpp"

Match::Match(const Team* team1,const Team* team2,const PlayingFormat* playingFormat):team1(team1),team2(team2),playingFormat(playingFormat),currentInningIndex(-1),currentBattingTeam(nullptr),gameState(nullptr),gameStatus(GameStatus::NOT_STARTED){
	playingFormat->AddInning(this);
	gameState = new SheduledState();
}

Match::~Match(){
	for(auto& inning:innings){
		delete inning;
	}
}

Inning* Match::getCurrentInning() const{
	if(currentInningIndex == -1){
		throw runtime_error("Match has not started yet");
	}
	return innings[currentInningIndex];
}
int Match::getCurrentInningIndex() const{
	return currentInningIndex;
}
void Match::setCurrentInningIndex(int index){
	if(index < 0 || index >= innings.size()){
		throw out_of_range("Invalid inning index");
	}
	currentInningIndex = index;
}

const Team* Match::getCurrentBattingTeam() const{
	return currentBattingTeam;
}

void Match::setCurrentBattingTeam(const Team* team){
	if(team != team1 && team != team2){
		throw invalid_argument("Team is not part of the match");
	}
	currentBattingTeam = team;
}
const PlayingFormat* Match::getPlayingFormat() const{
	return playingFormat;
}

const GameState* Match::getGameState() const{
	return gameState;
}

const GameStatus Match::getGameStatus() const{
	return gameStatus;
}

const Team* Match::getWinner() const{
	if(gameStatus != GameStatus::END){
		throw runtime_error("Match is not yet completed");
	}

	// Logic to determine winner based on innings scores
	return winner;
}

void Match::addObserver(Observer* observer){
	observers.push_back(observer);
}

void Match::removeObserver(Observer* observer){
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Match::notifyAllObservers(const Ball ball) const{
	for(auto& observer : observers){
		observer->update(const_cast<Match*>(this), ball);
	}
}

void Match::addNewInning(Inning* inning){
	this->playingFormat->AddInning(this, inning);
}

void Match::addNewBall(Ball ball){
	if(currentInningIndex == -1){
		throw runtime_error("Match has not started yet");
	}
	this->getGameState()->addNewBall(ball);
}
void Match::startMatch(){
	if(gameStatus != GameStatus::NOT_STARTED){
		throw runtime_error("Match has already started or ended");
	}
	if(innings.empty()){
		throw runtime_error("No innings available to start the match");
	}
	currentInningIndex = 0;
	gameState = new LiveState();
	gameStatus = GameStatus::LIVE;
}

void Match::endMatch(){
	if(gameStatus != GameStatus::LIVE){
		throw runtime_error("Match is not live");
	}
	gameState = new FinishState();
	gameStatus = GameStatus::END;
	// Logic to determine winner based on innings scores
}

int Match::getTotalOvers() const{
	return playingFormat->getTotalOvers();
}

bool Match::isMatchComplete() const{
	return gameStatus == GameStatus::END || gameStatus == GameStatus::ABANDONED;
}

int Match::getTotalInnings() const{
	return thsi->playingFormat->totalInning();
}

int Match::getCurrentOverNumber() const{
	if(currentInningIndex == -1){
		throw runtime_error("Match has not started yet");
	}
	return getCurrentInning()->getOvers().size();
}

int Match::getCurrentBallNumber() const{
	if(currentInningIndex == -1){
		throw runtime_error("Match has not started yet");
	}
	return getCurrentInning()->getTotalBalls() % 6; // Assuming 6 balls per over
}

int Match::getWicketsRemaining() const{
	if(currentInningIndex == -1){
		throw runtime_error("Match has not started yet");
	}
	return 10 - getCurrentInning()->getWickets(); // Assuming 10 wickets per inning
}

int Match::getCurrentScore() const{
	if(currentInningIndex == -1){
		throw runtime_error("Match has not started yet");
	}
	return getCurrentInning()->getScore();
}

const Team* Match::getTeam1() const{
	return team1;
}

const Team* Match::getTeam2() const{
	return team2;
}

vector<Inning*> Match::getInnings() const{
	return innings;
}

