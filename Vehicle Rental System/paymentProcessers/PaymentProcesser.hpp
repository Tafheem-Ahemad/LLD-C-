#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Reservation.hpp"
#include "PaymentStatergy.hpp"

class PaymentProcesser {
public:
	bool processPayment(const PaymentStatergy* paymentStrategy,const double amount) {
		// for simplicity assuming payment is always successful
		cout << "Processing payment of amount: " << amount << endl;
		paymentStrategy.pay(amount);
		cout << "Payment successful for reservation ID: " << reservation.getId() << endl;
		return true;
	}
};