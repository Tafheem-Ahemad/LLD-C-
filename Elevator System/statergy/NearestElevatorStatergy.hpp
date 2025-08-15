#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"
#include "ElevatorSelectStatergy.hpp"

class NearestElevatorStatergy : public ElevatorSelectStatergy{
public:
	Elevator* selectElevator(vector<Elevator*>elevators,Request request) override{

		// do somne logic , 
		// return null if no Elevator is present

		return elevators[0];
	}
};