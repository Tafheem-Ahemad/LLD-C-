#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Account.hpp"
#include "Card.hpp"
#include "Transaction.hpp"

class User{
private:
	const string id;
	string name;
	const string email;
	map<string,Account*>accounts;
	map<string,Card*>cards;
	map<string,Transaction*>transactions;
	Card* defaultCard;
public:
	User(const string &id, const string &name, const string &email);
	~User();

	void addAccount(Account* account);
	void removeAccount(Account* account);

	void addCard(Card* card);
	void removeCard(Card* card);

	void addTransaction(Transaction* transaction);

	// getter && setter
	string getId() const;
	string getName() const;
	string getEmail() const;
	vector<Account*> getAccounts() const;
	Account* getAccount(const string &accountNumber) const;
	Card* getCard(const string &cardNumber) const;
	Transaction* getTransaction(const string &id) const;
	vector<Transaction*> getTransactions() const;
	vector<Card*> getCards() const;
	Card* getDefaultCard() const;
	void setDefaultCard(Card* card);
};