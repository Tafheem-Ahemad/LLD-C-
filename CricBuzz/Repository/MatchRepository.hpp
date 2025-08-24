#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Match.hpp"
#include "Team.hpp"
#include "PlayingFormat.hpp"

class MatchRepository{
private:
	map<string,Match*>matches;
	MatchRepository();
	~MatchRepository();

	MatchRepository (const MatchRepository& other) = delete;
	MatchRepository& operator=(const MatchRepository& other) = delete;
	MatchRepository (MatchRepository&& other) = delete;
	MatchRepository& operator=(MatchRepository&& other) = delete;
public:

	static MatchRepository& getInstance();

	Match* createNewMatch(const string& formatType,Team* team1,Team* team2);
	void addMatch(Match* match);
	Match* getMatchById(const string& matchId);	
	vector<Match*> getAllMatches() const;
private:
	string generateMatchId();
};