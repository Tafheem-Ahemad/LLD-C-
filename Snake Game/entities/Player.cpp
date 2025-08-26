#include "Player.hpp"

Player::Player(const string id,const string name):id(id),name(name){
	
}

// getter && setter
string Player::getId() const{
	return this->id;
}

string Player::getName() const{
	return this->name;
}

void Player::setName(const string &name){
	this->name = name;
	throw runtime_error("Name is const");
}