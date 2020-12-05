#include <iostream>
#include <string>
#include <fstream>

//using namespace std;

class dietPlan
{
//Access Specifier 
public:

	

	
	//member functions below

	//default constructor with no parameters
	dietPlan();

	//default constructor with arguments
	dietPlan(int _goalCal, std::string _planName, std::string _planDate);

	//copy constructor
	dietPlan(const dietPlan &other);
	
	//destructor
	~dietPlan();
	

	//setters and getters 
	int getCal() const;
	

	std::string getplanName() const;
	
	std::string getplanDate() const;
	

	void setgoalCal(int _goalCal);
	

	void setplanName(std::string _planName);

	void setplanDate(std::string _setplanDate);
	

	void editGoalCal();


private:
	int goalCal;
	std::string planName;
	std::string planDate;

};

std::istream &operator >> (std::istream &in, dietPlan &plan);




class exercisePlan
{
//Access Specifier 
public:

	
	//member functions below

	//default constructor
	exercisePlan();
	
	//copy constructor
	exercisePlan(const exercisePlan &other);
	

	//destructor
	~exercisePlan();

	//setters and getters 
	int getSteps() const;
	

	std::string getplanName() const;
	

	std::string getplanDate() const;
	

	void setgoalSteps(int _goalSteps);
	

	void setplanName(std::string _planName);

	void setplanDate(std::string _setplanDate);
	
	void editGoalSteps();
	

private:

	//Data Members
	int goalSteps;
	std::string planName;
	std::string planDate;




};





class fitnessAppWrapper
{
public: 
	//default contructor
	fitnessAppWrapper()
	{

	}

	//destructor
	~fitnessAppWrapper()
	{

	}



	//member functions 

	void runApp(void);
	

	void loadDailyPlan(std::fstream &fileStream, dietPlan &plan);
	

	void loadDailyPlan(std::fstream &fileStream, exercisePlan &plan);
	

	void loadWeeklyPlan(std::fstream &fileStream, dietPlan weeklyPlan[]);
	void loadWeeklyPlan(std::fstream &fileStream, exercisePlan weeklyPlan[]);

	void displayDailyPlan(dietPlan plan);
	void displayDailyPlan(exercisePlan plan);

	void displayWeeklyPlan(dietPlan plan[]);
	void displayWeeklyPlan(exercisePlan plan[]);
	
	void storeDailyPlan(std::fstream &outfile,  dietPlan &plan);
	void storeDailyPlan(std::fstream &outfile,  exercisePlan &plan);

	void storeWeeklyPlan(std::fstream &outfile, dietPlan plan[]);
	void storeWeeklyPlan(std::fstream &outfile, exercisePlan plan[]);
	
	void displayMenu();

	void editWeekly(dietPlan weeklyPlan[]);
	void editWeekly(exercisePlan weeklyPlan[]);
	void Exit(std::fstream &outfileStream1, dietPlan arr1[], std::fstream &outfileStream2, exercisePlan arr2[]);

private:

	//dietPlan dPlan[7];
	//exercisePlan ePlan[7];
	std::fstream infileDiet;
	std::fstream infileExercise;
	std::fstream outfileDiet;
	std::fstream outfileExercise;

};