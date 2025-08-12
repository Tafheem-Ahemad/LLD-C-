#include<bits/stdc++.h>
#include "Message.hpp"

Message::Message(const std::string& payload): payload(payload){
	timestamp = time(nullptr);
}

string Message::getPayload() const{
	return this->payload;
}
time_t Message::getTimestamp() const{
	return this->timestamp;
}

