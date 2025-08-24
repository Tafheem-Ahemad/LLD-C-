#include "TeamRepository.hpp"

TeamRepository::TeamRepository(){
}

TeamRepository::~TeamRepository(){
	for(auto& teamPair : teams){
		delete teamPair.second;
	}
}

TeamRepository& TeamRepository::getInstance(){
	static TeamRepository instance;
	return instance;
}	

Team* TeamRepository::createNewTeam(const string& name,vector<Player*> players){
	string teamId = generateTeamId();
	Team* newTeam = new Team(teamId,name,players);
	teams[teamId] = newTeam;
	return newTeam;
}

void TeamRepository::addTeam(Team* team){
	teams[team->getId()] = team;
}

Team* TeamRepository::getTeamById(const string& teamId){
	if(teams.find(teamId) == teams.end()){
		throw runtime_error("Team with given id does not exist");
	}
	return teams[teamId];
}

vector<Team*> TeamRepository::getAllTeams() const{
	vector<Team*> allTeams;
	for(const auto& teamPair : teams){
		allTeams.push_back(teamPair.second);
	}
	return allTeams;
}

string TeamRepository::generateTeamId(){
	static int teamIdCounter = 1;
	return "TEAM" + to_string(teamIdCounter++);
}