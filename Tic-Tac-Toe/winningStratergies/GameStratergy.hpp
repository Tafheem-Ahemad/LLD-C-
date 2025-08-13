#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Symbol.hpp"
#include "Board.hpp"

class GameStratergy{
public:
	virtual ~GameStratergy() = default;
	virtual bool checkStratergy(const Board* board,const Symbol symbol,const int &x, const int &y) = 0;
};