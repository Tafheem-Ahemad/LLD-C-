#include "CricBuzzService.hpp"
#include "MatchRepository.hpp"
#include "PlayingFormatRepository.hpp"
#include "TeamRepository.hpp"
#include "PlayerRepository.hpp"

CricBuzzService::CricBuzzService(){
}

CricBuzzService::~CricBuzzService(){
	for(auto& match:MatchRepository::getInstance().getAllMatches()){
		delete match;
	}
	for(auto& team:TeamRepository::getInstance().getAllTeams()){
		delete team;
	}
	for(auto& player:PlayerRepository::getInstance().getAllPlayers()){
		delete player;
	}
}

CricBuzzService& CricBuzzService::getInstance(){
	static CricBuzzService instance;
	return instance;
}

Match* CricBuzzService::createMatch(const Team* team1,const Team* team2,const string &format){
	Match* newMatch = MatchRepository::getInstance().createNewMatch(format,team1,team2);
	return newMatch;
}

void CricBuzzService::addObserver(const string matchId,Observer* observer){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	match->addObserver(observer);
}

void CricBuzzService::removeObserver(const string matchId,Observer* observer){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	match->removeObserver(observer);
}

void CricBuzzService::madeBall(const string& matchId,const Ball ball){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	match->addNewBall(ball);
}

int CricBuzzService::getScore(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getCurrentScore();
}

GameStatus CricBuzzService::getMatchStatus(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getGameStatus().toString();
}

vector<Match*> CricBuzzService::getAllMatches() const{
	return MatchRepository::getInstance().getAllMatches();
}

void CricBuzzService::startMatch(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	match->startMatch();
}

void CricBuzzService::endMatch(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	match->endMatch();
}

Team* CricBuzzService::getWinningTeam(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getWinner();
}

Team* CricBuzzService::createTeam(const string& name,const vector<Player*>& players){
	Team* newTeam = TeamRepository::getInstance().createNewTeam(name,players);
	return newTeam;
}

Player* CricBuzzService::createPlayer(const string& name,const string& teamId){
	Player* newPlayer = PlayerRepository::getInstance().createNewPlayer(name);
	Team* team = TeamRepository::getInstance().getTeamById(teamId);
	team->addPlayer(newPlayer);
	return newPlayer;
}

vector<Team*> CricBuzzService::getAllTeams() const{
	return TeamRepository::getInstance().getAllTeams();
}

vector<Player*> CricBuzzService::getAllPlayers() const{
	return PlayerRepository::getInstance().getAllPlayers();
}

Team* CricBuzzService::getTeamById(const string& teamId){
	return TeamRepository::getInstance().getTeamById(teamId);
}

Player* CricBuzzService::getPlayerById(const string& playerId){
	return PlayerRepository::getInstance().getPlayerById(playerId);
}

GameState* CricBuzzService::getGameState(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getGameState();
}

string CricBuzzService::getPlayingFormat(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getPlayingFormat()->getFormatName();
}

PlayerStatistics* CricBuzzService::getPlayerStatistics(const string& matchId,const string& playerId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getPlayerStatistics(playerId);
}

void CricBuzzService::printScoreBoard(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	match->printScoreBoard();
}

Over* CricBuzzService::getCurrentOver(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getCurrentInning()->getCurrentOver();
}

vector<Over*> CricBuzzService::getAllOvers(const string& matchId){
	Match* match = MatchRepository::getInstance().getMatchById(matchId);
	return match->getCurrentInning()->getOvers();
}

