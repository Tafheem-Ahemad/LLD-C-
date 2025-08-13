#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Symbol.hpp"

class Player{
private:
	string name;
	const Symbol symbol;
public:
	Player(const string &name,const Symbol &symbol);
	string getName() const;
	Symbol getSymbol() const;
};