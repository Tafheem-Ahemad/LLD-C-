#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"

class PaymentStatergy{
public:
	virtual bool processPayment(Account* sourceAccount,Account* DestinationAccount,Currency currency,double amount) = 0;
};