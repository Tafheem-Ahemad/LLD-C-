#include<bits/stdc++.h>
#include "AlertSubscriber.hpp"

AlertSubscriber::AlertSubscriber(const std::string& id, const std::string& name) : id(id),name(name){}

string AlertSubscriber::getId() const override{
	return this->id;
}

string AlertSubscriber::getName() const{
	return this->name;
}

void AlertSubscriber::onMessage(Message &message) override{
	// do some bussiness logic;
}