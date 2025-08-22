#include "DigitalWalletService.hpp"
#include "CardFactoty.hpp"

DigitalWalletService::DigitalWalletService(/* args */) {
}
DigitalWalletService& DigitalWalletService::getIntance() {
	static DigitalWalletService instance;
	return instance;
}

User* DigitalWalletService::createUser(const string &name, const string &email) {
	string id = "U" + to_string(users.size() + 1);
	User* user = new User(id, name, email);
	users[id] = user;
	return user;
}

Account* DigitalWalletService::createAccount(User* user, const Currency currency) {
	string accountNumber = "A" + to_string(accounts.size() + 1);
	Account* account = new Account(accountNumber, user, currency);
	accounts[accountNumber] = account;
	user->addAccount(account);
	return account;
}

Card* DigitalWalletService::createCard(User* user, Account* account, const string &type, const string &pin) {
	Card* card = CardFactoty::getIntance().createCard(type, account, pin);
	if(card == nullptr) {
		throw invalid_argument("Invalid card type");
	}
	cards[card->getNumber()] = card;
	user->addCard(card);
	account->addCard(card);
	return card;
}

Transaction* DigitalWalletService::createTransaction(Account* sourceAccount, Account* destinationAccount, const Currency currency, double money) {
	string id = "T" + to_string(transactions.size() + 1);
	Transaction* transaction = new Transaction(id, sourceAccount, destinationAccount, currency, money);
	transactions[id] = transaction;
	sourceAccount->addTransaction(transaction);
	destinationAccount->addTransaction(transaction);
	sourceAccount->getUser()->addTransaction(transaction);
	destinationAccount->getUser()->addTransaction(transaction);
	return transaction;
}

void DigitalWalletService::addMoney(Account* account, double money) {
	account->deposite(money);
}
void DigitalWalletService::pay(User* user, Account* sourceAccount, Account* destinationAccount, const Currency currency, double money) {
	if (sourceAccount->getUser()->getId() != user->getId()) {
		throw invalid_argument("Source account does not belong to user");
	}
	if (sourceAccount->getBalance() < money) {
		throw invalid_argument("Insufficient balance in source account");
	}
	sourceAccount->withdraw(money);
	destinationAccount->deposite(money);
	this->createTransaction(sourceAccount, destinationAccount, currency, money);
}


void DigitalWalletService::setDefaultCard(User* user, Card* card) {
	if (card->getAccount()->getUser()->getId() != user->getId()) {
		throw invalid_argument("Card does not belong to user");
	}
	user->setDefaultCard(card);
}

void DigitalWalletService::changeCardPIN(Card* card, const string &oldPIN, const string &newPIN) {
	if (card->getPIN() != oldPIN) {
		throw invalid_argument("Old PIN does not match");
	}
	card->setPIN(newPIN);
}

User* DigitalWalletService::getUser(const string &id) const {
	if (!this->users.count(id)) {
		throw invalid_argument("User with given id does not exist");
	}
	return this->users.at(id);
}

Account* DigitalWalletService::getAccount(const string &accountNumber) const {
	if (!this->accounts.count(accountNumber)) {
		throw invalid_argument("Account with given number does not exist");
	}
	return this->accounts.at(accountNumber);
}

Card* DigitalWalletService::getCard(const string &cardNumber) const {
	if (!this->cards.count(cardNumber)) {
		throw invalid_argument("Card with given number does not exist");
	}
	return this->cards.at(cardNumber);
}

Transaction* DigitalWalletService::getTransaction(const string &id) const {
	if (!this->transactions.count(id)) {
		throw invalid_argument("Transaction with given id does not exist");
	}
	return this->transactions.at(id);
}

vector<User*> DigitalWalletService::getAllUsers() const {
	vector<User*> result;
	for (const auto& pair : this->users) {
		result.push_back(pair.second);
	}
	return result;
}

vector<Account*> DigitalWalletService::getAllAccounts() const {
	vector<Account*> result;
	for (const auto& pair : this->accounts) {
		result.push_back(pair.second);
	}
	return result;
}

vector<Card*> DigitalWalletService::getAllCards() const {
	vector<Card*> result;
	for (const auto& pair : this->cards) {
		result.push_back(pair.second);
	}
	return result;
}

vector<Transaction*> DigitalWalletService::getAllTransactions() const {
	vector<Transaction*> result;
	for (const auto& pair : this->transactions) {
		result.push_back(pair.second);
	}
	return result;
}

DigitalWalletService::~DigitalWalletService() {
	for (auto& pair : this->users) {
		delete pair.second;
	}
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