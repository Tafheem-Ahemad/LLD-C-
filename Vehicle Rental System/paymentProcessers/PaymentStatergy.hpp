#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Reservation.hpp"
#include "PaymentStatergy.hpp"
#include "CardPayment.hpp"
#include "UPIpayment.hpp"
#include "NetBankingPayment.hpp"

class PaymentStatergy{
public:
	virtual void pay(double amount) const = 0;
	virtual ~PaymentStatergy() = default;
};
