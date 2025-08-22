#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Currency.hpp"

class Observer{
public:
	virtual getMoney(const User* user,const Currency currency,const double amount) = 0;
};
