//       ____   __     __
//        /   /   \  /   \
//       /   /      /
//      /    \___/  \___/
//
// Date: 9/1/2021
// Name: David Vermaak
//Project Description: This program takes the three sides of a triangle and calculates various Geometric
// properties of the triangle, including the area, incircle radius, circumcircle radius, and remaining area
// Inputs: The three sides of a triangle
// Outputs: Three angles (rad or deg), Area (units^2), and radius (units)
//*************************************************************

#include <iostream> 	//This header containing cout and cin
#include <conio.h>  	//This header declares getch which pauses intil a key is pushed
#include <math.h>		//This header allows for the use of more complex mathmatical operators
#include <string>		//This header enables string functions
#include <cctype> 		//This header contains functions that give boolian answers for given types of char
#include <iomanip>		//This header contains functions to better format output


using namespace std; //introduces namespace std

int main ( )
{
	
// initalizes the variables of the sides and angles of the triangle	
double side_A, side_B, side_C, angle_A, angle_B, angle_C;
// initalizes the variables of the Area, incircle radius, circumcircle radius, and remaining area	
double Area, AreaIR, AreaOR, InRadius, OutRadius, rArea, s;
// sets up a constant for the value of pi	
const float pi = acos(-1.0);
//initalizes a variable for the menu				
int choice;
//initalizes a character used to choose radian or degree output
char angle;
string Angle = " radians  ";
//initalizes a string used to choose the units for the output
string units;

// prompt user for input
cout << "This program takes the three sides of a triangle and calculates various Geometric properties"
<< "\n\nPlease enter the units your side lengths are in, eg. meters\n";
cin >> units;
units = " " + units;	//adds a space before the string for better legibility

do 
{
	cout << "Please enter the three side lengths of your triangle:\n\n";

cout <<"        C \n";		//provides the user with a visual of the triangle
cout <<"       / \\ \n";	//this helps with understanding where the angles and sides are 
cout <<"      /   \\ \n";	//in relation to each other
cout <<"    a/     \\b \n";
cout <<"    /       \\ \n";
cout <<"   /_________\\ \n";
cout <<"  B     c     A \n\n\n";


cout << "side a: ";	
cin >> side_A;
cout << "\n side b: ";
cin >> side_B;
cout << "\n side c: ";
cin >> side_C;	


//this statement checks if the values that were entered are within acceptable parameters 	
if (side_A < 0 || side_B < 0 || side_C < 0 )
{ cout << "\n Error.\n A negative value for any of the triangles sides is not allowed.\n Try again.";
choice = 1;
}

else if (side_A > (side_B + side_C) || side_B > (side_A + side_C) || side_C > (side_B + side_A) )
{ cout << "\n Error.\n One of the sides of the triangle exceeds parameters.\n Try again.";
choice = 1;
}

else

		//calculates the angles by law of sines
		angle_A = acos((pow(side_B, 2) + pow(side_C, 2) - pow(side_A, 2))/(2 * side_B * side_C));
		angle_B = acos((pow(side_A, 2) + pow(side_C, 2) - pow(side_B, 2))/(2 * side_A * side_C));		
		
		//pi is the total number of radians in a triangle so c = total-(a+b)
		angle_C = (pi)-(angle_A + angle_B);	
	
		//initial calculations of the area using s, the semi-perimeter (Heron's Formula)
		s = 0.5*(side_A + side_B + side_C);
		Area = 	sqrt(s*(s-side_A)*(s-side_B)*(s-side_C));
		choice = 3;
		
	
} while (choice == 1);


cout << "Please enter the three side lengths of your triangle:\n\n";

cout <<"        C \n";		//provides the user with a visual of the triangle
cout <<"       / \\ \n";	//this helps with understanding where the angles and sides are 
cout <<"      /   \\ \n";	//in relation to each other
cout <<"    a/     \\b \n";
cout <<"    /       \\ \n";
cout <<"   /_________\\ \n";
cout <<"  B     c     A \n\n\n";


cout << "side a: ";	
cin >> side_A;
cout << "\n side b: ";
cin >> side_B;
cout << "\n side c: ";
cin >> side_C;	


//this statement checks if the values that were entered are within acceptable parameters 	
if (side_A < 0 || side_B < 0 || side_C < 0 )
{ cout << "\n Error.\n A negative value for any of the triangles sides is not allowed.\n Program terminated.";

return 1; }

else if (side_A > (side_B + side_C) || side_B > (side_A + side_C) || side_C > (side_B + side_A) )
{ cout << "\n Error.\n One of the sides of the triangle exceeds parameters.\n Program terminated.";

return 1; }

else

		//calculates the angles by law of sines
		angle_A = acos((pow(side_B, 2) + pow(side_C, 2) - pow(side_A, 2))/(2 * side_B * side_C));
		angle_B = acos((pow(side_A, 2) + pow(side_C, 2) - pow(side_B, 2))/(2 * side_A * side_C));		
		
		//pi is the total number of radians in a triangle so c = total-(a+b)
		angle_C = (pi)-(angle_A + angle_B);	
	
		//initial calculations of the area using s, the semi-perimeter (Heron's Formula)
		s = 0.5*(side_A + side_B + side_C);
		Area = 	sqrt(s*(s-side_A)*(s-side_B)*(s-side_C));


do	//creates a loop for the menu that returns the user here after each switch choice
{
	// display menu
	cout << "\n\nPlease choose one of the following options to continue: (1,2,3,4)\n";
	cout << "(1): Find the 3 angles of the triangle, and the triangle area \n";
	cout << "(2): Find the largest incircle radius, and the remaining interior area of the triangle  \n";
	cout << "(3): Find the circumcircle radius, and the remaining interior area of the circumcircle  \n";
	cout << "(4): Quit 	\n\n";
	cout << "Enter your choice :";
	
	//get user input for use in the switch choice
	cin >> choice; 
	cout << "\n"; 

    

	switch(choice)	//easy way to set up a menu where it jumps to the correct line 
					//depending on the value of choice the user inputs
	{
		
		
		case 1:
			
			cout << "Would you like the angles displayed in radians (r) or  degrees (d)?\n (r or d): \n\n";
			cin >> angle;
			
					if (angle == 'd')	//if user wants degrees will convert radians to degrees
					{
					angle_A = angle_A * ( 180/ pi);
					angle_B = angle_B * ( 180/ pi);		
					angle_C = angle_C * ( 180/ pi);
					Angle = " degrees  ";
					}
					
			//visual output for the user that allows for better understanding of the other outputs
			cout <<"        C \n";
			cout <<"       / \\ \n";
			cout <<"      /   \\ \n";
			cout <<"    a/     \\b \n";
			cout <<"    /       \\ \n";
			cout <<"   /_________\\ \n";
			cout <<"  B     c     A \n\n\n";
			
			
			cout << "The three angles are A = " << angle_A << Angle 
				 << " B = " << angle_B << Angle 
				 << " and C = " << angle_C << Angle
				 << "\nThe area of the triangle is: " << Area << units << " squared" 
				 <<" \n \n To return to the menu press enter";
			 
			getch(); 		//pauses until a key is pressed
			system("cls");	//clears the console screen
			break;			//goes to the end of the switch statment
		
		
		
		
		case 2:
			cout << " Finding the largest incircle radius, and the remaining interior area of the triangle\n"; 
			
				InRadius = ((2 * Area)/(side_A + side_B + side_C));
				AreaIR = pi * (pow(InRadius, 2));
				rArea = Area - AreaIR;
				
		//visual output for the user that allows for better understanding of the other outputs		
			cout <<"           C \n";
			cout <<"          / \\ \n";
			cout <<"         /   \\ \n";
			cout <<"       a/  .  \\b \n";
			cout <<"       /.  R1 .\\ \n";
			cout <<"      /.   .-->.\\ \n";
			cout <<"     /  .     .  \\ \n";
			cout <<"    /      .      \\ \n";
			cout <<"   /_______________\\ \n";
			cout <<"  B         c       A \n\n\n";
	
			cout << "The largest incircle radius is: " << InRadius << units 
				 << " \nand the remaining interior area of the triangle = " << rArea << units << " squared"	
				 << "\n \n To return to the menu press enter";
			
			getch(); 
			system("cls");
			break;
		
		
		
		case 3:
			 
			
				
				OutRadius =	sqrt((side_A * side_B * side_C)/((side_A + side_B + side_C) * (side_B + side_C - side_A) * (side_C + side_A - side_B) * (side_A + side_B - side_C)));
				AreaOR = pi * (pow(OutRadius, 2));
				rArea = Area - AreaOR;
				
			//visual output for the user that allows for better understanding of the other outputs
			cout <<"             .             \n";
			cout <<"       .      ^ C  .       \n";
			cout <<"             /|\\          \n";
			cout <<"   .        / | \\     .   \n";
			cout <<"          a/  |  \\b       \n";
			cout <<" .        /   |   \\     . \n";
			cout <<"         /    *R2  \\      \n";
			cout <<"  .     /           \\  .  \n";
			cout <<"       /             \\    \n";
			cout <<"    . /_______________\\   \n";
			cout <<"    B         c       A    \n";
			cout <<"        .           .      \n";
			cout <<"              .            \n";
			cout <<"                           \n";	
			cout << "\n \n The circumcircle radius is: " << OutRadius << " \nand the remaining interior area of the circumcircle = " << rArea << units << " squared";	
			cout << "\n \n To return to the menu press enter";
			
			getch(); 
			system("cls");
			break;
		
		
		default:	//catch-all case that ends the program if any number other than (1,2,3) is entered
			cout << "Program has ended\n";
			
			return 0;					
	}				
}

while(choice != 1 || 2 || 3);	//keeps the loop going while conditions are right

return 0;
}
