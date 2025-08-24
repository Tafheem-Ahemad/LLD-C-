#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayerStatistics.hpp"
#include "Player.hpp"

class BowlingPlayerStatistics : public PlayerStatistics{
private:
	int ballThrow;
	int getWickets;
	int runsGiven;
	vector<Player*> wicketedPlayers;
public:
	BowlingPlayerStatistics();
	int getBallThrow() const;
	int getWickets() const;
	int addBallThrow();
	int addWickets(Player* player);
	vector<Player*> getWicketedPlayers() const;
	int getRunsGiven() const;
	int addRunsGiven(int runs);

	void printStatistics() override;
};