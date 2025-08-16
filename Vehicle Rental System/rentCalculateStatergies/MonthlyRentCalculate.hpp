#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "VehicleType.hpp"
#include "Vehicle.hpp"
#include "User.hpp"
#include "RentalStore.hpp"
#include "Reservation.hpp"

class MonthlyRentCalculateStatergy : public RentCalculateStatergy {
public:
	double calculateRent(const Vehicle& vehicle, const User& user, const Reservation& reservation) override {
		// it also depends on which model and rental store location
		// For simplicity, we will just return a fixed monthly price based on the vehicle's
		double dailyPrice = vehicle.getRentalPricePerDay();
		return dailyPrice * 30;
	}

};