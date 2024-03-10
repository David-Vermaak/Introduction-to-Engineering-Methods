//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 9/1/2021
// Name: David Vermaak
// Project Description: converts the minutes into years and days
// Inputs: a value of minutes
// Outputs: a value of years and a value of days
//*************************************************************

#include <iostream> //header containing cout and cin
#include <string>

using namespace std; //introduces namespace std

int main ( )
{

int days;			// initalizes the variables we will use to store integer values
double minutes, years;			// initalizes the variables we will use to store decimal values

cout << "Please enter the number of minutes,\n m = ";	//asks for the value in minutes

cin >> minutes;		//gets the users input in minutes

	days = minutes / (60*24);		//calculates the days from minutes
	years = days / 365;				//calculates the years from days
	days = days % 365;				//calculates the remaining days after years 
	

//output
cout << "there are " << years << " years and " << days << " days in " << minutes << " minutes";


return 0;
}

