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
 
 int main ( )	//The Main function
{
string  units, s2, option;	
double height, hmax, v_initial, v_final, vx, vy, vy_final, range, displacement, dx, dy, angle, time, timehmax, tempT;
int n;
char c;
vector <double> N;
	
do 
{

// display menu
cout << " Hello, this program calculates the parabolic trajectory of a projectile\n"
	 << " Please enter your measurment system to continue:\n"
	 << " Meters \n" << " Feet \n"  << " Quit\n\n";
cin >> units;
lowercase(units);		//calls the function: lowercase 

if( units == "quit") return 0;	//The quit condition of the menu and loop

else if (units == "meter" || units == "meters" || units == "feet" || units == "foot" )
{
cout << " Please enter your initial height:\n";
cin >> height;
cout << " Please enter your initial velocity:\n";
cin >> v_initial;
cout << "Would you like to input your angles in radians or degrees? \n ";
cin >> s2;
cout << " Please enter your initial angle:\n";
cin >> angle;
cout << " Please enter the number of data points you want:\n";
cin >> n;

	if (height < 0 || v_initial <= 0 || n <5 || n > 100) 	//The failure condition
	{
		cout <<"Incorrect Input"; 
		goHome();	
	}  

	else
	{
	c = string2Char(s2);				//calls the function string2char and stores to char c
	angle = deg2rad(c, angle);			//calls the function deg2rad and returns angle

	time = quadratic ((v_initial*sin(angle)), height);
	
	//time independant calculations
	timehmax = (v_initial*sin(angle))/g;		
	hmax = height + ((pow(v_initial,2)*pow(sin(angle),2))/(2*g));

	vx = v_initial*cos(angle);
	vy = v_initial*sin(angle);

	vy_final = v_initial*sin(angle)-(g*time);
	v_final = sqrt(pow(vx,2)+pow(vy_final,2));
	
	//time based calculations
	dx = vx*time;				
	dy = vy*time - 0.5*g*pow(time,2);
	displacement = sqrt(pow(dx,2)+pow(dy,2));
	range = v_initial * cos(angle) * time;

	N.push_back(0.0); 			//Time
	N.push_back(0.0); 			//initial position x
	N.push_back(height); 		//initial position y
	N.push_back(vy); 			//initial velocity y
	N.push_back(v_initial);		//initial velocity

	for(int i=1; i < n; i++)
	{
	dx = (i/(n-1.0))*displacement;							//position x
	tempT = dx/vx;											//Time
	N.push_back(tempT); 												
	N.push_back(dx);													
	N.push_back(height + vy*tempT+0.5*-g*pow(tempT,2));		//position y
	N.push_back(vy-g*tempT);								//velocity y
	N.push_back(sqrt(pow(vx,2)+pow((vy-g*tempT),2)));		//velocity
	}


	cout << " Time of Flight: " << time << " seconds \n Displacement: " << displacement << " " << units 
		 << "\n Range: " << range << " " << units << "\n Maximum Height: " << hmax << " " 
		 << units << "\n Final Velocity: " << v_final << " " << units << "/second\n\n ";


	cout <<" Would you like the results Displayed or Stored to a file?\n\n Display or Store:";
	cin >> option;
	lowercase(option);	
		
	if (option == "display" || option == "displayed")
	{

	cout << "\n\nTime\t  x("<<units<< ")\t y("<<units<< ")\tVelocity in y\t  Velocity("<<units<<"/second)\n";
	
	for (int a=0; a <= (N.size()-5); a+=5) 
	{
		cout << left << fixed << setprecision(2) << setw(10) << N[a] << setw(15) << N[a+1] << setw(15) << N[a+2] << setw(18) << N[a+3] << setw(18) << N[a+4] <<endl;
	}
	
	goHome();
	}	
	 

	else if (option == "store" || option == "stored")
	{
	//open file
	ofstream outfile("File1.csv");
	outfile << "Time,x,y,Velocity in y,Velocity\n";

	for (int a=0; a <= (N.size()-5); a+=5) 
	{
		outfile << N[a] << "," << N[a+1] << "," << N[a+2] << "," << N[a+3] << "," << N[a+4] <<"\n";
	}
	
	outfile.close();
	goHome();	
	}	

}

}

else		//The failure condition of the menu
{
	cout << " Incorrect Unit\n\n ";		//error message for an incorrect input
	goHome();
} 

	
} while (units != "quit" );

return 0;
}

