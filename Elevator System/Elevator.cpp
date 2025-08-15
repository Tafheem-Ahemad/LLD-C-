#include "Elevator.hpp"

Elevator::Elevator(const string &id) 
	: id(id), currentFloor(1), isrunning(false) {
	curState = new IdleState(); 
}

void Elevator::move(){
	this->curState->move(this);
}
void Elevator::setState(ElevatorState* state){
	if (curState) {
		delete curState; // Clean up the old state
	}
	curState = state;
	notifyObservers(); 
}


void Elevator::addObserver(ElevatorObserver* observer){
	for(auto& obs : obervers) {
		if (obs == observer) {
			return; 
		}
	}
	obervers.push_back(observer);
}
void Elevator::notifyObservers(){
	for (auto& observer : obervers) {
		observer->update(this);
	}
}

void Elevator::addRequest(Request request) {
	curState->addRequest(this, request);
}

string Elevator::getId() const {
	return id;
}
string Elevator::isRunning() const {
	return isrunning ? "Running" : "Stopped";
}
Direction Elevator::getDirection() const {
	return curState->getDirection();
}
int Elevator::getCurrentFloor() const {
	return currentFloor.load();
}

bool Elevator::isRunning() const {
	return isrunning;
}

void Elevator::stopElevator() {
	isrunning = false;
	setState(new IdleState());
}
void Elevator::setCurrentFloor(int floor) {
	currentFloor.store(floor);
	notifyObservers();
}

set<int> Elevator::getUpRequest() const {
	return upRequest;
}
set<int> Elevator::getDownRequest() const {
	return downRequest;
}
void Elevator::addUpRequest(int floor) {
	upRequest.insert(floor);
}
void Elevator::addDownRequest(int floor) {
	downRequest.insert(floor);
}

Elevator::~Elevator() {
	delete curState; // Clean up the current state
	for (auto observer : obervers) {
		delete observer; // Clean up observers if they are dynamically allocated
	}
	obervers.clear(); // Clear the observer list
}

void Elevator::operator()() {
    while (isRunning) {
        move();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
