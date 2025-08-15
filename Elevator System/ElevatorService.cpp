#include "ElevatorService.hpp"
#include "Elevator.hpp"
#include "ElevatorSelectStatergy.hpp"
#include "Request.hpp"
#include "Direction.hpp"
#include "Display.hpp"
#include "Display.hpp"

ElevatorService::ElevatorService(int numElevators, ElevatorSelectStatergy* strategy): selectStrategy(strategy) {
	Display* display = new Display();
	for (int i = 0; i < numElevators; ++i) {
		string elevatorId = "Elevator_" + to_string(i + 1);
		addElevator(elevatorId,display);
	}
}

void ElevatorService::addElevator(const string& elevatorId,const ElevatorObserver* display) {
	if (elevators.find(elevatorId) != elevators.end()) {
		throw runtime_error("Elevator with this ID already exists");
	}
	Elevator* elevator = new Elevator(elevatorId);
	elevators[elevatorId] = elevator;
	elevator->addObserver(new Display());
}

void ElevatorService::removeElevator(const string& elevatorId) {
	auto it = elevators.find(elevatorId);
	if (it == elevators.end()) {
		throw runtime_error("Elevator with this ID does not exist");
	}
	delete it->second; // Clean up the Elevator object
	elevators.erase(it);
}

Elevator* ElevatorService::getElevator(const string& elevatorId){
	auto it = elevators.find(elevatorId);
	if (it == elevators.end()) {
		throw runtime_error("Elevator with this ID does not exist");
	}
	return it->second;
}

void ElevatorService::setSelectStrategy(ElevatorSelectStatergy* strategy){
	if (selectStrategy) {
		delete selectStrategy;
	}
	selectStrategy = strategy;
}
ElevatorSelectStatergy* ElevatorService::getSelectStrategy() const{
	return selectStrategy;
}

void ElevatorService::start() {
	for (auto& pair : elevators) {
		Elevator* elevator = pair.second;
		elevatorThreads.emplace_back(std::ref(*elevator));
	}
}

void ElevatorService::stop() {
	for (auto& pair : elevators) {
		Elevator* elevator = pair.second;
		elevator->stopElevator();
	}
	for (auto& thread : elevatorThreads) {
		if (thread.joinable()) {
			thread.join();
		}
	}
	elevatorThreads.clear();
}
void ElevatorService::requestElevator(const Direction& direction,const int targetFloor){
	Request request(targetFloor, direction, RequestSource::EXTERNAL);
	vector<Elevator*> elevatorList;
	for (auto& pair : elevators) {
		elevatorList.push_back(pair.second);
	}

	Elevator* selectedElevator = selectStrategy->selectElevator(elevatorList, request);
	if(selectedElevator == nullptr) {
		throw runtime_error("No elevator available , Please wait for a while");
	}

	selectedElevator->addRequest(request);
}

void ElevatorService::selectFloor(const string& elevatorId,const int targetFloor){
	auto it = elevators.find(elevatorId);
	if (it == elevators.end()) {
		throw runtime_error("Elevator with this ID does not exist");
	}
	Elevator* elevator = it->second;
	Request request(targetFloor, Direction::IDLE, RequestSource::INTERNAL);
	elevator->addRequest(request);
}