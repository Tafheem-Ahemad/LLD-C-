#include "User.hpp"
#include "Reservation.hpp"
#include "RentalStore.hpp"
#include "Vehicle.hpp"
#include "RegistrationStatus.hpp"


Reservation::Reservation(const string &id, const string &name, User* user, RentalStore* pickUpStore, 
						 RentalStore* returnStore, const year_month_day &startDate, const year_month_day &endDate, 
						 Vehicle* vehicle)
	: id(id), name(name), user(user), pickUpStore(pickUpStore), returnStore(returnStore), 
	  curStatus(RegistrationStatus::PENDING), startDate(startDate), endDate(endDate), vehicle(vehicle), cost(0.0) {}

void Reservation::confirmReservation(){
	curStatus = RegistrationStatus::CONFIRMED;
}

void Reservation::startReservation(){
	curStatus = RegistrationStatus::IN_PROGRESS;
}

void Reservation::cancelReservation(){
	curStatus = RegistrationStatus::CANCELLED;
}

User* Reservation::getUser() const {
	return user;
}

year_month_day Reservation::getStartDate() const {
	return startDate;
}

year_month_day Reservation::getEndDate() const {
	return endDate;
}

RegistrationStatus Reservation::getCurStatus() const {
	return curStatus;
}

Vehicle* Reservation::getVehicle() const {
	return vehicle;
}

RentalStore* Reservation::getPickUpStore() const {
	return pickUpStore;
}

RentalStore* Reservation::getReturnStore() const {
	return returnStore;
}

void Reservation::setReturnStore(RentalStore* returnStore) {
	this->returnStore = returnStore;
}

void Reservation::setCost(double cost) {
	this->cost = cost;
}

double Reservation::getCost() const {
	return cost;
}
string Reservation::getId() const {
	return id;
}
string Reservation::getName() const {
	return name;
}
