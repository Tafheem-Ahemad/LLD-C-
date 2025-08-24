#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "PlayingFormat.hpp"
#include "Match.hpp"

class ODIFormat : public PlayingFormat{
public:
	int getTotalOvers() const override;
	void AddInning(const Match* match,Inning* inning) override;
	int totalInning() const override;
	string  getFormatName() const override;
};
