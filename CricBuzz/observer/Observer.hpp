#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Match.hpp"
#include "Ball.hpp"

class Observer{
public:
	virtual void update(Match* match,const Ball ball) = 0;
};