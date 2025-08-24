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
	Team* winner;
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

	// Observer pattern methods
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyAllObservers(const Ball ball) const;

	void addNewInning(Inning* inning);
	void addNewBall(Ball ball);
	void startMatch();
	void endMatch();

	int getTotalOvers() const;
	bool isMatchComplete() const;
	int getTotalInnings() const;
	int getCurrentOverNumber() const;
	int getCurrentBallNumber() const;
	int getWicketsRemaining() const;
	int getCurrentScore() const;
	

	// getter setter
	const Team* getTeam1() const;
	const Team* getTeam2() const;
	vector<Inning*> getInnings() const;
	Inning* getCurrentInning() const;
	int getCurrentInningIndex() const;
	void setCurrentInningIndex(int index);
	const Team* getCurrentBattingTeam() const;
	void setCurrentBattingTeam(const Team* team);
	const PlayingFormat* getPlayingFormat() const;
	const GameState* getGameState() const;
	const GameStatus getGameStatus() const;
	const Team* getWinner() const;
	

};