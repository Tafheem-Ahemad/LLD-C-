#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Cell.hpp"
#include "CellType.hpp"
#include "Dice.hpp"
#include "Player.hpp"

class Board{
private:
	const int size;
	vector<vector<Cell*>> board;
	vector<Position> playerPositions;
public:
	Board(const int size);
	~Board();

	void makeMove(Player* Player,int value);
	bool isWinner(Player* player);
	void InitBoard();
	void printBoard() const;


	// getter setter
	int getSize() const;
	vector<vector<Cell*>> getBoard() const;
	vector<Position> getPlayerPositions() const;
};
