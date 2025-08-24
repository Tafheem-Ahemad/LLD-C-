#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayerStatistics.hpp"
#include "Player.hpp"

class BattingPlayerStatistics : public PlayerStatistics{
private:
	int runs;
	int ballPlayed;
	Player* wicketBy;
public:
	BattingPlayerStatistics();

	int getRuns() const;
	int getBallPlayed() const;

	int addRuns(int runs);
	int addBallPlayed();

	void setWicketBy(Player* player);
	void removeWicketBy();
	Player* getWicketBy() const;

	void printStatistics() override;
};