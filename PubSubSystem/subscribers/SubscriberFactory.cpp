#include<bits/stdc++.h>
#include "Subscriber.hpp"
#include "NewsSubscriber.hpp"
#include "AlertSubscriber.hpp"
using namespace std;

Subscriber* createSubScriber(const string &type,const string &name,const string &id){
	if(type=="news"){
		return new NewsSubscriber(id,name);
	}else if(type=="alert"){
		return new AlertSubscriber(id,name);
	}else return NULL;
}