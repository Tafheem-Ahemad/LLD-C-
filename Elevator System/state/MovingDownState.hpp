#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"
#include "Request.hpp"
#include "Direction.hpp"
#include "ElevatorState.hpp"

class MovingDownState : public ElevatorState{
public:
	void move(Elevator* elevator) override;
	void addRequest(Elevator* elevator,Request request) override;
	Direction getDirection() const override;
};