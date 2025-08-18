#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "PieceColor.hpp"
#include "GameStatus.hpp"

class Game{
private:
	Board* board;
	Player* player1;
	Player* player2;
	GameStatus status;
	Player* currentPlayer;
	Player* winner;
	vector<Move> moves;
	Color color1;
	Color color2;
public:
	Game(Player* player1, Player* player2, int boardSize, Color color1, Color color2);
	~Game();
	void start();
	void switchPlayer();
	void makeMove(Position source, Position destination);
	bool isValidMove(Position source, Position destination) const;
	vector<Position> getAllValidPositions(const Position source) const;
	bool isGameOver() const;
	void makeDraw();
	void resetGame();

	GameStatus getStatus() const;
	Player* getCurrentPlayer() const;
	Player* getWinner() const;
	Board* getBoard() const;
	vector<Move> getMoves() const;
	vector<Move> getMovesByPlayer(const Player* player) const;

	void addMove(const Move& move);
	void setStatus(GameStatus newStatus)
};