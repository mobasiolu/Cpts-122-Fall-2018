#include "pa4.h"




//default constructor with no parameters
dietPlan:: dietPlan()
{
	//std::cout << "Default Constructor called" << std::endl;
	goalCal = 0;
	planName = "\0";
	planDate = "\0";
}

//default constructor with arguments
dietPlan:: dietPlan(int _goalCal, std::string _planName, std::string _planDate)
{
	goalCal = _goalCal;
	planName = _planName;
	planDate = _planDate;

}

//copy constructor
dietPlan:: dietPlan(const dietPlan &other)
{
	//std::cout << "Copy Constructor called" << std::endl;
	goalCal = other.goalCal;
	planName = other.planName;
	planDate = other.planDate;

}


//destructor
dietPlan:: ~dietPlan()
{
	//std::cout << "Destructor called" << std::endl;
}

//member function
//setters and getters 
int dietPlan::getCal() const
{
	return goalCal;
}

 std::string dietPlan::getplanName() const
{
	return planName;
}

 std::string dietPlan:: getplanDate() const
{
	return planDate;
}

void dietPlan::setgoalCal(int _goalCal)
{
	goalCal = _goalCal;
}

void dietPlan::setplanName(std::string _planName)
{
	planName = _planName;

}

void dietPlan::setplanDate(std::string _setplanDate)
{
	planDate = _setplanDate;
}

void dietPlan::editGoalCal() //editgoalcal is mostly used as a helper function later in the program
{
	int cal = 0; 

	std::cout << "Enter a new value for goal calories " << std::endl;// prompts the user for a new goal calories value
	std::cin >> cal;
	std::cout << "\n";
	goalCal = cal;//sets that value to the goal calories

	std::cout << goalCal << std::endl << planName << std::endl << planDate << std::endl;// print the results
	std::cout << "\n";
}


//default constructor
exercisePlan:: exercisePlan()
{

}

//copy constructor
exercisePlan:: exercisePlan(const exercisePlan &other)
{

}

//destructor
exercisePlan:: ~exercisePlan()
{
	//std::cout << "Destructor called" << std::endl;
}

//setters and getters 
int exercisePlan::getSteps() const
{
	return goalSteps;
}

std::string exercisePlan:: getplanName() const
{
	return planName;
}

std::string exercisePlan::getplanDate() const
{
	return planDate;
}

void exercisePlan::setgoalSteps(int _goalSteps)
{
	goalSteps = _goalSteps;
}

void exercisePlan::setplanName(std::string _planName)
{
	planName = _planName;

}

void exercisePlan:: setplanDate(std::string _setplanDate)
{
	planDate = _setplanDate;
}

void exercisePlan::editGoalSteps()
{
	int steps = 0;

	std::cout << "Enter a new value for goal steps" << std::endl;
	std::cin >> steps;
	std::cout<<"\n";
	goalSteps = steps;
	std::cout << "\n";
}

std::ostream &operator << (std::ostream &out, const dietPlan &plan) //overloaded ostream for DietPlan
{
	out << plan.getplanName() << std::endl; //stream insertion of a diet plan, uses the getter function to retrieve its values for each respective data members
	out << plan.getCal() << std::endl;
	out << plan.getplanDate() << std::endl;


	return out;
}

std::ostream &operator << (std::ostream &out, const exercisePlan &plan) //overloaded ostream for Exercise Plan
{	
	out << plan.getplanName() << std::endl;
	out << plan.getSteps() << std::endl;
	out << plan.getplanDate() << std::endl;

	return out;
}

std::istream &operator >> (std::istream &in, dietPlan &plan) //overloaded istream for DietPlan
{
	//makes local declarations of the data members contained in a dietplan
	int tGoalCal = 0; 
	std::string tPlanName = "\0";
	std::string tPlanDate = "\0";

	
	in >> tPlanName; //stream extration of the local data members to the file
	in >> tGoalCal; //
	in >> tPlanDate; //
	

	plan.setplanDate(tPlanDate); //uses the setters to change the values of the data member
	plan.setgoalCal(tGoalCal);
	plan.setplanName(tPlanName);

	return in;

}

std::istream &operator >> (std::istream &in, exercisePlan &plan) //overloaded istream for Exercise Plan
{
	//same thing as the above
	int tGoalSteps = 0;
	std::string tPlanName = "\0";
	std::string tPlanDate = "\0";

	
	in >> tPlanName;
	in >> tGoalSteps;
	in >> tPlanDate;

	plan.setplanDate(tPlanDate);
	plan.setgoalSteps(tGoalSteps);
	plan.setplanName(tPlanName);

	return in;

}



void fitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, dietPlan &plan)
{
	fileStream >> plan; //stream extraction of a diet plan obj using our previously defined overloaded operator
}

void fitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, exercisePlan &plan)
{
	fileStream >> plan; //same as above
}

void fitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream, dietPlan weeklyPlan[])
{
	for (int count = 0; fileStream.good() && count <= 6; count++) //for loop to iterate through the array holding our daily plans in the file and incrementally have them populate the array of size 7
	{
		fileStream >> weeklyPlan[count];

	}
	std::cout << "diet plan loaded" << std::endl;

	fileStream.close(); // closing the file stream
}

void fitnessAppWrapper:: loadWeeklyPlan(std::fstream &fileStream, exercisePlan weeklyPlan[])
{

	for(int count = 0; fileStream.good() && count <= 6; count ++) //for loop to iterate through the array holding our daily plans in the file and incrementally have them populate the array of size 7
	{ 
	 fileStream >> weeklyPlan[count];
	 
	}
	std::cout << "exercise plan loaded" << std::endl;

	fileStream.close();

}

void fitnessAppWrapper::displayDailyPlan(dietPlan plan)
{

	std::cout << plan << std::endl; //cout used to display a singular plan for its respective day
}

void fitnessAppWrapper::displayDailyPlan(exercisePlan plan)
{

	std::cout << plan << std::endl; //cout used to display a singular plan for its respective day
}





void fitnessAppWrapper::displayWeeklyPlan(dietPlan plan[])
{
	
		for (int count = 0; count <= 6; count++)
		{
			std::cout << plan[count] << std::endl; //after calling loadweekly, this function uses a for loop to go through each index in the 7 index array to display the entire weekly plan to the terminal

		}


}

void fitnessAppWrapper:: displayWeeklyPlan(exercisePlan plan[])
{
	for (int count = 0; count <= 6; count++)
	{
		std::cout << plan[count] << std::endl; // same thing as above

	}

}

void fitnessAppWrapper::storeDailyPlan(std:: fstream &fileStream, dietPlan &plan)
{
	fileStream << plan;
}

void fitnessAppWrapper::storeDailyPlan(std::fstream &fileStream, exercisePlan &plan)
{
	fileStream << plan;
}

void fitnessAppWrapper::storeWeeklyPlan(std::fstream &fileStream , dietPlan plan[])
{	
	fileStream.open("dietPlans.txt", std::ios::out); //opening the dietplans file, and using ios::out to allow write operations to a stream since we're storing
	for (int count = 0; count <= 6; count++) //iterating through a for loop to store each contiguous element in the array of 7
	{
		fileStream << plan[count] << std::endl;
	}

	std::cout << "diet plan stored" << std::endl; //lets the user know the plan was stored by printing to the terminal

}

void fitnessAppWrapper::storeWeeklyPlan(std::fstream &fileStream, exercisePlan plan[])
{
	fileStream.open("exercisePlans.txt", std::ios::out); //opening the dietplans file, and using ios::out to allow write operations to a stream since we're storing
	for (int count = 0; count <= 6; count++) //iterating through a for loop to store each contiguous element in the array of 7
	{
		fileStream << plan[count] << std::endl;
	}

	std::cout << "exercise plan stored" << std::endl; //lets the user know the plan was stored by printing to the terminal

}

void fitnessAppWrapper::editWeekly(dietPlan weeklyPlan[]) 
{
	

	for (int count = 0; count <= 6; count++) //iterating through the entire array
	{
		weeklyPlan[count].editGoalCal();//goes through each element in the array and calls editgoal for each respective element
	}
}

void fitnessAppWrapper::editWeekly(exercisePlan weeklyPlan[])
{

	for (int count = 0; count <= 6; count++) //same as above
	{
		weeklyPlan[count].editGoalSteps();
	}

}

void fitnessAppWrapper::Exit(std::fstream &outfileStream1, dietPlan arr1[], std::fstream &outfileStream2, exercisePlan arr2[])
{

	storeWeeklyPlan(outfileStream1, arr1 );// exit basically calls the store function for both the exercise and diet plans
storeWeeklyPlan(outfileStream2, arr2 );//
	system("cls"); //closes the terminal

}

void fitnessAppWrapper::displayMenu()
{
	int choice = 0; //initializes a choice variable for our switch statement
	int exit = 1; //initializes an exit variable for our input validation loop
	std::fstream infile; //infile to read from diet plan
	std::fstream infile2; //infile to read from exercise plan
	std::fstream outfile; // writes to diet plan
	std::fstream outfile2;// writes to exercise plan

	dietPlan dietArr[7];
	exercisePlan exerciseArr[7];

	while (exit) //input validation loop for the display menu
	{
		std::cout << "1. Load weekly diet plan from file" << std::endl;
		std::cout << "2. Load weekly exercise plan from file" << std::endl;
		std::cout << "3. Store weekly diet plan to file" << std::endl;
		std::cout << "4. Store weekly exercise plan to file" << std::endl;
		std::cout << "5. Display weekly diet plan to screen" << std::endl;
		std::cout << "6. Display weekly exercise plan to screen" << std::endl;
		std::cout << "7. Edit daily diet plan" << std::endl;
		std::cout << "8. Edit daily exerc1ise plan" << std::endl;
		std::cout << "9. Exit" << std::endl;
		std::cout << "Enter a choice" << std::endl;
		std::cin >> choice;
		system("cls");

		while ((choice < 1 || choice > 10)) //while loop to reprompt the user if they enter an invalid value
		{
			std::cout << "Enter a valid number" << std::endl;
			std::cin >> choice;
		}

		switch (choice) //switch case statement that calls each function according to the menu
		{
		case 1:
			infile.open("dietPlans.txt"); //opens the stream
			
			loadWeeklyPlan(infile, dietArr); //calls loadweekly function 
			infile.close();//closes the stream
			break;

		case 2:
			infile2.open("exercisePlans.txt");
			
			loadWeeklyPlan(infile2, exerciseArr);
			infile2.close();
			break;

		case 3:
			
			storeWeeklyPlan(outfile, dietArr);
			outfile.close();
			exit = 0;
			break;
		case 4:
		
			storeWeeklyPlan(outfile2, exerciseArr);
			outfile2.close();
			break;
		case 5:
			displayWeeklyPlan(dietArr);
			break;
		case 6:
			displayWeeklyPlan(exerciseArr);
			break;
		case 7:
			editWeekly(dietArr);
			break;
		case 8:
			editWeekly(exerciseArr);
			break;
		case 9:
			Exit(outfile,dietArr,outfile2,exerciseArr);
			exit = 0;
			break;
		default:
			break;
		}

	}

}

void fitnessAppWrapper::runApp(void)
{
	displayMenu();//calls display menu, which is the meat of our function

}