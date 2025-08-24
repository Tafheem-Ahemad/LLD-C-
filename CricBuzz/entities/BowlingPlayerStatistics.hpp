#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayerStatistics.hpp"
#include "Player.hpp"

class BowlingPlayerStatistics : public PlayerStatistics{
private:
	Player* player;
	int ballThrow;
	int getWickets;
	int runsGiven;
	vector<Player*> wicketedPlayers;
public:
	BowlingPlayerStatistics(Player* player);

	Player* getPlayer() const;
	int getBallThrow() const;
	int getWickets() const;
	int addBallThrow();
	void addWicket(Player* player);
	vector<Player*> getWicketedPlayers() const;
	int getRunsGiven() const;
	int addRunsGiven(int runs);

	void printStatistics() override;
};
