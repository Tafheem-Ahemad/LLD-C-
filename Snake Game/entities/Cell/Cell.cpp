#include "Cell.hpp"

Cell::Cell(const Position sourcePosition,	const Position destinationPosition,const int placeValue)
:sourcePosition(sourcePosition),destinationPosition(destinationPosition),placeValue(placeValue)
{
}


Cell::~Cell(){}

Position Cell::getDestinationPosition() const{
	return this->destinationPosition;
}

int Cell::getPlaceValue() const{
	return this->placeValue;
}
