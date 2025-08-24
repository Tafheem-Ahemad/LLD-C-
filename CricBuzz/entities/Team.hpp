#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Player.hpp"

class Team{
private:
	const string id;
	string name;
	map<string,Player*>players;
public:
	Team(const string& name, const string& id);

	void addPlayer(Player* player);
	void removePlayer(Player* player);

	// getter setter
	Player* getPlayerById(const string& playerId);
	string getName() const;
	string getId() const;
	vector<Player*> getPlayers() const;
};