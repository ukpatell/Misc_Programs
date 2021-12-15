/***************************
Name: Umangkumar Patel
Date: October 20, 2019
Prof: Fahringer, Daniel
Prog: Generate Magic Square
	  with Random Values
	  (3 x 3)
***************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int ROW = 3;							// ROW size
const int COL = 3;							// COL size
int   magic[ROW][COL];						// Set-Up Magic Square

void print();								// Prints the Magic Square
void fill();								// Fills  the Magic Square
bool magicCheck();							// Checks if it is the Magic Square
void clear();								/* Clears the Square, to reset Values 
											   If not Magic Square on First    */
void magicTest();							// Sample Magic Square for Test Purposes
int counter,stop;										   
int main()
{
	srand(time(0));						 	// System Time
	int exit;
	system("color 2");						// Console Color(text)
	cout << "\tInstructions:\n\n\tProgram Asks For A Number\n"
		 << "\tOf Times You Wish To Run In Search For Magic Square\n"
         << "\tIt May Either Run Into The Last(Sample) Data\n"
		 <<	"\tOr Either It Finds the Square Before That\n"
		 << "\n\tEnter Loop-Control Number: ";
	cin >> stop;
	while(exit != 1)
	{
		counter++;							// Counter
		fill();								// Call the Fill()  Function 
		if(magicCheck() == false)			// If Magic Square is Not Found
		{
			clear();						// Call the Clear Function to Clear the Board
			exit = 0;						// Set the Exit Value (false)
		}
		else if(magicCheck() == true)		// If Magic Square is Found
		{
			if(counter == stop)				// Display if it reaches Counter
			{
				system("color c1");				
				cout << "\n\tSample Data..." << endl;	
			}
			else							// Else Display this
				system("color f3");
			cout << "\n\n\t\tAttempts: " 
			     << counter << endl;		// Displays Attempts
			exit = 1;						// Set the Exit value (true)
		}

	}
	print();								// Call the Print() Function
	return 0;
}
void fill()										
{
	for(int n = 1; n <= 9; n++)
	{
		int r,c;				
		do
		{
			r = (rand() % 3 );				// Random Row
			c = (rand() % 3 );				// Random Column
		}while(magic[r][c] != 0);			// Continue Until Location (0) is Found
		magic[r][c] = n;					// If Location Found, set it to the For Loop Number
	}
		if(counter == stop)					
		{
			magicTest();					// Run the test data if it reaches the stop-value
		}
	
}
void print()
{

	for(int r = 0; r < ROW; r++)
	{
		cout << "\t\t";
		for(int c = 0; c < COL; c++)
			cout << magic[r][c] << " ";		// Prints the Square
		cout << endl;
	}
}
bool magicCheck()
{
	int d1 = 0, d2 = 0;
	int v  = 0, h  = 0;					// Sum Counter of Diagonals(2), Vertical & Horizontal
	int tV[3];							// Keeps track of Vertical and Horizontal Total 
	
	for(int i = 0; i < ROW; i++)		// Calculates the Diagnols
	{
		d1 += magic[i][i];				// Diagnol 1
		d2 += magic[i][2-i];			// Diagnol 2
	}
	for(int r = 0; r < ROW; r++)		// Calculates Vertical and Horizontal
	{
		for(int c = 0; c < COL; c++)
		{
			v += magic[c][r];			// Vertical   Sum
			h += magic[r][c];			// Horizontal Sum
		}
		if(v == 15 && h == 15)			
		{
			tV[r] = 15;					// save the sum in array
		}
		else
			tV[r] = 0;
		v = 0;
		h = 0;
	}
	if(d1 == 15 && d2 == 15 && tV[0] == 15 && tV[1] == 15 && tV[2] == 15)
		return true;					// Return True if Sum is true
	else
		return false;					// Else Return False
}
void clear()
{
	for(int r = 0; r < ROW; r++)
	{
		for(int c = 0; c < COL; c++)
			magic[r][c] = 0;			// Clear the Values
	}
}
void magicTest()						// Sample Data (Magic Square)
{										
	magic[0][0] = 4;
	magic[0][1] = 9;
	magic[0][2] = 2;
	magic[1][0] = 3;
	magic[1][1] = 5;
	magic[1][2] = 7;
	magic[2][0] = 8;
	magic[2][1] = 1;
	magic[2][2] = 6;
}
