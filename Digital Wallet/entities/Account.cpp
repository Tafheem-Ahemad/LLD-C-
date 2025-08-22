#include "Account.hpp"


Account::Account(const string &accountNumber, 
				 const User* user, 
				 const Currency currency)
	: accountNumber(accountNumber), user(user), currency(currency), balance(0.0) {
}

~Account Account() {
	// Clean up dynamically allocated Transactions
	for (auto& pair : transactions) {
		delete pair.second;
	}
	transactions.clear();

	// Note: Observers and Cards are not deleted here as they may be managed elsewhere
}

void Account::addTransaction(Transaction* transaction) {
	if(transactions.count(transaction->getId())) {
		throw invalid_argument("Transaction with same id already exists");
	}
	this->transactions[transaction->getId()] = transaction;
}

void Account::deposite(double money) {
	this->balance += money;
	// notify observers
	for (auto observer : this->observers) {
		observer->getMoney(this->user, this->currency, money);
	}
}

void Account::withdraw(double money) {
	if (this->balance < money) {
		throw invalid_argument("Insufficient balance");
	}
	this->balance -= money;
	// notify observers
	for (auto observer : this->observers) {
		observer->getMoney(this->user, this->currency, -money);
	}
}

void Account::addObserver(Observer* observer) {
	this->observers.push_back(observer);
}

void Account::removeObserver(Observer* observer) {
	this->observers.erase(remove(this->observers.begin(), this->observers.end(), observer), this->observers.end());
}

void Account::addCard(Card* card) {
	if (this->cards.count(card->getNumber())) {
		throw invalid_argument("Card with same number already exists");
	}
	this->cards[card->getNumber()] = card;
}

void Account::removeCard(Card* card) {
	if (!this->cards.count(card->getNumber())) {
		throw invalid_argument("Card with given number does not exist");
	}
	this->cards.erase(card->getNumber());
}

User* Account::getUser() const {
	return const_cast<User*>(this->user);
}

double Account::getBalance() const {
	return this->balance;
}

vector<Transaction*> Account::getTransaction() const {
	vector<Transaction*> result;
	for (const auto& pair : this->transactions) {
		result.push_back(pair.second);
	}
	return result;
}

Transaction* Account::getTransaction(const string &id) const {
	if (!this->transactions.count(id)) {
		throw invalid_argument("Transaction with given id does not exist");
	}
	return this->transactions.at(id);
}

vector<Observer*> Account::getObservers() const {
	return this->observers;
}

Currency Account::getCurrency() const {
	return this->currency;
}

string Account::getAccountNumber() const {
	return this->accountNumber;
}

vector<Card*> Account::getCards() const {
	vector<Card*> result;
	for (const auto& pair : this->cards) {
		result.push_back(pair.second);
	}
	return result;
}
