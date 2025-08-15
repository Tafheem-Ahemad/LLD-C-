#include "IdleState.hpp"
#include "MovingDownState.hpp"
#include "MovingUpState.hpp"
#include "Request.cpp"
#include "Direction.hpp"
#include "RequestSouce.hpp"

void MovingUpState::move(Elevator* elevator) {
	if(elevator->upRequest.empty()) {
		elevator->setState(new IdleState());
		return;
	}

	int firstUpFloor = *elevator->upRequest.begin();
	elevator->setCurrentFloor(elevator->getCurrentFloor() + 1);

	if(elevator->getCurrentFloor() == firstUpFloor) {
		elevator->upRequest.erase(firstUpFloor);
		if(elevator->upRequest.empty()) {
			elevator->setState(new IdleState());
		}
	}

}

void MovingUpState::addRequest(Elevator* elevator, Request request) {
	if(request.getRequestSource() == RequestSource::INTERNAL) {
		if(request.getTargetFloor() > elevator->getCurrentFloor()) {
			elevator->upRequest.insert(request.getTargetFloor());
		} else if(request.getTargetFloor() < elevator->getCurrentFloor()) {
			elevator->downRequest.insert(request.getTargetFloor());
		}
	} else {
		if(request.getDirection() == Direction::UP && request.getTargetFloor() >= elevator->getCurrentFloor()) {
			elevator->upRequest.insert(request.getTargetFloor());
		} else if(request.getDirection() == Direction::DOWN) {
			elevator->downRequest.insert(request.getTargetFloor());
		}
	}
}

Direction MovingUpState::getDirection() const {
	return Direction::UP;
}