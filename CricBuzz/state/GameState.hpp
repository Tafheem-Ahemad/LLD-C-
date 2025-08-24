#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "GameState.hpp"
#include "Match.hpp"

class GameState{
public:
	virtual void updateGameState(Match* match,const Ball ball) = 0;
	virtual string getStateName() const = 0;
}