#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

class Data

{

public: // Member functions
	Data();
	Data(Data &copy);
	~Data();

		//setters and getters 
	void setcustomerNumber(int customerNum);
	void setserviceTime(int serviceTime);
	void settotalTime( int totalTime);
	
	int getcustomerNumber();
	int getserviceTime();
	int gettotalTime();

	int gennormalTime(); // generates express time
	int genexpressTime(); // generates express time

	void decrementServiceTime(); // decrements the service time of a customer in the queue 

private:

	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1

	int serviceTime;   // Random time; varies between express and normal lanes; units in minutes

	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!

