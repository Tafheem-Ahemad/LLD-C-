#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Account.hpp"
#include "Currency.hpp"
#include "Card.hpp"
#include "Transaction.hpp"

class DigitalWalletService{

	DigitalWalletService(const DigitalWalletService&) = delete;
	DigitalWalletService& operator=(const DigitalWalletService&&) = delete;
	DigitalWalletService(DigitalWalletService&) = delete;
	DigitalWalletService& operator=(DigitalWalletService&&) = delete;
	DigitalWalletService(/* args */);

	map<string,User*>users;
	map<string,Account*>accounts;
	map<string,Card*>cards;
	map<string,Transaction*>transactions;

public:
	static DigitalWalletService& getIntance();
	User* createUser(const string &name, const string &email);
	Account* createAccount(User* user, const Currency currency);
	Card* createCard(User* user, Account* account, const string &type, const string &pin);
	Transaction* createTransaction(Account* sourceAccount, Account* destinationAccount, const Currency currency, double money);

	// other methods
	void addMoney(Account* account, double money);
	void pay(User* user, Account* sourceAccount, Account* destinationAccount, const Currency currency, double money);
	void setDefaultCard(User* user, Card* card);
	void changeCardPIN(Card* card, const string &oldPIN, const string &newPIN);

	// getter setter
	User* getUser(const string &id) const;
	Account* getAccount(const string &accountNumber) const;
	Card* getCard(const string &cardNumber) const;
	Transaction* getTransaction(const string &id) const;
	vector<User*> getAllUsers() const;
	vector<Account*> getAllAccounts() const;
	vector<Card*> getAllCards() const;
	vector<Transaction*> getAllTransactions() const;
};

