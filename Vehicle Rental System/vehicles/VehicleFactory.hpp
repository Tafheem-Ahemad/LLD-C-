#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "VehicleType.hpp"
#include "VehicleStatus.hpp"
#include "Reservation.hpp"
#include "Vehicle.hpp"
#include "Bike.hpp"
#include "Car.hpp"
#include "Van.hpp"

class VehicleFactory {
public:
	static Vehicle*createVehicle(const string& type, const string& name, const string& registrationNumber, double rentalPricePerDay, int seatingCapacity = 0, double loadCapacity = 0.0) {
		if (type == "Car") {
			return make_unique<Car>(name, registrationNumber, loadCapacity, rentalPricePerDay);
		} else if (type == "Van") {
			return make_unique<Van>(name, registrationNumber, seatingCapacity, loadCapacity, rentalPricePerDay);
		} else if (type == "Bike") {
			return make_unique<Bike>(name, registrationNumber, rentalPricePerDay);
		}
		throw invalid_argument("Unknown vehicle type: " + type);
	}
};
