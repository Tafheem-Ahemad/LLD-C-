#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayerStatistics.hpp"
#include "Player.hpp"

class BattingPlayerStatistics : public PlayerStatistics{
private:
	const Player* player;
	int runs;
	int ballPlayed;
	Player* wicketBy;
public:
	BattingPlayerStatistics(const Player* player);

	int getRuns() const;
	int getBallPlayed() const;

	int addRuns(int runs);
	int addBallPlayed();

	void setWicketBy(const Player* player);
	Player* getWicketBy() const;

	Player* getPlayer() const;

	void printStatistics() override;
};