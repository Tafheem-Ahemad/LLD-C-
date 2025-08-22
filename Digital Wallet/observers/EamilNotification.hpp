#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Currency.hpp"
#include "Observer.hpp"

class EmailNotification: public Observer{
public:
	void getMoney(const User* user,const Currency currency,const double amount) override{
		// send email to user
		cout<<"Email Notification: "<<amount<<" "<<currency<<" has been credited to your account "<<user->getEmail()<<endl;
	}
};