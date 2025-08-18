#pragma	once
#include<bits/stdc++.h>
using namespace std;

#include "Piece.hpp"
#include "PieceType.hpp"
#include "Color.hpp"
#include "PlayingStatergy.hpp"

class King : public Piece {
public:
	King(Color color);
	~King();

	PieceType getPieceType() const override;
	Color getColor() const override;
	void addPlayingStatergies(PlayingStatergy* playingStatergy) override;
	void removePlayingStatergies(PlayingStatergy* playingStatergy) override;
	vector<PlayingStatergy*> getAllPlayingStatergies() const override;

	// some King specific methods can be added here
};