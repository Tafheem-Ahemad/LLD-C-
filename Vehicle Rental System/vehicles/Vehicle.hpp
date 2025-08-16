#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "VehicleType.hpp"
#include "VehicleStatus.hpp"
#include "Regervation.hpp"

class Vehicle{
	const string RegistrationNumber;
	string name;
	atomic<bool> available;
	double rentalPriceperHour;
	VehicleStatus status;
public:
	Vehicle(const string& name,const string &RegistrationNumber,const double rentalPricePerDay);

	string getRegistrationNumber() const;
	string getName() const;
	VehicleStatus getStatus() const;
	atomic<bool> isAvailable() const;
	double getRentalPricePerDay() const;
	
	void setStatus(VehicleStatus status);
	void setAvailable(bool available);
	void setRentalPricePerDay(double price);
	
	virtual VehicleType getVehicleType const = 0;
};
