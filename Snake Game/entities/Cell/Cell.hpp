#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "CellType.hpp"
#include "Position.hpp"

class Cell{
private:
	const Position sourcePosition;
	const Position destinationPosition;
	const int placeValue;
public:
	Cell(const Position sourcePosition,	const Position destinationPosition,const int placeValue);
	~Cell();

	Position getDestinationPosition const;
	int getPlaceValue() const;

	virtual CellType getCellType() const = 0;
};