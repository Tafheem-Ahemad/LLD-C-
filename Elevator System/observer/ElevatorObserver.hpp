#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Elevator.hpp"

class ElevatorObserver{
public:
	virtual void update(const Elevator* elevator)=0;
	virtual ~ElevatorObserver() = default;
};
