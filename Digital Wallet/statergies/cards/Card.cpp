#include"Card.hpp"

Card(const string number,const Account* account, const string &pin):number(number),account(account),PIN(pin){
}

string Card::getNumber() const{
	return this->number;
}

Account* Card::getAccount() const{
	return const_cast<Account*>(this->account);
}
string Card::getPIN() const{
	return this->PIN;
}

void Card::setPIN(const string &pin){
	this->PIN = pin;
}
void Card::getUser() const{
	return this->account->getUser();
}