#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "PaymentStatergy.hpp"

class UPIPayment : public PaymentStatergy{
public:
	bool processPayment(Account* sourceAccount,Account* DestinationAccount,Currency currency,double amount){
		// process payment using UPI
		// check if sourceAccount has enough balance
		if(sourceAccount->getBalance() < amount){
			cout<<"Insufficient balance in source account"<<endl;
			return false;
		}

		// assume UPI payment is successful
		// process payment
		sourceAccount->withdraw(amount);
		DestinationAccount->deposite(amount);
		return true;
	}
};