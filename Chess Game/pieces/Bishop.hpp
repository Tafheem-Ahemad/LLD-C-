#pragma	once
#include<bits/stdc++.h>
using namespace std;

#include "Piece.hpp"
#include "PieceType.hpp"
#include "Color.hpp"
#include "PlayingStatergy.hpp"

class Bishop : public Piece {
public:
	Bishop(Color color);
	~Bishop();

	PieceType getPieceType() const override;
	Color getColor() const override;
	void addPlayingStatergies(PlayingStatergy* playingStatergy) override;
	void removePlayingStatergies(PlayingStatergy* playingStatergy) override;
	vector<PlayingStatergy*> getAllPlayingStatergies() const override;

	// some Bishop specific methods can be added here
};
