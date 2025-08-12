#pragma once
#include<bits/stdc++.h>

#include "Subscriber.hpp"
#include "Message.hpp"

class AlertSubscriber : public Subscriber{
private:
	string id;
	string name;

public:
	AlertSubscriber(string id,string name);

	string getId() const override;
	string getName() const;

	void onMessage(const Message &message) override;
};