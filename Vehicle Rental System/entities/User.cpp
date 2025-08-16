#include "User.hpp"

User::User(const string &id, const string &name) : id(id), name(name) {}

void User::addReservation(Reservation* reservation) {
	reservations.push_back(reservation);
}

void User::removeReservation(Reservation* reservation) {
	auto it = find(reservations.begin(), reservations.end(), reservation);
	if (it != reservations.end()) {
		reservations.erase(it);
	}
}

string User::getId() const {
	return id;
}
