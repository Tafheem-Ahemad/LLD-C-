#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayingFormat.hpp"
#include "Match.hpp"
#include "GameState.hpp"
#include "Observer.hpp"
#include "Team.hpp"
#include "Player.hpp"
#include "PlayerStatistics.hpp"


class CricBuzzService{
private:
	CricBuzzService();
	~CricBuzzService();

	CricBuzzService (const CricBuzzService& other) = delete;
	CricBuzzService& operator=(const CricBuzzService& other) = delete;
	CricBuzzService (CricBuzzService&& other) = delete;
	CricBuzzService& operator=(CricBuzzService&& other) = delete;

public:

	static CricBuzzService& getInstance();

	Match* createMatch(const Team* team1,const Team* team2,const string &format);
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	
	void madeBall(const string& matchId,const Ball ball);
	int getScore(const string& matchId);
	string getMatchStatus(const string& matchId);
	vector<Match*> getAllMatches() const;

	void startMatch(const string& matchId);
	void endMatch(const string& matchId);

	Team* getWinningTeam(const string& matchId);
	
	Team* createTeam(const string& name,const vector<Player*>& players);
	Player* createPlayer(const string& name,const string& teamId);

	vector<Team*> getAllTeams() const;
	vector<Player*> getAllPlayers() const;
	Team* getTeamById(const string& teamId);
	Player* getPlayerById(const string& playerId);

	GameState* getGameState(const string& matchId);
	string getPlayingFormat(const string& matchId);

	PlayerStatistics* getPlayerStatistics(const string& matchId,const string& playerId);
	void printScoreBoard(const string& matchId);

	Over* getCurrentOver(const string& matchId);
	vector<Over*> getAllOvers(const string& matchId);

}