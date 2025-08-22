#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "Card.hpp"
#include "PaymentStatergy.hpp"

class CardPayment : public PaymentStatergy{
	Card* card;
public:
	bool processPayment(Account* sourceAccount,Account* DestinationAccount,Currency currency,double amount) override {
		// process payment using card
		// check if card is valid and belongs to sourceAccount
		if(this->card->getAccount()->getAccountNumber() != sourceAccount->getAccountNumber()){
			cout<<"Card does not belong to source account"<<endl;
			return false;
		}

		//assume card is valid and has enough balance
		// process payment
		this->card->processPayment(currency,amount);
		DestinationAccount->deposite(amount);
		return true;
	}

	void setCard(Card* card){
		this->card = card;
	}

	void getCard(){
		return this->card;
	}
};