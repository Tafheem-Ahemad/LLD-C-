#include "Transaction.hpp"

Transaction::Transaction(const string &id, 
						 const Account* sourceAccount, 
						 const Account* destinationAccount, 
						 const Currency currency, 
						 double money)
	: id(id), sourceAccount(sourceAccount), destinationAccount(destinationAccount), currency(currency), money(money), timeStamp(time(0)) {
}


string Transaction::getId() const {
	return this->id;
}

const Account* Transaction::getSourceAccount() const {
	return this->sourceAccount;
}

const Account* Transaction::getDestinationAccount() const {
	return this->destinationAccount;
}

Currency Transaction::getCurrency() const {
	return this->currency;
}
double Transaction::getMoney() const {
	return this->money;
}

time_t Transaction::getTimeStamp() const {
	return this->timeStamp;
}
