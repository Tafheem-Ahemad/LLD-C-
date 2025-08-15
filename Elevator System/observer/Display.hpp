#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"

class Display : public ElevatorObserver{
public:
	void update(const Elevator* elevator) override{
		// do some work
		cout<<"Elevator with id"<<elevator.getId()<<" current floor "<<elevator.getFloor()<<endl;
	}
};

