#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "GameStratergy.hpp"

class DiagonalStratergy : public GameStratergy{
public:
	bool checkStratergy(const Board* board,const Symbol symbol, const int &x, const int &y) override;
};