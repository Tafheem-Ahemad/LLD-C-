#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Position.hpp"
#include "Piece.hpp"
#include "PlayingStatergy.hpp"

class DiagonalMoveStatergy : public PlayingStatergy {
public:
	bool isValidMove(const Position &source, const Position &destination, const Piece* piece) const override;

	vector<Position> getPossibleMoves(const Position &source) const override;
}