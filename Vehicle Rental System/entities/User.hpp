#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Reservation.hpp"

class User{
private:
	const string id;
	string name;
	vector<Reservation*> reservations;
public:
	User(const string &id, const string &name);
	void addReservation(Reservation* reservation);
	void removeReservation(Reservation* reservation);
	string getId() const;
};