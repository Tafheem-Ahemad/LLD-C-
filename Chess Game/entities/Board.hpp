#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Position.hpp"
#include "cell.hpp"
#include "Piece.hpp"

class Board{
private:
	int size;
	vector<vector<Cell*>>board;
	CellColor color1;
	CellColor color2;
	vector<Piece*> deadPieces;
public:
	Board(int size, CellColor color1, CellColor color2);
	~Board();

	void initializeBoard();

	void makeMove(Position source,Position destination) ;
	bool isvalidMove(Position source,Position destination) const ;
	vector<Position> getAllValidPosiotion(const Position source) const;
	bool isValidPosition(const Position &position) const;
	bool isDrawn() const;
	bool isCheckMate() const;

	int getSize() const;
	Piece* getPiece(Position position) const;
	void setPiece(Position position);

	vector<Piece*> getDeadPieces() const;
private:
	void addDeadPiece(Piece* piece);
};