#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>
#include <MMSystem.h>


using namespace std;
using namespace std::this_thread;

int main()
{
	double multiplyer = 1;
    cout << "LETS GO!\n" << "MULTIPLYER: "; 
	cin >> multiplyer;
	ifstream workoutPlan("plan.txt");
	if (!workoutPlan) 
	{
		return EXIT_FAILURE;
	}

	int minutesPerExercise = 0;
	int totalTimeMinutes = 0;
	string name = "";

	workoutPlan >> totalTimeMinutes;
	cout << "This will take " << totalTimeMinutes << " minutes in total" << endl;

	while (workoutPlan >> minutesPerExercise)
	{
		workoutPlan >> name;
		cout << "You should do " << name << " for " << minutesPerExercise*multiplyer << " minutes." << endl;
		system("PAUSE");
		sleep_for(chrono::seconds((int)((minutesPerExercise*multiplyer)*60)));
		PlaySound(TEXT("sound.wma"), NULL, SND_ASYNC);
	}

	cout << "You have compleated the routine!";
	workoutPlan.close();
	system("PAUSE");
	return EXIT_SUCCESS;

}