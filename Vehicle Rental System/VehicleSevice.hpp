#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "RentalStore.hpp"
#include "Reservation.hpp"
#include "PaymentStatergy.hpp"
#include "PaymentProcesser.hpp"
#include "RentCalculateStatergy.hpp"
#include "VehicleFactory.hpp"

class VehicleSevice{
private:
	map<string,User*>users;
	map<string,RentalStore*>rentalStores;
	map<string,Reservation*>reservations;

	PaymentStatergy* paymentStatergy;
	RentCalculateStatergy* rentCalculateStatergy;

	PaymentProcesser* paymentProcesser;

	VehicleSevice();
	~VehicleSevice();

	VehicleSevice(const VehicleSevice&) = delete;
	VehicleSevice& operator=(const VehicleSevice&) = delete;
	VehicleSevice(VehicleSevice&&) = delete;
	VehicleSevice& operator=(VehicleSevice&&) = delete;
public:
	static VehicleSevice& getIntance() const;
	void addUser(const string &id, const string &name);
	Vehicle* newVehicle(const string& type, const string& name, const string& registrationNumber, double rentalPricePerDay);
	void addRentalStore(const string &id, const string &name, const Location &location);
	bool doPayment(double amount) const;

	void setPaymentStatergy(PaymentStatergy* paymentStatergy);
	PaymentStatergy* getPaymentStatergy(PaymentStatergy* paymentStatergy);

	void setRentCalculateStatergy(RentCalculateStatergy* rentCalculateStatergy);
	RentCalculateStatergy* getRentCalculateStatergy() const;

	void addVehicleToStore(const string &storeId, Vehicle* vehicle);
	void removeVehicleFromStore(const string &storeId, Vehicle* vehicle);

	RentalStore* getRentalStore(const string &storeId) const;
	User* getUser(const string &userId) const;
	Reservation* getReservation(const string &reservationId) const;

	void addReservation(const string &userId, const string &storeId, const year_month_day &startDate, 
						const year_month_day &endDate, Vehicle* vehicle);

	void confirmReservation(const string &reservationId);
	void startReservation(const string &reservationId);
	void cancelReservation(const string &reservationId);
	void setReturnStore(const string &reservationId, const string &returnStoreId);
	void setCost(const string &reservationId, double cost);
	Reservation* getReservation(const string &reservationId) const;
	vector<Vehicle*> getAvailableVehicles(const string &storeId, const year_month_day &startDate,
										const year_month_day &endDate) const;
	double calculateRent(const string &reservationId) const;
	void removeUser(const string &userId);
	void removeRentalStore(const string &storeId);
	
private:
	string getRandomString(int len) const;
	string newUserId() const;
	string newStoreId() const;
	string newReservationId() const;
};
