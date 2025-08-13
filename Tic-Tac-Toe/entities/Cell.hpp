#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Symbol.hpp"
#include "GameStatus.hpp"

class Cell{
private:
	Symbol symbol;

public:
	Cell(const Symbol &symbol);
	Symbol getSymbol() const;
	void setSymbol(Symbol symbol);
};