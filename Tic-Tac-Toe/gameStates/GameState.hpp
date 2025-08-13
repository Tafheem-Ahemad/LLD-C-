#pragma once
#include <bits/stdc++.h>
using namespace std;


#include "Game.hpp"

class GameState{
public:
	virtual void handleMove(const Game* game,const int &x,const int &y,const Symbol symbol) = 0;
	virtual ~GameState()=default;
};

