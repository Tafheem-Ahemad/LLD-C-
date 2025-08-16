#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Vehicle.hpp"
#include "RentalStore.hpp"
#include "User.hpp"
#include "RegistrationSatus.hpp"

class Reservation{
private:
	const string &id;
	string name;
	const User* user;
	RentalStore* pickUpStore;
	RentalStore* returnStore;
	RegistrationStatus curStatus;
	year_month_day startDate;
	year_month_day endDate;
	Vehicle* vehicle;
	double cost;
public:
	Regervation(const string &id, const string &name, User* user, RentalStore* pickUpStore, RentalStore* returnStore, 
				const Date &startDate, const Date &endDate, Vehicle* vehicle);

	void confirmReservation();
	void startReservation();
	void cancelReservation();
	User* getUser() const;
	User* startDate() const;
	User* endDate() const;
	RegistrationStatus getCurStartus() const;
	Vehicle* getVehicle() const;
	RentalStore* getPickUpStore() const;
	RentalStore* getReturnStore() const;
	void setReturnStore(RentalStore* returnStore);
	void setCost(double cost);
	double getCost() const;
	string getId() const;
	string getName() const;
};
