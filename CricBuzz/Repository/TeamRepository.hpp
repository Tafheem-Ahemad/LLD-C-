#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Team.hpp"
#include "Player.hpp"

class TeamRepository{
private:
	map<string,Team*>teams;
	TeamRepository();
	~TeamRepository();

	TeamRepository (const TeamRepository& other) = delete;
	TeamRepository& operator=(const TeamRepository& other) = delete;
	TeamRepository (TeamRepository&& other) = delete;
	TeamRepository& operator=(TeamRepository&& other) = delete;
public:

	static TeamRepository& getInstance();
	Team* createNewTeam(const string& name,vector<Player*> players);
	Team* getTeamById(const string& teamId);	
	vector<Team*> getAllTeams() const;

private:
	string generateTeamId();
}