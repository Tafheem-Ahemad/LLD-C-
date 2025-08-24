#pragma once
#include<bits/stdc++.h>
using namespace std;

class Player{
private:
	const string id;
	string name;
	year_month_day dob;
	double height;
	double weight;
public:
	Player();
	
	// getter && setter
	string getName() const;
	string getId() const;
	year_month_day getDob() const;
	double getHeight() const;
	double getWeight() const;
};
