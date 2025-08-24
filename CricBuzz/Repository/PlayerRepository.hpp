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

	void addPlayer(Player* player);
	Player* getPlayerById(const string& playerId);	
	vector<Player*> getAllPlayers() const;
};

