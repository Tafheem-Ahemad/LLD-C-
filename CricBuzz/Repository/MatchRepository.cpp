#include "MatchRepository.hpp"

MatchRepository::MatchRepository(){
}

MatchRepository::~MatchRepository(){
	for(auto& matchPair : matches){
		delete matchPair.second;
	}
}

MatchRepository& MatchRepository::getInstance(){
	static MatchRepository instance;
	return instance;
}

Match* MatchRepository::createNewMatch(const string& formatType,Team* team1,Team* team2){
	string matchId = generateMatchId();
	PlayingFormat* format;
	if(formatType == "T20"){
		format = new T20Format();
	}
	else if(formatType == "ODI"){
		format = new ODIFormat();
	}
	else if(formatType == "Test"){
		format = new TestFormat();
	}
	else{
		throw runtime_error("Invalid format type");
	}
	Match* newMatch = new Match(matchId,team1,team2,format);
	matches[matchId] = newMatch;
	return newMatch;
}

void MatchRepository::addMatch(Match* match){
	matches[match->getId()] = match;
}

Match* MatchRepository::getMatchById(const string& matchId){
	if(matches.find(matchId) == matches.end()){
		throw runtime_error("Match with given id does not exist");
	}
	return matches[matchId];
}

vector<Match*> MatchRepository::getAllMatches() const{
	vector<Match*> allMatches;
	for(const auto& matchPair : matches){
		allMatches.push_back(matchPair.second);
	}
	return allMatches;
}

string MatchRepository::generateMatchId(){
	static int matchIdCounter = 1;
	return "MATCH" + to_string(matchIdCounter++);
}

