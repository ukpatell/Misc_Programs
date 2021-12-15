/************************
Name : Umangkumar Patel
Date : October 27, 2019
Prof : Fahringer, Daniel
Prog : Game of Life #7
************************/
#include<iostream>
#include<fstream>										      
#include<iomanip>
using namespace std;

const int ROW = 12;
const int COL = 12;

ofstream outFile;									   		 // Output File

void intro();
void value (int [ROW][COL], int [ROW][COL]);				 // Loop for Each Organism	
int check(int[ROW][COL], int,int);			 				 // Grants Life if Passes for each Organism
void print(int [ROW][COL]);									 // Print
void copy(int[ROW][COL], int [ROW][COL]);					 // Copy Array
int main()
{
	int gen;									
	int life[ROW][COL] = 
	    {
			{0,0,0,0,0,0,0,0,0,0,0,0},
	    	{0,0,0,0,1,0,1,0,1,0,0,0},
	    	{0,0,0,1,0,1,0,1,0,0,0,0},
	    	{0,0,0,0,0,0,0,0,0,0,0,0},
	    	{0,0,0,0,1,0,1,0,1,0,0,0},
	    	{0,0,0,1,0,1,0,1,0,0,0,0},
	    	{0,1,1,1,1,1,1,1,1,1,1,0},
	    	{0,0,0,0,1,1,1,1,0,0,0,0},
	    	{0,0,0,0,1,0,1,0,1,0,0,0},
	    	{0,0,0,1,0,1,0,1,0,0,0,0},
	    	{0,0,0,0,1,0,1,0,1,0,0,0},
	    	{0,0,0,0,0,0,0,0,0,0,0,0} 	};						// Original  Generation
	int life2[ROW][COL] = {0};									// Next-Life Generation
	
	cout << "Enter Number of Generations To \nCalculate Survival After the Parent: ";
	cin  >> gen;
	outFile.open("Generation.txt");								// File
	intro();													// Instructions/ Header for the OUtput
	
	outFile << "\nGeneration\n\n";
	print(life);
	for(int x = 1; x <= gen; x++)
	{
		value(life,life2);
		outFile << "\nGeneration " << x << " \n\n";
		print(life2);
		copy(life,life2);
	}
	
	outFile.close();										// Close Output File
	cout << "Output saved as Generation.txt" << endl;		// Display Message
}
void intro()
{
	outFile << "Name: Umangkumar Patel\t\t\tGame Of Life\t\t\tDate: 10/24/2019\n\n";
	outFile << "\tRules for the Game:\n\t\t• Birth:     An organism will be born in each empty location that has exactly 3 neighbors\n";
	outFile << "\t\t• Death:     An organism with 4 or more organisms as neighbors will die from overcrowding."
			<< "\n\t\t\t     An organism with 1 or 0 neighbors will die of loneliness\n";
	outFile << "\t\t• Survival:  An organism with 2 or 3 neighbors will survive to the next generation\n";
}
void value(int old[ROW][COL], int success[ROW][COL])
{
	for(int r = 1;  r < 11; r++)							// Avoids Borders
	{
		for(int c = 1; c < 11; c++)							// Avoids Borders***
		{	
			success[r][c] = check(old,r,c);					// Sends for Life or No
		}
	}
}
int check(int o[ROW][COL], int r, int c)
{
	int total = 0;
	total = o[r-1][c-1] + o[r-1][c] + o[r-1][c+1]
		  + o[r][c-1] + o[r][c+1]
		  + o[r+1][c-1] + o[r+1][c] + o[r+1][c+1];			// Calculates Sum
			
	if(total == 3 && o[r][c] == 0)							// Birth
		return 1;
	if(o[r][c] == 1)
	{
		if(total == 2 || total == 3)						// Survival
			return 1;
		else
			return 0;										// Death 
	}
	total = 0;												// Reset Total
	return 0;
}
void print(int print[ROW][COL])
{
	for(int x = 0; x < 12; x++)
		outFile <<"\t" <<  x;
	outFile << endl;
	outFile << endl;
	
	for (int r = 0; r < ROW; r++)
	{
		outFile << r;
		for(int c = 0; c < COL; c++)
		{
			outFile << " \t" << print[r][c];
		}
		outFile << endl;
	}
}
void copy(int old[ROW][COL], int n[ROW][COL])
{
	for(int row = 0; row < ROW; row++)
	{
		for(int col = 0; col < COL; col++)
			old[row][col] = n[row][col];					// Copies 2nd Array to 1st Array
	}
	n[ROW][COL] = {0};
}







