#pragma once
#include<bits/stdc++.h>
using namespace std;

class Player{
private:
	const string id;
	string name;
public:
	Player(const string id,const string name);
	
	// getter && setter
	string getId() const;
	string getName() const;
	void setName(const string &name);
};