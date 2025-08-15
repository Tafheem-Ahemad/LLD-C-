#include "IdleState.hpp"
#include "MovingDownState.hpp"
#include "MovingUpState.hpp"
#include "Request.cpp"
#include "Direction.hpp"
#include "RequestSouce.hpp"

void MovingDownState::move(Elevator* elevator) {
	if(elevator->downRequest.empty()) {
		elevator->setState(new IdleState());
		return;
	}

	int firstDownFloor = *elevator->downRequest.begin();
	elevator->setCurrentFloor(elevator->getCurrentFloor() - 1);

	if(elevator->getCurrentFloor() == firstDownFloor) {
		elevator->downRequest.erase(firstDownFloor);
		if(elevator.downRequest.empty()) {
			elevator->setState(new IdleState());
		}
	}

}

void MovingDownState::addRequest(Elevator* elevator, Request request) {
	if(request.getRequestSource() == RequestSource::INTERNAL) {
		if(request.getTargetFloor() < elevator->getCurrentFloor()) {
			elevator->downRequest.insert(request.getTargetFloor());
		} else if(request.getTargetFloor() > elevator->getCurrentFloor()) {
			elevator->upRequest.insert(request.getTargetFloor());
		}
	} else {
		if(request.getDirection() == Direction::DOWN && request.getTargetFloor() <= elevator->getCurrentFloor()) {
			elevator->downRequest.insert(request.getTargetFloor());
		}else if(request.getDirection() == Direction::UP) {
			elevator->upRequest.insert(request.getTargetFloor());
		}
	}
}

Direction MovingDownState::getDirection() const {
	return Direction::DOWN;
}