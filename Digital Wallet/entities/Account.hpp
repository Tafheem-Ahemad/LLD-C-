#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Transaction.hpp"
#include "Currency.hpp"
#include "Observer.hpp"

class Account{
private:
	const string accountNumber;
	const User* user;
	const Currency currency;
	double balance;
	map<string ,Transaction*>transactions;
	vector<Observer*>observers;
	map<string,Card*>cards;
public:

	Account(const string &accountNumber, 
	        const User* user, 
	        const Currency currency);
	~Account();

	void addTransaction(Transaction* transaction);
	void deposite(double money);
	void withdraw(double money);

	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);

	void addCard(Card* card);
	void removeCard(Card* card);

	// getter setter
	User* getUser() const;
	double getBalance() const;
	vector<Transaction*> getTransaction() const;
	Transaction* getTransaction(const string &id) const;
	vector<Observer*> getObservers() const;
	Currency getCurrency() const;
	string getAccountNumber() const;
	vector<Card*> getCards() const;

};
