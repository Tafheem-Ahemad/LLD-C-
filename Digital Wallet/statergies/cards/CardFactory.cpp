#include "CardFactoty.hpp"
#include "Visa.hpp"
#include "MasterCard.hpp"
#include "Rupay.hpp"

CardFactoty::CardFactoty(/* args */) {
}
CardFactoty::~CardFactoty() {
}
CardFactoty& CardFactoty::getIntance() {
	static CardFactoty instance;
	return instance;
}

Card* CardFactoty::createCard(string type,Account* account, string pin) {
	if(type == "VISA"){
		return new VISA(account,pin);
	}else if(type == "MasterCard"){
		return new MasterCard(account,pin);
	}else if(type == "Rupay"){
		return new Rupay(account,pin);
	}else{
		throw invalid_argument("Invalid card type");
	}
}