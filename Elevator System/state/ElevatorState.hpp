#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"
#include "Request.hpp"
#include "Direction.hpp"

class ElevatorState{
public:
	virtual void move(Elevator* elevator) = 0;
	virtual void addRequest(Elevator* elevator,Request request) = 0;
	virtual Direction getDirection() const = 0;
	virtual ~ElevatorState() = default;
};
