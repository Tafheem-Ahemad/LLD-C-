#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Game.hpp"
#include "GameState.hpp"

class DrawState: public GameState{
public:
	void handleMove(const Game* game,const int &x,const int &y,const Symbol symbol) override;
};
