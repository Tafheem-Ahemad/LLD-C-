#pragma once
#include<bits/stdc++.h>
using namespace std;

class Dice {
private:
	const int maxValue;
	vector<int>previousValues;
public:
	Dice(int maxValue=6);
	~Dice();

	int getNewValue();
	vector<int> getPreviousValues() const;
};