#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Account.hpp"
#include "User.hpp"
#include "Currency.hpp"

class Transaction{
private:
	string id;
	const Account* sourceAccount;
	const Account* destinationAccount;
	const Currency currency;
	double money;
	time_t timeStamp;
public:
	Transaction(const string &id, 
	            const Account* sourceAccount, 
	            const Account* destinationAccount, 
	            const Currency currency, 
	            double money);

	// getter && setter
	string getId() const;
	const Account* getSourceAccount() const;
	const Account* getDestinationAccount() const;
	Currency getCurrency() const;
	double getMoney() const;
	time_t getTimeStamp() const;
};
