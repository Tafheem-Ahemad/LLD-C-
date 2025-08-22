#include "User.hpp"

User::User(const string &id, const string &name, const string &email)
	: id(id), name(name), email(email) {
}

User::~User() {
	for (auto& pair : this->accounts) {
		delete pair.second;
	}
	for (auto& pair : this->cards) {
		delete pair.second;
	}
	for (auto& pair : this->transactions) {
		delete pair.second;
	}
}

void User::addAccount(Account* account) {
	this->accounts.push_back(account);
}
void User::removeAccount(Account* account) {
	this->accounts.erase(remove(this->accounts.begin(), this->accounts.end(), account), this->accounts.end());
}

void User::addCard(Card* card) {
	if (this->cards.count(card->getNumber())) {
		throw invalid_argument("Card with same number already exists");
	}
	this->cards[card->getNumber()] = card;
}

void User::removeCard(Card* card) {
	if (!this->cards.count(card->getNumber())) {
		throw invalid_argument("Card with given number does not exist");
	}
	this->cards.erase(card->getNumber());
}

void User::addTransaction(Transaction* transaction) {
	if (this->transactions.count(transaction->getId())) {
		throw invalid_argument("Transaction with same id already exists");
	}
	this->transactions[transaction->getId()] = transaction;
}

string User::getId() const {
	return this->id;
}

string User::getName() const {
	return this->name;
}

string User::getEmail() const {
	return this->email;
}

vector<Account*> User::getAccounts() const {
	vector<Account*> result;
	for (const auto& pair : this->accounts) {
		result.push_back(pair.second);
	}
}

Account* User::getAccount(const string &accountNumber) const {
	if (!this->accounts.count(accountNumber)) {
		throw invalid_argument("Account with given number does not exist");
	}
	return this->accounts.at(accountNumber);
}

Card* User::getCard(const string &cardNumber) const {
	if (!this->cards.count(cardNumber)) {
		throw invalid_argument("Card with given number does not exist");
	}
	return this->cards.at(cardNumber);
}


Transaction* User::getTransaction(const string &id) const {
	if (!this->transactions.count(id)) {
		throw invalid_argument("Transaction with given id does not exist");
	}
	return this->transactions.at(id);
}
vector<Transaction*> User::getTransactions() const {
	vector<Transaction*> result;
	for (const auto& pair : this->transactions) {
		result.push_back(pair.second);
	}
	return result;
}
vector<Card*> User::getCards() const {
	vector<Card*> result;
	for (const auto& pair : this->cards) {
		result.push_back(pair.second);
	}
	return result;
}
Card* User::getDefaultCard() const {
	return this->defaultCard;
}
void User::setDefaultCard(Card* card) {
	if (!this->cards.count(card->getNumber())) {
		throw invalid_argument("Card with given number does not exist");
	}
	this->defaultCard = card;
}
