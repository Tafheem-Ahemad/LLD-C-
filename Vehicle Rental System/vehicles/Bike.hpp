#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "VehicleType.hpp"
#include "VehicleStatus.hpp"
#include "Reservation.hpp"

class Bike : public Vehicle{
private:
	VehicleType vehicleType;
public:
	Bike(const string& name, const string& registrationNumber, double rentalPricePerDay);

	VehicleType getVehicleType() const override;
};
