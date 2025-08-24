#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Match.hpp"

class PlayingFormat{
public:
	virtual int getTotalOvers() const =0;
	virtual void AddInning(const Match* match,Inning* inning) =0;
	virtual int totalInning() const =0;
	virtual string  getFormatName() const =0;
};