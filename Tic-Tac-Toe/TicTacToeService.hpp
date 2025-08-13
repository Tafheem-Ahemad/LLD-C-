#pragma once
#include <bits/stdc++.h>
using namespace std;

class TicTacToeService{
private:

	map<string,Game*>gameRegistry;
	
	TicTacToeService();
	~TicTacToeService();

	// delete copy any external
	TicTacToeService(const TicTacToeService&) =delete;
	TicTacToeService& operator=(const TicTacToeService&) =delete;
	TicTacToeService(TicTacToeService&&) =delete;
	TicTacToeService& operator=(TicTacToeService&&) =delete;

public:
	static TicTacToeService& getIntance();

	Game* createNewGame(const string &player1Name,const string &player2Name,const int size = 3);

	void makeMove(const string &gameId,Player* player, const int &x, const int &y);
	
	void  printBoard(const string &gameId) const;
	Game* getGame(const string &gameId) const;
private:
	string createGameId();
	string randomString(CONST int length);
};
