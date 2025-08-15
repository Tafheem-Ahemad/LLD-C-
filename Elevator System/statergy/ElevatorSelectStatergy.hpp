#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"

class ElevatorSelectStatergy{
public:
	virtual Elevator* selectElevator(vector<Elevator*>elevators,Request request)=0;
	virtual ~ElevatorSelectStatergy() = default;
};
