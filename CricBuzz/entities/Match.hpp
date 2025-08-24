#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Inning.hpp"
#include "Team.hpp"
#include "Over.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include "Observer.hpp"
#include "PlayingFormat.hpp"
#include "GameState.hpp"
#include "GameStatus.hpp"

class Match{
private:
	const Team* team1;
	const Team* team2;
	vector<Inning*>innings;
	int currentInningIndex;
	const Team* currentBattingTeam;

	vector<Observer*> observers;

	const PlayingFormat* playingFormat;
	const GameState* gameState;

	const GameStatus gameStatus;
public:
	Match(const Team* team1,const Team* team2,const PlayingFormat* playingFormat);
	~Match();
};