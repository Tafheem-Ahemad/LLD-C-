#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Symbol.hpp"
#include "Cell.hpp"

class Board{
private:
	int size;
	vector<vector<Cell*>>board;
	int moveCount;

public:
	Board(const int &size);
	~Board() {}

	Symbol getCell(const int &x,const int &y) const;
	bool isFull() const;
	bool placeSymbol(const int &x,const int &y,const Symbol &symbol);
	void printBoard() const;
	void reset();

private:
	void initialize();

};