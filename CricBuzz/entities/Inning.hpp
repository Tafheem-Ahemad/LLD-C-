#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Team.hpp"
#include "Player.hpp"
#include "Over.hpp"
#include "PlayerStatistics.hpp"
#include "Ball.hpp"

class Inning{
private:
	const Team* battingTeam;
	const Team* bowlingTeam;
	vector<Over*> overs;
	int score;
	int wickets;
	map<string,PlayerStatistics*>playerStats;
public:
	Inning();
	~Inning();

	void addNewBall(Ball ball);
	void addWicket(Player* player);
	void addRun(int score);

	PlayerStatistics* getPlayerStats(Player* player);
	//getter setter
};