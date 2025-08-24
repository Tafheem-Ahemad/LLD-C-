#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "BallOutput.hpp"
#include "Player.hpp"

class Ball{
private:
	const Player* batsman;
	const Player* bowler;
	const BallOutput ballOutput;
public:
	Ball(const Player* batsman,const Player* bowler,const BallOutput ballOutput);

	// getter Setter
	const Player* getBatsman() const;
	const Player* getBowler() const;
	BallOutput getBallOutput() const;
};