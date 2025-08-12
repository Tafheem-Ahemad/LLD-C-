#pragma once

#include <bits/stdc++.h>
#include "Topic.hpp"
#include "Subscriber.hpp"
#include "Message.hpp"

using namespace std;

class PubSubService {
private :
	map<string,Topic*>topicRegitry;
	map<string,Subscriber*>subscriberRegistry;

	PubSubService();
    ~PubSubService();

    // Disable copy/move semantics
    PubSubService(const PubSubService&) = delete;
    PubSubService& operator=(const PubSubService&) = delete;
    PubSubService(PubSubService&&) = delete;
    PubSubService& operator=(PubSubService&&) = delete;

public:

	static PubSubService& getInstance();

	string createTopic(const string& topicName);
	void removeTopic(const string& topicId);

	string createSubsriber(const string& subsriberName);
	void removeSubscriber(const string& subsriberId);

	void subscribe(const string& subscriberId,const string& topicId);
	void unsubscribe(const string& subscriberId,const string& topicId);
	void publish(const string& topicId,const Message& message);

private:
	Subscriber* findSubscriber(const string& subscriberID) const;
	Topic* findTopic(const string& topicID) const;

	string generateSubscriberId();
	string generateTopicId();
	string randomString(int length);
}