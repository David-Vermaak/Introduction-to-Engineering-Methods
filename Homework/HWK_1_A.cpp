//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 9/1/2021
// Name: David Vermaak
// Project Description: Template
// Inputs: 
// Outputs: 
//*************************************************************

#include <iostream> //header containing cout and cin
#include <string>

using namespace std; //introduces namespace std

int main ( )
{

double x1, x2, y1, y2, slope; // initalizes the variables we will use to store values


cout << "Please enter the first x value,\n x1 = ";	//asks for the first x value

cin >> x1;												//takes the users input and stores it to x1

cout << "Please enter the first y value,\n y1 = ";	//asks for the first y value

cin >> y1;												//takes the users input and stores it to y1

cout << "Please enter the second x value,\n x2 = ";	//asks for the second x value

cin >> x2;												//takes the users input and stores it to x2

cout << "Please enter the second y value,\n y2 = ";	//asks for the second y value

cin >> y2;												//takes the users input and stores it to y2

	slope = (y2 - y1)/(x2 - x1);
	
	cout << "The slope of the line is " << slope;
	
return 0;
}

