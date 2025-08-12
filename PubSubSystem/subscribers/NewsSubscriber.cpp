#include<bits/stdc++.h>
#include "NewsSubscriber.hpp"

NewsSubscriber::NewsSubscriber(const std::string& id, const std::string& name) : id(id),name(name){}

string NewsSubscriber::getId() const override{
	return this->id;
}

string NewsSubscriber::getName() const{
	return this->name;
}

void NewsSubscriber::onMessage(Message &message) override{
	// do some bussiness logic;
}