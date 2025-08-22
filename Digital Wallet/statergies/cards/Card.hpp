#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "PaymentStatergy.hpp"
#include "CardType.hpp"

class Card{
protected:
	const string number;
	const Account* account;
	string PIN;
	const CardType type;
public:
	Card(const string number,const Account* account, const string &pin);

	// process methods
	virtual void processPayment(const Currency currency,const double amount) = 0;
	virtual string getType() const = 0;

	// getter setter
	string getNumber() const;
	Account* getAccount() const;
	string getPIN() const;
	void setPIN(const string &pin);
	void getUser() const;


};