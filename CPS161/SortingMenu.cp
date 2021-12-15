/*************************
Name: Umangkumar Patel
Date: November 12, 2019
Prof: Fahringer, Daniel
Prog: Shell Sort #9
	  Write A Menu-Driven
	  Sorting Program
	  With 20 Random #
*************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

const int SIZE = 20;								// Constant Size of an Array
int sort[20];										// Created an Array with SIZE^^^

void menu();										// Introduction
void insertion();									//*****SORTS*******//
void dan();
void select();
void shell();
void display();										// Unsorted Array of Rand() #
void print();										//   Sorted Arrat

int main()
{
	menu();											// Call to the Menu-Function
	return 0;
}
void menu()
{
	system("color f5");
	system("cls");
	int choice;										// Choice (input)
	cout << "\t\t\t\t\tWelcome To My Sorting Program\n\n";
	cout << "\tInstructions: Enter your Choice(#) from the following methods to sort this Random Number(s)\n\n\t";
	cout << "1) Insertion Sort\t";
	cout << "2) Dan   Sort\n\t";
	cout << "3) Selection Sort\t";
	cout << "4) Shell Sort\n\n\t";
	cout << "-------------------------------------------------------------------------------------------";
	display();										// displays unsorted random list
	cout << "\n\t-------------------------------------------------------------------------------------------\n";
	cout << "\n\tEnter Your Choice: ";				// asks user for input
	cin  >> choice;									// input(choice)
	
	switch(choice)									// call appropriate sort based on choice
	{
		case 1: 
			insertion();							// Insertion Sort
			break;
		case 2:
			dan();									// ?Bubble 
			break;
		case 3:
			select();								// Selection Sort
			break;
		case 4:
			shell();								// Shell Sort
			break;
		default:
			cout << "\nYour Choice is Invalid! Rerun...";		// If anyother selected....
			break;
	}
}
void insertion()
{
	int val,temp;
    for (int x = 1; x < SIZE; x++) 							// Start at Index(+1)
	{
        val = x;											// Initialize to val for comparison
        while (val > 0 && sort[val - 1] > sort[val])		// Compares Val with Pre-Val, if Less then..
		 {
            temp = sort[val];								// Complete Swapping Method
            sort[val] = sort[val - 1];
            sort[val - 1] = temp;
            val--;											// Decrement
        }
    }
	print();												// Display
}	
void dan()
{
	int val,temp;
	   for (int i = 0; i < SIZE; i++)
	   {
       		val = i;
			while (val > 0 && sort[val] < sort[val-1])
			{
        	    temp = sort[val];								// Complete Swapping Method
            	sort[val] = sort[val - 1];
            	sort[val - 1] = temp;
        	    val--;
        	}
       }
	print();										// Display
}
void select()
{
	int temp;
	
	for(int i = 0; i < SIZE-1; i++)
	{	
		int minNum = i;								// Locate Min Number in an Array
		for(int x = i+1; x < SIZE; x++)
		{
			if(sort[x] < sort[minNum])				// Comparison
				minNum = x;							// Initialize it
		}
		temp 		 = sort[i];						// Swapping Method
		sort[i] 	 = sort[minNum];
		sort[minNum] = temp;
		
	}
	print();										// Display
}
void shell()										/* USED TWO LOOPS */ /* NOT ABLE TO USE WHILE */
{
	int gap = SIZE;									// Initialize Gap (N)
	int tmp;										// temp variable
	do 												// do this until.....
	{
		gap = floor(gap + 1)/2;						// Gap Value, for the closest integer (odd/even)
		for (int i = 0; i < (SIZE - gap); i++)		// Start at 0-gap vals
		{
			if (sort[i + gap] < sort[i])			// If indices are 'true' for comparison
			{
				tmp = sort[i+gap];					// Swapping Method
				sort[i + gap] = sort[i];
				sort[i] = tmp;
			}
		}
	} while(gap >1);								// gap isn't 1 or less
	print();
}
void display()										// Displays Unsorted
{
	
	srand(time(0));
	for(int i = 0; i < SIZE; i++)
		sort[i] = (rand() % 50) + 1;
	cout << "\n\tUnsorted Array: ";
	for(int i = 0; i < SIZE; i++)
		cout << sort[i] << " "; 
}
void print()										// Displays sorted
{
	cout << "\n\t-------------------------------------------------------------------------------------------";
	cout << "\n\tSorted   Array: ";
	for(int i = 0; i < SIZE; i++)
		cout << sort[i] << " ";
	cout << "\n\t-------------------------------------------------------------------------------------------\n";
}
