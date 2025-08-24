#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Observer.hpp"
#include "Ball.hpp"
#include "Match.hpp"

class NotificationObserver : public Observer{
public:
	void update(Match* match,const Ball ball) override;
};

