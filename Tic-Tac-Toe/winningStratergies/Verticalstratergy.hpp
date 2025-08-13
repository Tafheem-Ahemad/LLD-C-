#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "GameStatergy.hpp"

class VerticalStratergy : public GameStratrergy{
public:
	bool checkStratergy(const Board* board,const Symbol symbol, const int &x, const int &y) override;
};