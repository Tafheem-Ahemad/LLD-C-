#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "PaymentStatergy.hpp"

class CardFactoty{
	CardFactoty(/* args */);
	~CardFactoty();

	CardFactoty(const CardFactoty&) = delete;
	CardFactoty& operator=(const CardFactoty&&) = delete;
	CardFactoty(CardFactoty&) = delete;
	CardFactoty& operator=(CardFactoty&&) = delete;
public:

	static CardFactoty& getIntance();
	Card* createCard(string type,Account* account, string pin);
};
