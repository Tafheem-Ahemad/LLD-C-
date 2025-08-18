#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PieceType.hpp"
#include "Color.hpp"
#include "PlayingStatergy.hpp"
#include "Piece.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "King.hpp"
#include "Pawn.hpp"

class PieceFactory{
private:

	PieceFactory();
	~PieceFactory();

	// Disable copy and move semantics
	PieceFactory(const PieceFactory&) = delete;
	PieceFactory& operator=(const PieceFactory&) = delete;
	PieceFactory(PieceFactory&&) = delete;
	PieceFactory& operator=(PieceFactory&&) = delete;
public:
	static PieceFactory& getInstance() ;
	Piece* createPiece(PieceType pieceType, Color color) ;
};
