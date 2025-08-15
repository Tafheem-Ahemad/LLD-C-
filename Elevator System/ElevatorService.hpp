#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"
#include "ElevatorObserver.hpp"
#include "ElevatorSelectStatergy.hpp"
#include "ElevatorState.hpp"
#include "RequestSouce.hpp"
#include "Request.hpp"
#include "Direction.hpp"

class ElevatorService{
private:
	map<string, Elevator*> elevators;
	ElevatorSelectStatergy* selectStrategy;
	vector<thread> elevatorThreads;

	ElevatorService(int numElevators, ElevatorSelectStatergy* strategy);
	~ElevatorService();

	ElevatorService(const ElevatorService&) = delete; // Disable copy constructor
	ElevatorService& operator=(const ElevatorService&) = delete; // Disable assignment operator
	ElevatorService(ElevatorService&&) = delete; // Disable move constructor
	ElevatorService& operator=(ElevatorService&&) = delete; // Disable move assignment operator
public:
	static ElevatorService& getInstance(int numElevators, ElevatorSelectStatergy* strategy) ;

	void addElevator(const string& elevatorId, const ElevatorObserver* display);
	void removeElevator(const string& elevatorId);
	Elevator* getElevator(const string& elevatorId);

	void setSelectStrategy(ElevatorSelectStatergy* strategy);
	ElevatorSelectStatergy* getSelectStrategy() const;

	void start();
	void stop();

	// facades
	void requestElevator(const Direction& direction,const int targetFloor);
	void selectFloor(const string& elevatorId,const int targetFloor);
};
