#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "CellType.hpp"
#include "Position.hpp"
#include "Cell.hpp"

class Ladder : public Cell{
public:
	Ladder(const Position sourcePosition,	const Position destinationPosition,const int placeValue)
	:Cell(sourcePosition,destinationPosition,placeValue){}

	CellType getCellType() const{
		return LADDER;
	}
};