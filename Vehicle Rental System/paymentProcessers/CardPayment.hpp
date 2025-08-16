#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Reservation.hpp"
#include "PaymentStatergy.hpp"

class CardPayment : public PaymentStatergy {
private:
	const string upiId;
	const string cardNumber;
	const string cardHolderName;
public:
	CardPayment(const string& upiId, const string& cardNumber, const string& cardHolderName)
		: upiId(upiId), cardNumber(cardNumber), cardHolderName(cardHolderName) {}
		
	void pay(double amount) const override {
		cout << "Processing card payment of amount: " << amount << endl;
		// Simulate card payment processing logic here
		cout << "Card payment successful." << endl;
	}
};