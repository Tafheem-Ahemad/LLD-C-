#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "VehicleType.hpp"
#include "Vehicle.hpp"
#include "User.hpp"
#include "RentalStore.hpp"
#include "Reservation.hpp"

class RentCalculateStatergy {
public:
	virtual double calculateRent(const Vehicle& vehicle, const User& user, const Reservation& reservation) = 0;
	virtual ~RenCalculateStatergy() = default;t
};