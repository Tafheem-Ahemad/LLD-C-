#include "ODIFormat.hpp"

const int ODIFormat::getTotalOvers() const{
	return 50;
}
const void ODIFormat::AddInning(const Match* match,Inning* inning) {
	if(match->getTotalInnings() == 2){
		throw runtime_error("Cannot add more innings to the match");
	}
	match->innings.push_back(inning);
}

const int ODIFormat::totalInning() const{
	return 2;
}

const string  ODIFormat::getFormatName() const{
	return "ODI";
}

