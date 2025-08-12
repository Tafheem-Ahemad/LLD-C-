#pragma once
#include<bits/stdc++.h>
#include "Subscriber.hpp"

using namespace std;

class Topic{
private:
	string name;
	set<Subscriber*>subscribers;

public:
	Topic(const std::string& id,const std::string& name);

	string getName() const;
	string getId() const;
	vector<Subscriber*> getSubscribers() const;

	void addSubscriber(Subscriber* subscriber);
	void removeSubscriber(Subscriber* subscriber);

	void broadcast(const Message& message);
};
