#include "T20Formal.hpp"

int T20Format::getTotalOvers() const{
	return 20;
}

void AddInning(const Match* match,Inning* inning) {
	if(match->getInnings().size() == 2){
		assert(0);
	}

	match->innings.push_back(inning);
}

int T20Format::totalInning() const{
	return 2;
}

string  T20Format::getFormatName() const{
	return "T20";
}