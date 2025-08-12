#pragma once
#include<bits/stdc++.h>

class Message{
private:
	string payload;
	time_t timestamp;

public:
	Message(const std::string& payload);

	// getter and setter
	string getPayload() const;
	time_t getTimestamp() const;
};