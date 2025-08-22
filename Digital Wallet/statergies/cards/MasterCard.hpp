#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "PaymentStatergy.hpp"
#include "Card.hpp"
#include "CardType.hpp"

class MasterCard : public Card{
public:
	MasterCard(string number,const Account* account, const string &pin):Card(number,account,pin){
		this->type = CardType::MasterCard;
	}
	
	void processPayment(const Currency currency,const double amount) override {
		// do something , maybe call some api
		// also check if enough balance is there in account
		cout<<"Processing payment of "<<amount<<" "<<currency<<" using MasterCard card "<<this->number<<endl;
		this->account->withdraw(amount);
	}

	CardType getType() const override {
		return this->type;
	}
};