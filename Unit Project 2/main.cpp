
//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 10/26/2021
// Name: David Vermaak
//Project Description: The main function of Unit Project 2: Unit Conversion 
// Inputs: units, initial and final values, formatting values, etc.
// Outputs: a formatted table
//*************************************************************

#include <iostream> 	 //This header containing cout and cin
#include <math.h>		 //This header allows for the use of more complex mathematical operators
#include <string>		 //This header enables string functions
#include <cctype> 		 //This header contains functions that give Boolean answers for given types of char
#include <iomanip>		 //This header contains functions to better format output
#include <ctype.h>		 //This header contains functions to manipulate chars
#include <conio.h>  	//This header declares getch which pauses until a key is pushed
#include "MyLibrary.h"	 //Personal library header
 
using namespace std; //introduces namespace std


int main ()					//The Main function
{
string  s1, s2, s3, C;			//initializing strings
double f, a, a0, a1, a2, a3, a4;		//initializing doubles

	
do	//do while loop to make the program repeatable
{

// display menu
cout << " Hello, this program outputs a formatted list of unit conversions\n"
	 << " Please enter one of the following options to continue:\n"
	 << " Length \n" << " Mass \n" << " Time \n" << " Angle \n" << " Quit\n\n";
	
	//get user input
	cin >> s1; 
	lowercase(s1);		//calls the function lowercase and then stores it to a string s1

if (s1 == "quit") return 0;	//quit option of the menu

else if (s1 == "length")		//length option of the menu
{
   cout << " You have chosen Length conversion\n" 
	 << " Please choose your initial unit:\n"
	 << " Meters: (m)  Centimeters: (cm)  Feet: (ft) or Inches: (in)\n";
	 cin >> s2;
	 cout << " Please choose your second unit:\n"
	 << " Meters: (m)  Centimeters: (cm)  Feet: (ft) or Inches: (in)\n";
	 cin >> s3;
	 
//All of the following functions are declared in the MyLibrary.h file and defined in the MyLibrary.cpp file
// Both of the Files are in the UnitProject2 folder
// These functions are reused at least four times throughout the program
	 	
C = consolidate (s1, s2, s3);	//calls the function consolidate and stores it to a string 
	 
	 lowercase(C);		//calls the function lowercase and then stores it to a string C
	 
	 f = convFactor(C);		//calls the function convFactor and stores it to the double f
	 	 
	 if (f>0)			//Fail condition if -1.0 is returned from convFactor
	 {
	 	GetData(a0, a1, a2, a3, a4);				//calls the function GetData
	 	printTable(a0, a1, a2, a3, a4, f, s1, s2, s3);		//calls the function printTable
	 }
	  
	 goHome();		//calls the function goHome 
}

else if (s1 == "mass")	//Mass option of the menu
{
   cout << " You have chosen Mass conversion\n" 
	 << " Please choose your initial unit:\n"
	 << " Kilogram: (kg)  Gram: (g)  or Slug: (sl)\n";
	 cin >> s2;	
	 cout << " Please choose your second unit:\n"
	 << " Kilogram: (kg)  Gram: (g)  or Slug: (sl)\n";
	 cin >> s3;
	 	
	  C = consolidate (s1, s2, s3);		 	 
	 lowercase(C);			 
	 f = convFactor(C);	
	 	 
	 if (f>0)
	 {
	 	GetData(a0, a1, a2, a3, a4);			 	 	 
	 	printTable(a0, a1, a2, a3, a4, f, s1, s2, s3);		
	 }
	  goHome();		
}

else if (s1 == "time")	//Time option of the menu
{
   cout << " You have chosen Time conversion\n" 
	 <<" Please choose your initial unit:\n"
	 <<" Hour: (hr)  Minute: (min)  or Second: (sec)\n";
	 cin >> s2;
	 cout << " Please choose your second unit:\n"
	 << " Hour: (hr)  Minute: (min)  or Second: (sec)\n";
	 cin >> s3;
	 	
	  C = consolidate (s1, s2, s3);		 	 
	 lowercase(C);				 
	 f = convFactor(C);	
	 	 
	 if (f>0)
	 {
	 	GetData(a0, a1, a2, a3, a4);			 	 	 
	 	printTable(a0, a1, a2, a3, a4, f, s1, s2, s3);
	 } 
	 goHome();		
}

else if (s1 == "angle")		//Angle option of the menu
{
   cout << " You have chosen Angle conversion\n" 
	 << " Please choose your initial unit:\n"
	 << " Degree: (deg)  Radian: (rad)  or Grade: (g)\n";
	 cin >> s2;	
	 cout << " Please choose your second unit:\n"
	 << " Degree: (deg)  Radian: (rad)  or Grade: (g)\n";
	 cin >> s3;
	 	
	 C = consolidate (s1, s2, s3);		 	 
	 lowercase(C);			
	 f = convFactor(C);	
	 	 
	 if (f>0)
	 {
	 	GetData(a0, a1, a2, a3, a4);	 	 	 
	 	printTable(a0, a1, a2, a3, a4, f, s1, s2, s3);
	 }	  
	 goHome();
}

else		//The failure condition and error message for an incorrect input
{
	cout << " Incorrect Entry\n\n ";
	goHome();
} 

	
} while (s1 != "quit" );	//other part of the while loop

return 0;
}

