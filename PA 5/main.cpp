#include <iostream>
#include "Test.h"
//Name: Maxmimillian Obasiolu
//PA 5, CPTS 122, TA: Ryan N
//Collaborators: Kadir Nour, Connor D, Oumar Sidibe, Matthias McFarlane, Collin Krummer 


int main(void)
{
	int x = 0;
	std::cout << "enter 1 to run the test functions. enter 2 to run the actual program" << std::endl;
	std::cin >> x;


	if (x == 1)
	{
		std::string y;
		testEnqueue();
		testEnqueue2();
		testDequeue();
		testDequeue2();

		std::cout << "the first four test functions have been called. the fifth will now execute after you click a key" << std::endl;

		system("Pause");

		testSimulation();
	}
	else if (x == 2)
	{

		Queue normalLine, expressLine; // our two lines 
		int newnormalEnter, newexpressEnter, totalsimulationTime = 0, normal_id_num = 1, express_id_num = 1, normal_service_time = 0, express_service_time = 0; // 
		Data *person = new Data;
		newnormalEnter = person->gennormalTime();
		newexpressEnter = person->genexpressTime();

		do
		{

			if (newnormalEnter == 0) // this if statement is true if a new customer is entering the normal line
			{
				//newexpressEnter = person->genexpressTime();
				std::cout << "Someone has entered the normal checkout line!!" << std::endl;
				std::cout << "Total simulation time:" << totalsimulationTime << std::endl;


				person->setcustomerNumber(normal_id_num); // sets the person's checkout ID to a corresponding number, starts at 1 and goes in ascending order
				person->setserviceTime(person->gennormalTime()); // sets the service time of the customer 
				person->settotalTime(totalsimulationTime); //the total simulation time is equal to the total time a person has been waiting

				normalLine.enqueue(person); //entered a person into the 
				std::cout << "Customer" << normalLine.getmpHead()->getpData()->getcustomerNumber() << std::endl;
				std::cout << std::endl;

				normal_id_num++; //increments an assigned number for the next customer
				newnormalEnter = person->gennormalTime(); //assigned random time for next customer to enter the line
			}

			if (normalLine.isEmpty() != 1) //isEmtpy returns a 1 if the queue is empty. 
			{
				if (normalLine.getmpHead()->getpData()->getserviceTime() == 0) // returns the service time because if the service time of a customer is 0, they're free to go
				{
					normal_service_time = totalsimulationTime - (normalLine.getmpHead()->getpData()->getserviceTime()); //calculates a person's total time in line
					std::cout << "Someone has exited the normal checkout line!!" << std::endl;
					std::cout << "Total time they were in line:" << normal_service_time << std::endl;
					std::cout << "Customer " << (normalLine.getmpHead()->getpData()->getcustomerNumber()) << std::endl;
					std::cout << std::endl;

					normalLine.dequeue();//removes the customer from the queue after we've taken their information 

				}
			}

			//express queue

			if (newexpressEnter == 0) // this if statement is true if a new customer is entering the normal line
			{
				//newexpressEnter = person->genexpressTime();
				std::cout << "Someone has entered the express checkout line!!" << std::endl;
				std::cout << "Total simulation time:" << totalsimulationTime << std::endl;


				person->setcustomerNumber(express_id_num); // sets the person's checkout ID to a corresponding number, starts at 1 and goes in ascending order
				person->setserviceTime(person->genexpressTime()); // sets the service time of the customer 
				person->settotalTime(totalsimulationTime); //the total simulation time is equal to the total time a person has been waiting

				expressLine.enqueue(person); //entered a person into the 
				std::cout << "Customer" << expressLine.getmpHead()->getpData()->getcustomerNumber() << std::endl;
				std::cout << std::endl;

				express_id_num++; //increments an assigned number for the next customer
				newexpressEnter = person->genexpressTime(); //assigned random time for next customer to enter the line
			}

			if (expressLine.isEmpty() != 1) //isEmtpy returns a 1 if the queue is empty. 
			{
				if (expressLine.getmpHead()->getpData()->getserviceTime() == 0) // returns the service time because if the service time of a customer is 0, they're free to go
				{
					express_service_time = totalsimulationTime - (expressLine.getmpHead()->getpData()->getserviceTime()); //calculates a person's total time in line
					std::cout << " Someone has exited the express checkout line!!" << std::endl;
					std::cout << "Total time they were in line: " << express_service_time << " minutes" << std::endl;
					std::cout << "Customer " << (expressLine.getmpHead()->getpData()->getcustomerNumber()) << std::endl;
					std::cout << std::endl;

					expressLine.dequeue();//removes the customer from the queue after we've taken their information 

				}
			}

			totalsimulationTime++;
			newnormalEnter--;
			newexpressEnter--;

			if (normalLine.isEmpty() != 1) //checks to see if the queue is empty
			{
				normalLine.getmpHead()->getpData()->decrementServiceTime(); // if the queue is not empty, then the service time of a customer is decremented
			}
			if (expressLine.isEmpty() != 1) //checks to see if the queue is empty
			{
				expressLine.getmpHead()->getpData()->decrementServiceTime(); // if the queue is not empty, then the service time of a customer is decremented
			}


			if ((totalsimulationTime % 10) == 0) // whenever the total simulation is divisible by 10 with no remainder
			{
				normalLine.printQueue();
				expressLine.printQueue();
			}

		} while (totalsimulationTime != 1440);

	}
}