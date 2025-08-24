#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "GameState.hpp"
#include "Match.hpp"

class BreakState : public GameState{
public:
	void updateGameState(Match* match,const Ball ball) override;
	string getStateName() const override;
};	