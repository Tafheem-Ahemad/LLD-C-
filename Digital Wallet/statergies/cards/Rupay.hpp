#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "PaymentStatergy.hpp"
#include "Card.hpp"
#include "CardType.hpp"

class Rupay : public Card{
public:
	Rupay(string number,const Account* account, const string &pin):Card(number,account,pin){
		this->type = CardType::Rupay;
	}

	void processPayment(const Currency currency,const double amount) override{
		// do something , maybe call some api
		// also check if enough balance is there in account
		cout<<"Processing payment of "<<amount<<" "<<currency<<" using Rupay card "<<this->number<<endl;
		this->account->withdraw(amount);
	}
	CardType getType() const override {
		return this->type;
	}
};