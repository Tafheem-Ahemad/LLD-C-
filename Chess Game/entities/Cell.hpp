#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Color.hpp"
#include "Piece.hpp"

class Cell{
private:
	Piece* piece;
	bool Empty;
	const Color color;
public:
	Cell(const Color color);
	~Cell();

	bool isEmpty() const;
	bool makeEmpty();

	Piece* getPiece() const;
	void setPiece(Piece* piece);
	Color getColor() const;
};