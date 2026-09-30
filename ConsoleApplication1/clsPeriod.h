#pragma once
#include<iostream>
#include"clsDate.h"
class clsPeriod
{
private:
	clsDate _StartDate;
	clsDate _EndDate;
public:
	clsPeriod(clsDate startDate,clsDate endDate) {
		this->_StartDate= startDate;
		this->_EndDate= endDate;
	 }
};

