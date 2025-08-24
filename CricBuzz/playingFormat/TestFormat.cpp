#include "TestFormat.hpp"

int TestFormat::getTotalOvers() const{
	return 90;
}
void TestFormat::AddInning(const Match* match,Inning* inning) {
	if(match->getInnings().size() == 4){
		throw runtime_error("Cannot add more innings to the match");
	}

	match->innings.push_back(inning);
}

int TestFormat::totalInning() const{
	return 4;
}

string  TestFormat::getFormatName() const{
	return "Test";
}