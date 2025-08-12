#pragma once
#include<bits/stdc++.h>

#include "Subscriber.hpp"
#include "Message.hpp"

class NewsSubscriber : public Subscriber{
private:
	string id;
	string name;

public:
	NewsSubscriber(const string& id,const string& name);

	string getId() const override;
	string getName() const;

	void onMessage(const Message &message) override;
};