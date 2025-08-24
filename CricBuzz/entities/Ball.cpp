
#include "Ball.hpp"

Ball::Ball(const Player* batsman,const Player* bowler,const BallOutput ballOutput):batsman(batsman),bowler(bowler),ballOutput(ballOutput){

}

// getter Setter
const Player* Ball::getBatsman() const{
	return batsman;
}

const Player* Ball::getBowler() const{
	return bowler;
}

BallOutput Ball::getBallOutput() const{
	return ballOutput;
}
