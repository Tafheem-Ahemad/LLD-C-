#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Direction.hpp"
#include "RequestSouce.hpp"

class Request{
private:
	const int targetFloor;
	const Direction direction;
	const RequestSource requestSource;
public:
	Request(const int targetFllor,constm Direction direction, const RequestSource requestSouce);
	~Request();

	// getter setter
	int getTargetFloor() const;
	Direction getDirection() const;
	RequestSource getRequestSource() const;
};
