#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PieceType.hpp"
#include "Color.hpp"
#include "PlayingStatergy.hpp"

class Piece{
private:
	const Color color;
	const PieceType pieceType;
	vector<PlayingStatergy*> playingStatergies;
public:
	Piece(Color color,);
	~Piece();

	virtual PieceType getPieceType() const = 0;
	virtual Color getColor() const = 0;
	virtual void addPlayingStatergies(PlayingStatergy* playingStatergy) = 0;
	virtual void removePlayingStatergies(PlayingStatergy* playingStatergy) = 0;
	virtual vector<PlayingStatergy*> getAllPlayingStatergies() const = 0 ;

};

