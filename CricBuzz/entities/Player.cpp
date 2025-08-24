#include "Player.hpp"

Player::Player(const string& id,const string& name):id(id),name(name){

}

// getter && setter
string Player::getName() const{
	return name;
}

string Player::getId() const{
	return id;
}

year_month_day Player::getDob() const{
	return dob;
}

double Player::getHeight() const{
	return height;
}

double Player::getWeight() const{
	return weight;
}
