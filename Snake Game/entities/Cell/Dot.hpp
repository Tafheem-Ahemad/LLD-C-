#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "CellType.hpp"
#include "Position.hpp"
#include "Cell.hpp"

class Dot : public Cell{
public:
	Dot(const Position sourcePosition,	const Position destinationPosition,const int placeValue)
	:Cell(sourcePosition,destinationPosition,placeValue){}

	CellType getCellType() const{
		return EMPTY;
	}
};