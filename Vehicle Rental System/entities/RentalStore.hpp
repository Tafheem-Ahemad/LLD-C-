#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Location.hpp"
#include "Vehicle.hpp"

class RentalStore{
	map<string,Vehicle*>vehicles;
	Location location;
	const string id;
	string name;
public:
	RentalStore(const string &id, const string &name, const Location &location);
	~RentalStore();

	void addVehicle(Vehicle* vehicle);
	void removeVehicle(Vehicle* vehicle);
	vector<Vehicle*> getAvailable Vehicles(date,date);
	Vehicle* getVehicle(const string &RegistrationNumber) const;
	bool isAvailable(Vehicle* vehicle,date,date);
	Location getLocation() const;
};
