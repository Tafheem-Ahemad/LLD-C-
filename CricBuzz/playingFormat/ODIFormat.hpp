#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayingFormat.hpp"
#include "Match.hpp"

class ODIFormat : public PlayingFormat{
public:
	const int getOvers() const override;
	const void AddInning(const Match* match) override;
	const int totalInning() const override;
	const string  getFormatName() const override;
};
