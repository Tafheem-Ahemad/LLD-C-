#pragma once
#include<bits/stdc++.h>
using namespace std;

class Message{
private:
	string payload;
	time_t timestamp;

public:
	Message(const string& payload);

	// getter and setter
	string getPayload() const;
	time_t getTimestamp() const;
};