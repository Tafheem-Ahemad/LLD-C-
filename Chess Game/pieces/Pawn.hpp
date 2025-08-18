#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Piece.hpp"
#include "PieceType.hpp"
#include "Color.hpp"
#include "PlayingStatergy.hpp"

class Pawn : public Piece{
public:
	Pawn(Color color);
	~Pawn();

	PieceType getPieceType() const override;
	Color getColor() const override;
	void addPlayingStatergies(PlayingStatergy* playingStatergy) override;
	void removePlayingStatergies(PlayingStatergy* playingStatergy) override;
	vector<PlayingStatergy*> getAllPlayingStatergies() const override;

	// Pawn specific methods can be added here
};
