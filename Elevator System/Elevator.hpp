#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Request.hpp"
#include "ElevatorObserver.hpp"
#include "ElevatorSelectStatergy.hpp"
#include "ElevatorState.hpp"
#include "RequestSouce.hpp"

class Elevator{
private:
	const string id;
	ElevatorState* curState;
	atomic<int> currentFloor;
	bool isrunning;

	
	// observer design pattern
	vector<ElevatorObserver*>obervers;
public:
	Elevator(const string &id);
	~Elevator();
	
	set<int>upRequest;
	set<int>downRequest;

	// state design patern
	void move();
	void setState(ElevatorState* state);

	// observer design patern
	void addObserver(ElevatorObserver* observer);
	void notifyObservers();

	void addRequest(Request request);

	// getter setter

	string getId() const;
	string isRunning() const;
	Direction getDirection() const;
	int getCurrentFloor() const;
	bool isRunning() const;

	
	void stopElevator();
	void setCurrentFloor(int Floor);

	void operator()();
};
