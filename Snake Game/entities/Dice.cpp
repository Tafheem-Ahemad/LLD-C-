#include "Dice.hpp"

Dice::Dice(int maxValue):maxValue(maxValue){
	
}

Dice::~Dice(){
	
}

int Dice::getNewValue(){
	int value = rand()%maxValue + 1;
	previousValues.push_back(value);
	return value;
}

vector<int> Dice::getPreviousValues() const{
	return this->previousValues;
}
