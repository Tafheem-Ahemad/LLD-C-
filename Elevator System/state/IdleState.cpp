#include "IdleState.hpp"
#include "MovingDownState.hpp"
#include "MovingUpState.hpp"
#include "Request.cpp"
#include "Direction.hpp"
#include "RequestSouce.hpp"

void IdleState::move(Elevator* elevator) {
	if(!elevator->upRequest.empty()){
		elevator->setState=new MovingDownState();
		elevator.move();
	}else if(!elevator->downRequest.empty()){
		elevator->setState=new MovingUpState();
		elevator.move();
	}
}

void IdleState::addRequest(Elevator* elevator,Request request){
	if(request.getTargetFloor() < elevator->getCurrentFloor()){
		elevator->downRequest.insert(request.getTargetFloor());
	}else if(request.getTargetFloor() > elevator->getCurrentFloor()){
		elevator->upRequest.insert(request.getTargetFloor());
	}
}

Direction IdleState::getDirection() const {
	return Direction::IDLE;
}