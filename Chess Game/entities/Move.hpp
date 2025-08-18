#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PieceType.hpp"
#include "Player.hpp"
#include "Position.hpp"
#include "Piece.hpp"

class Move{
private:
	const Position source;
	const Position destination;
	Player* player;
public:
	Move(const Position source,const Position destination,const Player* player);
	Position getSource() const;
	Position getDestination() const;
	Player* getPlayer() const;
	
};
