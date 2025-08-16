#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Reservation.hpp"
#include "PaymentStatergy.hpp"

class NetBankingPayment : public PaymentStatergy {
private:
	const string bankName;
	const string accountNumber;
	const string ifscCode;
public:
	NetBankingPayment(const string& bankName, const string& accountNumber, const string& ifscCode)
		: bankName(bankName), accountNumber(accountNumber), ifscCode(ifscCode) {}

	void pay(double amount) const override {
		cout << "Processing net banking payment of amount: " << amount << endl;
		// Simulate net banking payment processing logic here
		cout << "Net banking payment successful." << endl;
	}
};