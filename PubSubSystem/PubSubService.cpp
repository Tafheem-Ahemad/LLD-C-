#include<bits/stdc++.h>
#include "PubSubService.hpp"
#include "Topic.hpp"
#include "Subscriber.hpp"
#include "SubscriberFactory.cpp"

PubSubService::PubSubService(){}

PubSubService::~PubSubService(){
	for(auto it:topicRegitry) delete(it.second);
	for(auto it:subscriberRegistry) delete(it.second);
}

PubSubService::PubSubService& getInstance(){
	static PubSubService instance;
	return instance;
}

string PubSubService::createTopic(const string& topicName){
	string newID="";
	while(true){
		newID=generateTopicId();
		if(mp.count(newID)==0) break;
	}

	Topic* newTopic=new Topic(newID,topicName);
	topicRegitry[newID]=newTopic;
	return newID;
}

void PubSubService::removeTopic(const string& topicId){
	Topic* topic=findTopic(topicId);
	if(topic != nullptr) delete(topic);
	topicRegitry.erase(topicId);
}

string PubSubService::createSubscriber(const string type,const string& topicName){
	string newID="";
	while(true){
		newID=generateSubscriberId();
		if(mp.count(newID)==0) break;
	}

	Topic* newSubscriber=createSubScriber(type,newID,topicName);
	subscriberRegistry[newID]=newSubscriber;
	return newID;
}

void PubSubService::removeSubscriber(const string& subsriberId){
	Subscriber* subscriber=findTopic(subsriberId);
	if(subscriber != nullptr) delete(subscriber);
	subscriberRegistry.erase(topicId);
}

void PubSubService::subscribe(const string& subscriberId,const string& topicId){
	Topic* topic=findTopic(topicID);
	if(topic==NULL){
		assert(0);
	}
	Subscriber* subscriber=findSubscriber(subscriberId);
	if(subscriber==NULL){
		assert(0);
	}

	topic->addSubscriber(subscriber);
}

void PubSubService::unsubscribe(const string& subscriberId,const string& topicId){
	Topic* topic=findTopic(topicID);
	if(topic==NULL){
		assert(0);
	}
	Subscriber* subscriber=findSubscriber(subscriberId);
	if(subscriber==NULL){
		assert(0);
	}

	topic->removeSubscriber(subscriber);
}

void PubSubService::publish(const string& topicId,const Message& message){
	Topic* topic=findTopic(topicID);
	if(topic==NULL){
		assert(0);
	}

	topic.public(message);
}

Subscriber* PubSubService::findSubscriber(const string& subscriberID) const{
	auto find=subscriberRegistry.find(subscriberID);
	if(find==subscriberRegistry.end()) return nullptr;
	return find->secend;
}

Topic* PubSubService::findTopic(const string& topicID) const{
	auto find=topicRegitry.find(subscriberID);
	if(find==topicRegitry.end()) return nullptr;
	return find->secend;
}


string PubSubService::generateSubscriberId(){
	return "SUB:"+randomString(10);
}
string PubSubService::generateTopicId(){
	return "TOP:"+randomString(10);
}

string PubSubService::randomString(int length) {
    const string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";

    random_device rd;       
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, chars.size() - 1);

    string result;
    result.reserve(length);
    for (int i = 0; i < length; ++i) {
        result += chars[distrib(gen)];
    }
    return result;
}