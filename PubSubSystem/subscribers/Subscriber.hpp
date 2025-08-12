#pragma once
#include<bits/stdc++.h>
#include "Message.hpp"

using namespace std;

class Subscriber{
public:
	virtual ~Subscriber() = default; 
	virtual string getId() =0;
	virtual void onMessage(const Message &message) =0;
}

