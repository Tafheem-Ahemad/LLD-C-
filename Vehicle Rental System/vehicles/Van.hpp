#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "VehicleType.hpp"
#include "VehicleStatus.hpp"
#include "Reservation.hpp"

class Van : public Vehicle{
private:
	int seatingCapacity;
	double loadCapacity;
	VehicleType vehicleType;
public:
	Van(const string& name, const string& registrationNumber, int seatingCapacity, double loadCapacity, double rentalPricePerDay);

	int getSeatingCapacity() const;

	double getLoadCapacity() const;

	VehicleType getVehicleType() const override;
};
