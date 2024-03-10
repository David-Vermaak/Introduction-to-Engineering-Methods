#include <iostream> 	//This header containing cout and cin
#include <conio.h>  	//This header declares getch which pauses intil a key is pushed
#include <math.h>		//This header allows for the use of more complex mathmatical operators
#include <string>		//This header enables string functions
#include <iomanip>		//This header contains functions to better format output
#include <ctype.h>		// This header contains functions to manipulate chars
#include <vector>		//This header allows the use of vectors (better arrays)
#include <algorithm>	//This header allows the use of algorithm functions
#include <numeric>		//This header allows the use of numeric functions
#include <fstream>		//This header allows the use of functions that edit files
#include "MyLibrary.h"	//Personal library header
 
using namespace std;

const double g = 9.80665;		//setting up a constant value for gravity
const double pi = acos(-1.0);	//setting up a constant value for pi

//Functions

//Function to change all chars in a string to lowercase
string &lowercase (string &S1)	
{
	
	for (int i = 0; i<S1.length(); i++)
	{	S1[i] = tolower(S1[i]);}
	return S1;	
}


//Function that takes each char in a string and puts it in a char
char string2Char (string y)
{
char C1 = y[0];
return C1;
}


//function to choose and change angles
double deg2rad (char c, double angle)
{
						
	if (c == 'd' || 'D') 			//if user wants degrees will convert radians to degrees
	{
		angle = angle * ( pi/180.0);
		
			if (angle < 90 && angle > 0) return angle ;	
			else cout << "Error\n Angle out of Bounds\n";
			goHome();
	}
	else return angle;
}



//Function to clear the screen and go back to the menu		
void goHome ()
{
	 cout << "\n\n To return to the menu press enter";
	 
	 getch(); 			//pauses until a key is pressed
	 
	 system("cls");		//clears the screen
}



//Function for the Quadratic equation 
double quadratic(double b, double c)
{
	double a = 0.5*(-g), t1, t2;

	t1 = (-b + sqrt(b*b - 4.0*a*c))/(2.0*a);
	t2 = (-b - sqrt(b*b - 4.0*a*c))/(2.0*a);

	if (t1>0) return t1;
	else return t2;
}

