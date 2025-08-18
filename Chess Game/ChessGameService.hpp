#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Position.hpp"
#include "Piece.hpp"
#include "PlayingStatergy.hpp"
#include "Player.hpp"
#include "Game.hpp"

class ChessGameService{
private:
	/* data */
	map<string,Game*>games;
	map<string,Player*>players;

	ChessGameService(/* args */);
	~ChessGameService();

	// Disable copy and move semantics
	ChessGameService(const ChessGameService&) = delete;
	ChessGameService& operator=(const ChessGameService&) = delete;
	ChessGameService(ChessGameService&&) = delete;
	ChessGameService& operator=(ChessGameService&&) = delete;
public:
	static ChessGameService& getIntance();
	
	void addNewGame(Player* player1,Player* player2,Color color1,Color color2) ;
	Game* getGame(const string& id);
	void makeMove(const string& id,Position source,Position destination);
	vector<Position> getAllPossibleMoves(const string& id,Position source);
	void makeGameOver(const string& id);
	void makeDraw(const string& id);
	void resetGame(const string& id);
	void addPlayer(const string& id, const string& name, PieceType pieceType);
	Player* getPlayer(const string& id);
	vector<Player*> getAllPlayers() const;
	void removePlayer(const string& id);

	vector<Move> getMovesByPlayer(const string& gameId, const string& playerId) const;
	vector<Move> getAllMoves(const string& gameId) const;
private:
	string getNewGameId() const;
	string getNewPlayerId() const;
	string getRandomId() const;
};
