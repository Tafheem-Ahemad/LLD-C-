#include "RentalStore.hpp"

RentalStore::RentalStore(const string &id, const string &name, const Location &location)
	: id(id), name(name), location(location) {}

RentalStore::~RentalStore() {
	for (auto &pair : vehicles) {
		delete pair.second; // Assuming ownership of vehicles
	}
	vehicles.clear();
}

void RentalStore::addVehicle(Vehicle* vehicle) {
	if (vehicle) {
		vehicles[vehicle->getRegistrationNumber()] = vehicle;
	}
}

void RentalStore::removeVehicle(Vehicle* vehicle) {
	if (vehicle) {
		auto it = vehicles.find(vehicle->getRegistrationNumber());
		if (it != vehicles.end()) {
			vehicles.erase(it);
		}
	}
}

bool RentalStore::isAvailable(Vehicle* vehicle, date startDate, date endDate) {
	if (!vehicle || !vehicle->isAvailable()) {
		return false;
	}
	// Additional logic to check availability based on the dates can be added here
	return true;
}

vector<Vehicle*> RentalStore::getAvailableVehicles(date startDate, date endDate) {
	vector<Vehicle*> availableVehicles;
	for (const auto &pair : vehicles) {
		if (isAvailable(pair.second, startDate, endDate)) {
			availableVehicles.push_back(pair.second);
		}
	}
	return availableVehicles;
}

Vehicle* RentalStore::getVehicle(const string &RegistrationNumber) const {
	auto it = vehicles.find(RegistrationNumber);
	if (it != vehicles.end()) {
		return it->second;
	}
	return nullptr;
}

Location RentalStore::getLocation() const {
	return location;
}