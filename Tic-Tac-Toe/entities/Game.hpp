#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Symbol.hpp"
#include "Cell.hpp"
#include "Board.hpp"
#include "GameStatus.hpp"
#include "Player.hpp"
#include "GameStratergy.hpp"
#include "HorizontalStatergy.hpp"
#include "VerticalStatergy.hpp"
#include "DiagonalStratergy.hpp"
#include "InProgressState.hpp"
#include "DrawState.hpp"
#include "WinState.hpp"
#include "GameState.hpp"

class Game{
private:
	const string id;
	Board* board;
	GameStatus gameStatus;
	Player* player1;
	Player* player2;
	Player* curPlayer;
	Player* WinnerPlayer;
	vector<GameStatergy*> stratergies;
	GameState* curState;
public:

	Game(const string &id,Player* player1,Player* player2,const int size);
	~Game() {}
	void swapPlayer();
	void makeMove(Player* player,const  &int x,const &int y);
	bool checkWinner(Player* player,const  &int x,const &int y);
	void reset();

	Board* getBoard() const;
	GameStatus getGameStatus() const;
	Player* getCurrentPlayer() const;
	Player* getWinnerPlayer() const;
	void setGameStatus(GameStatus status);
	void setCurState(GameState* state);
	void setWinnerPlayer(Player* player);


};