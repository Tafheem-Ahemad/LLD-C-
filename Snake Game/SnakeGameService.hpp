#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Player.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "GameState.hpp"
#include "Game.hpp"

class SnakeGameService
{
private:
	
	SnakeGameService (const SnakeGameService&) = delete;
	SnakeGameService& operator=(const SnakeGameService&) = delete;
	SnakeGameService (SnakeGameService&&) = delete;
	SnakeGameService& operator=(SnakeGameService&&) = delete;

	SnakeGameService(/* args */);
	~SnakeGameService();

	map<string,Player*>players;
	map<string,Game*>games;
public:
	static SnakeGameService& getIntance();

	void createGame(const string name,vector<Player*> players);
	void createPlayer(const string name);

	void makeMove(const string &gameId);

	// getter && setter 
	Game* getGame(const string &gameId) const;
	Player* getPlayer(const string &playerId) const;
	Player* getwinner(const string &gameId) const;
	GameStatus getGameStatus(const string &gameId) const;
	
private:
	string getRandom(int lengh);
};
