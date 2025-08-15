#include "NearestElevatorStatergy.hpp"
#include "Elevator.hpp"
#include "ElevatorSelectStatergy.hpp"

Elevator* NearestElevatorStatergy::selectElevator(vector<Elevator*> elevators,Request request) {
	if (elevators.empty()) {
		throw runtime_error("No elevators available");
	}

	// Logic to find the nearest elevator based on the targetNode
	// For simplicity, we will just return the first elevator in the list
	// In a real implementation, you would calculate the distance to each elevator
	// and return the one that is closest to the targetNode

	return *elevators[0];
}