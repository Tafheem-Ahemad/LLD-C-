#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "PaymentStatergy.hpp"

class NetBanking : public PaymentStatergy{
public:
	bool processPayment(Account* sourceAccount,Account* DestinationAccount,Currency currency,double amount){
		// process payment using net banking
		// check if sourceAccount has enough balance
		if(sourceAccount->getBalance() < amount){
			cout<<"Insufficient balance in source account"<<endl;
			return false;
		}

		// assume net banking is successful
		// process payment
		sourceAccount->withdraw(amount);
		DestinationAccount->deposite(amount);
		return true;
	}
};
