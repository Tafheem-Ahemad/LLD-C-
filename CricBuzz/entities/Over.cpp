#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Ball.hpp"
#include "Player.hpp"

class Over{
private:
	int netBalls; // excluding wides and no balls
	int totalRun;
	int totalWickets;
	vector<Ball>balls;
	vector<Player*>wickets;
	Player* bowler;
public:
	Over(const Player* bowler);
	~Over();

	void addNewBall(Ball ball);
	void addWicket(Player* player);
	
	// getter setter
	int getTotalRun() const;
	int getTotalWickets() const;
	Player* getBowler() const;
	vector<Player*> getWickets() const;
	int getTotalBalls() const;
	vector<Ball> getBalls() const;
	bool isOverComplete() const;
	int getNetBalls() const;
};
