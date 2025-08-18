#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PieceType.hpp"

class Player{
private:
	const string id;
	string name;
	const PieceType pieceType;
public:
	Player(const string &id,const string name,PieceType pieceType);
	PieceType getPieceType() const;
	string getName() const;
	string getId() const;
};
