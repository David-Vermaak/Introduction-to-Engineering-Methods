//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 9/1/2021
// Name: David Vermaak
//Project Description: Law of sines calculator
// Inputs: angles and sides of triangles
// Outputs: angles and sides of triangles
//*************************************************************

#include <iostream> 	//This header containing cout and cin
#include <string>
#include <conio.h>  	//This header declares getch which pauses intil a key is pushed
#include <math.h>		//This header allows for the use of more complex mathmatical operators

using namespace std; //introduces namespace std

int main ( )
{
int choice;			//initalizes a variable for the menu
do					//creates a loop 
{
	// display menu
	cout << "Please choose one of the following options to continue:\n\n";
	cout << "Two sides and an angle  (1) \n";
	cout << "Two angles and a side 	(2) \n";
	cout << "Quit with any other number	\n\n";
	cout << "Enter your choice :\n";
	
	//get user input
	cin >> choice; 
	cout << "\n"; 

    double a, b, c, angle_A, angle_B, angle_C;	// initalizes the variables
	const float pi = 3.14159265;				// sets up a constant

	switch(choice)	//easy way to set up a menu where it jumps to the correct line
	{
		
		
		case 1:
			
			cout << "You have selected Two sides and an angle, also known as a SSA triangle\n";
			cout << "Please input the first side\n";
			cin >> a;
			cout << "Please input the second side\n";
			cin >> b;
			cout << "Please input the angle in degrees\n";
			cin >> angle_A;
			
				angle_A = angle_A * (pi / 180);			//degrees to radians
				angle_B = asin((b*sin(angle_A))/a);		//calculates the angle by law of sines
				angle_C = (pi)-(angle_A + angle_B);		//pi is the total number of radians in a triangle
				
				c = (sin(angle_C)*a)/sin(angle_A);		//calculates the final side by law of sines
				
				angle_B = angle_B * ( 180/ pi);			//radians to degrees
				angle_C = angle_C * ( 180/ pi);

				
			cout << "The two angles are B = " << angle_B << " and C = " << angle_C;	//output
			cout << " The side c is " << c;
			 
			getch(); 		//pauses until a key is pressed
			system("cls");	//clears the console screen
			break;
		
		case 2:
			cout << "You have selected Two angles and a side, also known as a AAS triangle\n"; 
			cout << "Please input the first angle in degrees\n";
			cin >> angle_A;
			cout << "Please input the second angle in degrees\n";
			cin >> angle_B;
			cout << "Please input the side\n";
			cin >> a;
			
				angle_A = angle_A * (pi / 180);			//degrees to radians
				angle_B = angle_B * (pi / 180);			//degrees to radians
				angle_C = (pi)-(angle_A + angle_B);		//pi is the total number of radians in a triangle
				
				b = (sin(angle_B)*a)/sin(angle_A);		//calculates the side b by law of sines
				c = (sin(angle_C)*a)/sin(angle_A);		//calculates the side c by law of sines
				
				angle_C = angle_C * ( 180/ pi);			//radians to degrees
				
			cout << "The two sides are b = " << b << " and c = " << c;	//output
			cout << " The angle C is " << angle_C;
			
			
			getch(); 
			system("cls");
			break;
		
		default:							//catch-all case for numbers not used
			cout << "Program has ended\n";
			
			return 0;	
		
		
					
	
	}
		
			
}
while(choice != 1 || 2);	//keeps the loop going while conditions are right

return 0;
}


