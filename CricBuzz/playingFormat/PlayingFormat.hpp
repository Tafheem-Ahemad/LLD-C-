#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Match.hpp"

class PlayingFormat{
public:
	const int getOvers() const =0;
	const void AddInning(const Match* match) =0;
	const int totalInning() const =0;
	const string  getFormatName() const =0;
};