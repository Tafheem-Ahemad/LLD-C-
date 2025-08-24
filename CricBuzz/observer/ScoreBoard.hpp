#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Observer.hpp"
#include "Ball.hpp"
#include "Match.hpp"

class ScoreBoard : public Observer{
public:
	void update(Match* match,const Ball ball) override{
		// print the score board
		cout<<"ScoreBoard Update: New ball played in match between "<<match->getTeam1()->getName()<<" and "<<match->getTeam2()->getName()<<endl;
		cout<<"Batsman: "<<ball.getBatsman()->getName()<<", Bowler: "<<ball.getBowler()->getName()<<", Ball Output: ";
	}
}