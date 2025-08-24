#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Team.hpp"
#include "Player.hpp"
#include "Over.hpp"
#include "PlayerStatistics.hpp"
#include "BattingPlayerStatistics.hpp"
#include "BowlingPlayerStatistics.hpp"
#include "Ball.hpp"
#include "BallOutput.hpp"
#include "Player.hpp"

class Inning{
private:
	const Team* battingTeam;
	const Team* bowlingTeam;
	Player* currentBatsman1;
	Player* currentBatsman2;
	Player* currentBowler;
	Player* currentBatsmanONStrike;
	vector<Over*> overs;
	vector<Player*> wickets;
	int score;
	int numberOfWickets;
	map<string,BattingPlayerStatistics*>battingPlayerStats;
	map<string,BowlingPlayerStatistics*>bowlingPlayerStats;
public:
	Inning(const Team* battingTeam,const Team* bowlingTeam);
	~Inning();

	void startInning(Player* batsman1,Player* batsman2,Player* bowler);
	void addNewBall(Ball ball);
	void addWicket(Player* player);
	void addRun(int score);

	PlayerStatistics* getPlayerStats(Player* player);
	vector<PlayerStatistics*> getAllPlayerStatistics() const;
	PlayerStatistics* getPlayerStatisticsById(const string& playerId);
	void addnewBatsman(Player* newBatsman);

	//getter setter
	const Team* getBattingTeam() const;
	const Team* getBowlingTeam() const;
	int getScore() const;
	int getWickets() const;
	vector<Over*> getOvers() const;
	int getTotalBalls() const;
	vector<Player*> getWickets() const;
	vector<Player*> getPlayers() const;
	Player* getCurrentBatsman() const;
	Player* getCurrentBowler() const;
	void setCurrentBatsman(Player* player);
	void setCurrentBowler(Player* player);
	
};