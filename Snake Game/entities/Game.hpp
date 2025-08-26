#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Player.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "GameState.hpp"

class Game{
private:
	const string id;
	const string name;
	vector<Player*> players;
	int curIndex=0;
	Dice* dice;
	Player* winner;
	GameState gameState;
public:
	Game(const string id,const string name,vector<Player*> players);
	~Game();
	
	void startGame();
	void makeNextMove();
	int getNewDiceValue();
	Player* getCurrentPlayer() const;

	//getter setter;
	string getId() const;
	string getName() const;
	vector<Player*> getPlayers() const;
	Player* getWinner() const;
	GameState getGameState() const;
	void setGameState(const GameState &gameState);

};	