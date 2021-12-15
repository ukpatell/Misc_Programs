/************************
Name: Umangkumar Patel
Date: January 26, 2020
Prof: Fahringer, Daniel
Prog: Assignment #1.1
*************************/
#include<iostream>
using namespace std;

//	Functions
double calcVol(double,double);	
double calcSA(double,double);

int main()
{
	// Variable
	double radius,height,area,volume;		
	
	// System Color/Clear
	system("color f3");
	system("cls");
	
	// Header
	cout << "This Program Calculates the Surface Area and Volume of a Circular Cylinder.\n\n";
	
	// Loop for Test Data
	for(int i = 0; i <= 3; i++)
	{
		cout << "Test # " << i+1 << endl;
		
		// Input
		cout << "\tEnter Radius: ";
		cin  >> radius;			
		cout << "\tEnter Height: ";
		cin >> height;
		
		// Calculation
		volume = calcVol(radius,height);
		area   = calcSA(radius,height);
		
		// Display Results
		cout << "Area  :\t" << area << endl;
		cout << "Volume:\t" << volume << endl;
		system("PAUSE");
		
		// Clear the input
		radius = 0.0;
		height = 0.0;
	}
	return 0;
}

double calcVol(double r, double h)		// Function to calculate Volume
{
	return (3.14159 * r * r * h);
}
double calcSA(double r, double h)		// Function to calculate S.Area
{
	return ((2 * 3.14159 * r * h) + (2 * 3.14159 * r * r));
}
