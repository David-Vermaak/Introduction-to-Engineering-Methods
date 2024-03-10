#include <iostream> 	 //This header containing cout and cin
#include <conio.h>  	 //This header declares getch which pauses until a key is pushed
#include <math.h>		 //This header allows for the use of more complex mathematical operators
#include <string>		 //This header enables string functions
#include <cctype> 		 //This header contains functions that give Boolean answers for given types of char
#include <iomanip>		 //This header contains functions to better format output
#include <ctype.h>		 //This header contains functions to manipulate chars
#include <vector>		//This header allows the use of vectors (better arrays)
#include <algorithm>	//This header allows the use of algorithm functions
#include <numeric>		//This header allows the use of numeric functions
#include "MyLibrary.h"	 //Personal library header


//Functions

//Function gets data from the user and then stores it in doubles
void GetData (double& A0, double& A1, double& A2, double& A3, double& A4)
{

cout << " Enter the starting value (eg: 0)\n";
cin >> A0;
cout << " Enter the ending value (eg: 10)\n";
cin >> A1;
cout << " Enter the increment (eg: 1)\n";
cin >> A2;
cout << " Enter the number of digits for the 1st unit (eg: 1)\n";
cin >> A3;
cout << " Enter the number of digits for the 2nd unit (eg: 3)\n";
cin >> A4;	
	
	if (A1>=A0 && A1>=A2 && A3>=0 && A4>=0) return;	//checks for mathematically impossible entries
			
	else cout << " Error: value outside of scope";	//error message
}


//Function to change all chars in a string to lowercase
string &lowercase (string &S1)	
{
	
	for (int i = 0; i<S1.length(); i++)
	{	S1[i] = tolower(S1[i]);}			//uses tolower in a for loop
return S1;	
}


//Function to change the first char in a string to uppercase
string &Capitalize (string &s1)	
{	s1[0] = toupper(s1[0]);				//uses toupper for capitalization
return s1;	}


//Function to get data into one string
string &consolidate (string &S1, string &S2, string &S3)	
{	
string C = S1.substr (0,1)+ S2.substr (0,1)+ S3.substr (0,1); 	//uses .substr to add strings together
return C;	
}


// Function to return the conversion factor
double convFactor (string z)		
{
	char c0, c1, c2;			//initializes the chars
	String2Char (z, c0, c1, c2);	//uses function String2Char
	
	//this is a massive if/else if function to return the correct numeric value from the 30 options
	//each option is identified by a three-char designation: LMF aka LengthMeterFoot
	//12 for Length: lmc  lmf  lmi  lcm  lcf  lci  lfc  lfm  lfi  lic  lim  lif
	if (c0 == 'l')
	{
		if (c1 == 'm')		//meter
		{
			if (c2 == 'c'){return 0.01;}		//char code lmc    
			
			else if (c2 == 'f'){return 0.3048;}	//char code lmf
			
			else if (c2 == 'i'){return 0.0254;}	//char code lmi
		}
		
		else if (c1 == 'c')		//centimeter
		{
			if (c2 == 'm'){return 100.0;}
			
			else if (c2 == 'f'){return 30.48;}
			
			else if (c2 == 'i'){return 2.54;}	
		}
		
		else if (c1 == 'f')		//foot
		{
			if (c2 == 'm'){return 3.28084;}
			
			else if (c2 == 'c'){return 0.0328084;}
			
			else if (c2 == 'i'){return 12.0;}	
		}
		
		else if (c1 == 'i')		//inch
		{
			if (c2 == 'm'){return 39.37008;}
			
			else if (c2 == 'f'){return 12.0;}
			
			else if (c2 == 'c'){return 0.3937008;}	
		}
	}

	//6 for Mass: mkg  mks  mgk  mgs  msk  msg
	else if (c0 == 'm')
	{
		if (c1 == 'k')		//kilogram
		{
			if (c2 == 'g'){return 0.001;}
			
			else if (c2 == 's'){return 14.5939;}	
		}
		
		else if (c1 == 'g')		//gram
		{
			if (c2 == 's'){return 14593.9;}
			
			else if (c2 == 'k'){return 1000.0;}
		}
		
		else if (c1 == 's')		//slug
		{
			if (c2 == 'k'){return 0.06852177;}
			
			else if (c2 == 'g'){return 6.852177e-5;}
		}
		
	}

	//6 for time:  thm  ths  tms  tmh  tsm  tsh 
	else if (c0 == 't')
	{
		if (c1 == 'h')		//hour
		{
			if (c2 == 'm'){return (1.0/60.0);}
			
			else if (c2 == 's'){return (1.0/3600.0);}		
		}
		
		else if (c1 == 'm')		//minute
		{
			if (c2 == 's'){return (1.0/60.0);}
			
			else if (c2 == 'h'){return 60.0;}
		}
		
		else if (c1 == 's')		//second
		{
			if (c2 == 'h'){return 3600.0;}
			
			else if (c2 == 'm'){return 60.0;}
		}
		
	}

	//6 for angle:  adr  adg  arg  ard  agr  agd 
	else if (c0 == 'a')
	{
		if (c1 == 'd')		//degree
		{
			if (c2 == 'r'){return 57.29578;}
			
			else if (c2 == 'g'){return 0.9;}
			
			
		}
		
		else if (c1 == 'r')		//radian
		{
			if (c2 == 'g'){return 63.661977;}
			
			else if (c2 == 'd'){return 0.01745329;}
	
		}
		
		else if (c1 == 'g')		//grade
		{
			if (c2 == 'd'){return (1.0/0.9);}
			
			else if (c2 == 'r'){return 0.015708;}
	
		}
		
	}
	
	else
	{	cout << "Error, Units not recognized";	//error message
		return -1.0;					//returns a -1.0 which causes an if statement to fail
	}
}


//Function that takes each char in a string and puts it in a char
void String2Char (string y, char& C0, char& C1, char& C2)
{
C0 = y[0];
C1 = y[1];
C2 = y[2];	
}


//Function to print the table with data from Main, convFactor, and GetData
void printTable (double Ar0, double Ar1, double Ar2, double Ar3, double Ar4, double q, string q1, string q2, string q3)
{	Capitalize(q1); Capitalize(q2); Capitalize(q3);	//uses function Capitalize 
	
	cout << "\n\n\n\n The " << q1 << " Conversion of:\n___________________________|\n" 
		 << right <<setw(8) << q2 <<  "  to  " << right << setw(8) << q3 <<endl; 
	for (float i = Ar0; i <= Ar1; i = i + Ar2)
	{
		
		cout <<"___________________________\n"
			 << fixed << setprecision(Ar3) << right << setw(8) << i << "  |  " 
			 << setprecision(Ar4) << right << setw(8) << i/q << "      |" <<endl; 
	}
	
}
	 

//Function to clear the screen and go back to the menu		
void goHome ()
{
	 cout << "\n\n To return to the menu press enter";
	 
	 getch(); 			//pauses until a key is pressed
	 
	 system("cls");		//clears the screen
}


