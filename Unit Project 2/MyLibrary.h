using namespace std; //introduces namespace std
//Function declarations

//Function to get unit data into one string
string &consolidate (string &z1, string &z2, string &z3);

//Function to change all chars in a string to lowercase
string &lowercase (string &s);

//Function to change the first char in a string to uppercase
string &Capitalize (string &s1);

//Function that takes each char in a string and puts it in a char
void String2Char (string, char&, char&, char&);

//Function to get data for the loop 
void GetData (double&, double&, double&, double&, double&);	

// Function to return the conversion factor
double convFactor (string);

//Function to print the table 
void printTable (double, double, double, double, double, double, string, string, string);

//Function to clear the screen and go back to the menu
void goHome ();
