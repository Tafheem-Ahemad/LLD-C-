#pragma once
#include "Request.hpp"

Request::Request(const int targetFloor, const Direction direction, const RequestSource requestSource)
	: targetFloor(targetFloor), direction(direction), requestSource(requestSource) {}

Request::~Request() {}

int Request::getTargetFloor() const {
	return targetFloor;
}

Direction Request::getDirection() const {
	return direction;
}

RequestSource Request::getRequestSource() const {
	return requestSource;
}
