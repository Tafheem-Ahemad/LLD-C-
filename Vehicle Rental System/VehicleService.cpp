#include "VehicleSevice.hpp"

#include "VehicleFactory.hpp"
#include "User.hpp"
#include "RentalStore.hpp"
#include "Reservation.hpp"
#include "PaymentStatergy.hpp"
#include "PaymentProcesser.hpp"
#include "RentCalculateStatergy.hpp"

VehicleSevice::VehicleSevice() : paymentStatergy(nullptr), rentCalculateStatergy(nullptr) {
	paymentProcesser = new PaymentProcesser();
}

VehicleSevice::~VehicleSevice() {
	for (auto &pair : users) {
		delete pair.second; // Assuming ownership of users
	}
	users.clear();

	for (auto &pair : rentalStores) {
		delete pair.second; // Assuming ownership of rental stores
	}
	rentalStores.clear();

	for (auto &pair : reservations) {
		delete pair.second; // Assuming ownership of reservations
	}
	reservations.clear();
}

VehicleSevice& VehicleSevice::getIntance() const {
	static VehicleSevice instance;
	return instance;
}

void VehicleSevice::addUser(const string &id, const string &name) {
	if (users.find(id) == users.end()) {
		users[id] = new User(id, name);
	}
}
Vehicle* VehicleSevice::newVehicle(const string& type, const string& name, const string& registrationNumber, double rentalPricePerDay) {
	Vehicle* vehicle = VehicleFactory::createVehicle(type, name, registrationNumber, rentalPricePerDay);
	return vehicle;
}

void VehicleSevice::addRentalStore(const string &id, const string &name, const Location &location) {
	if (rentalStores.find(id) == rentalStores.end()) {
		rentalStores[id] = new RentalStore(id, name, location);
	}
}

bool VehicleSevice::doPayment(double amount) const {
	if (paymentStatergy) {
		return paymentProcesser->processPayment(*paymentStatergy, amount);
	}
	return false;
}

void VehicleSevice::setPaymentStatergy(PaymentStatergy* paymentStatergy) {
	this->paymentStatergy = paymentStatergy;
}

PaymentStatergy* VehicleSevice::getPaymentStatergy(PaymentStatergy* paymentStatergy) {
	return this->paymentStatergy;
}

void VehicleSevice::setRentCalculateStatergy(RentCalculateStatergy* rentCalculateStatergy) {
	this->rentCalculateStatergy = rentCalculateStatergy;
}

RentCalculateStatergy* VehicleSevice::getRentCalculateStatergy() const {
	return rentCalculateStatergy;
}

void VehicleSevice::addVehicleToStore(const string &storeId, Vehicle* vehicle) {
	auto it = rentalStores.find(storeId);
	if (it != rentalStores.end() && vehicle) {
		it->second->addVehicle(vehicle);
	}
}

void VehicleSevice::removeVehicleFromStore(const string &storeId, Vehicle* vehicle) {
	auto it = rentalStores.find(storeId);
	if (it != rentalStores.end() && vehicle) {
		it->second->removeVehicle(vehicle);
	}
}

RentalStore* VehicleSevice::getRentalStore(const string &storeId) const {
	auto it = rentalStores.find(storeId);
	if (it != rentalStores.end()) {
		return it->second;
	}
	throw runtime_error("Rental store not found: " + storeId);
}

User* VehicleSevice::getUser(const string &userId) const {
	auto it = users.find(userId);
	if (it != users.end()) {
		return it->second;
	}
	throw runtime_error("User not found: " + userId);
}

Reservation* VehicleSevice::getReservation(const string &reservationId) const {
	auto it = reservations.find(reservationId);
	if (it != reservations.end()) {
		return it->second;
	}
	throw runtime_error("Reservation not found: " + reservationId);
}

void VehicleSevice::addReservation(const string &userId, const string &storeId, const year_month_day &startDate, 
									const year_month_day &endDate, Vehicle* vehicle) {
	User* user = getUser(userId);
	RentalStore* store = getRentalStore(storeId);
	if (user && store && vehicle) {
		string reservationId = newReservationId();
		Reservation* reservation = new Reservation(reservationId, "Reservation for " + user->getId(), user, store, store, startDate, endDate, vehicle);
		reservations[reservationId] = reservation;
		user->addReservation(reservation);
		store->addVehicle(vehicle);
	}
}

void VehicleSevice::confirmReservation(const string &reservationId) {
	Reservation* reservation = getReservation(reservationId);
	if (reservation) {
		reservation->confirmReservation();
	}
}

void VehicleSevice::startReservation(const string &reservationId) {
	Reservation* reservation = getReservation(reservationId);
	if (reservation) {
		reservation->startReservation();
	}
}
void VehicleSevice::cancelReservation(const string &reservationId) {
	Reservation* reservation = getReservation(reservationId);
	if (reservation) {
		reservation->cancelReservation();
	}
}
void VehicleSevice::setReturnStore(const string &reservationId, const string &returnStoreId) {
	Reservation* reservation = getReservation(reservationId);
	if (reservation) {
		RentalStore* returnStore = getRentalStore(returnStoreId);
		reservation->setReturnStore(returnStore);
	}
}

void VehicleSevice::setCost(const string &reservationId, double cost) {
	Reservation* reservation = getReservation(reservationId);
	if (reservation) {
		reservation->setCost(cost);
	}
}
Reservation* VehicleSevice::getReservation(const string &reservationId) const {
	auto it = reservations.find(reservationId);
	if (it != reservations.end()) {
		return it->second;
	}
	throw runtime_error("Reservation not found: " + reservationId);
}


vector<Vehicle*> VehicleSevice::getAvailableVehicles(const string &storeId, const year_month_day &startDate,
														const year_month_day &endDate) const {
	RentalStore* store = getRentalStore(storeId);
	if (store) {
		return store->getAvailableVehicles(startDate, endDate);
	}
	throw runtime_error("Rental store not found: " + storeId);
}

double VehicleSevice::calculateRent(const string &reservationId) const {
	Reservation* reservation = getReservation(reservationId);
	if (reservation && rentCalculateStatergy) {
		return rentCalculateStatergy->calculateRent(reservation);
	}
	throw runtime_error("Cannot calculate rent for reservation: " + reservationId);
}

void VehicleSevice::removeUser(const string &userId) {
	auto it = users.find(userId);
	if (it != users.end()) {
		delete it->second; // Assuming ownership of user
		users.erase(it);
	}
}

void VehicleSevice::removeRentalStore(const string &storeId) {
	auto it = rentalStores.find(storeId);
	if (it != rentalStores.end()) {
		delete it->second; // Assuming ownership of rental store
		rentalStores.erase(it);
	}
}

string VehicleSevice::getRandomString(int len) const {
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string result;
	result.reserve(len);
	for (int i = 0; i < len; ++i) {
		result += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return result;
}

string VehicleSevice::newUserId() const {
	return "USER_" + getRandomString(8);
}
string VehicleSevice::newStoreId() const {
	return "STORE_" + getRandomString(8);
}
string VehicleSevice::newReservationId() const {
	return "RESERVATION_" + getRandomString(8);
}
