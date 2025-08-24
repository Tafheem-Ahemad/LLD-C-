#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Player.hpp"

class PlayerRepository{
private:
	map<string,Player*>players;
	PlayerRepository();
	~PlayerRepository();

	PlayerRepository (const PlayerRepository& other) = delete;
	PlayerRepository& operator=(const PlayerRepository& other) = delete;
	PlayerRepository (PlayerRepository&& other) = delete;
	PlayerRepository& operator=(PlayerRepository&& other) = delete;
public:

	static PlayerRepository& getInstance();

	Player* createNewPlayer(const string& name, const year_month_day& dob, double height, double weight);
	Player* getPlayerById(const string& playerId);	
	vector<Player*> getAllPlayers() const;
private:
	string generatePlayerId();
};

