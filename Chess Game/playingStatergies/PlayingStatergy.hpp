#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Position.hpp"
#include "Board.hpp"

class PlayingStatergy{
public:
	virtual bool isValidMove(const Position &source, const Position &destination,const Board* board) const = 0;
	virtual ~PlayingStatergy() = default;
	virtual vector<Position> getPossibleMoves(const Position &source,const Board* board) const = 0;
};
