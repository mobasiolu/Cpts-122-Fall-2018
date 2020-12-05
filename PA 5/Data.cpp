#include "Data.h"
Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}
 
Data::Data(Data &copy)
{
	this->customerNumber = copy.customerNumber;
	this->serviceTime = copy.serviceTime;
	this->totalTime = copy.serviceTime;
}

Data::~Data()
{
	std::cout << "Data Class Destructutor is being called" << std::endl;


}

void Data::setcustomerNumber(int customerNum)
{
	this->customerNumber = customerNum;
}

void Data::setserviceTime(int serviceTime)
{
	this->serviceTime = serviceTime;

}

void Data::settotalTime(int totalTime)
{
	this->totalTime = totalTime; 
}

int Data::getcustomerNumber()
{
	return customerNumber;
}

int Data::getserviceTime()
{
	return serviceTime;
}

int Data::gettotalTime()
{
	return totalTime;
}

int Data::gennormalTime()
{
	int normTime = 0; // will store a number btwn 3-8 to represent minutes

	normTime = rand() % 5 + 3; // 

	return normTime;
}

int Data::genexpressTime()
{
	int expressTime = 0; // will store a number btwn 1-5 to represent minutes

	expressTime = rand() % 5 + 1; // 

	return expressTime;
}

void Data::decrementServiceTime()
{
	serviceTime--;
}
