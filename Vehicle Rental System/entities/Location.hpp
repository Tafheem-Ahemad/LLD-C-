#pragma once
#include <bits/stdc++.h>
using namespace std;

class Location{
public:
	const string city;
	const string address;
	const string state;
	const string PINcode;
	Location(const string &city, const string &address, const string &state, const string &PINcode)
		: city(city), address(address), state(state), PINcode(PINcode) {};
};
