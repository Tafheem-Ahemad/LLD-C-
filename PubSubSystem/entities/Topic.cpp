#include<bits/stdc++.h>
#include "Topic.hpp"
#include "Subscriber.hpp"

Topic::Topic(const std::string& id,const std::string& name): name(name),id(id){}

string Topic::getName() const{
	return this->name;
}
string Topic::getId() const{
	return this->id;
}

vector<Subscriber*> Topic::getSubscribers() const{
	return vector<Subscriber*>(this->subscribers.begin(),this->subscribers.end());
}

void Topic::addSubscriber(Subscriber* subscriber){
	this->subscribers.insert(subscriber);
}

void Topic::removeSubscriber(Subscriber* subscriber){
	this->subscribers.erase(subscriber);
}

void Topic::broadcast(const Message &message){
	for(auto subscriber:this->subscribers){
		subscriber->onMessage(message);
	}
}