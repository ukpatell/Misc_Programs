#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;


int  num1, den1,
     num2, den2;															// Global Variables
int numA,denA;
ofstream outFile;															// create file object (Output)

void checkNumber(int,int,int,int);
void handleSame();
void gcf(int,int);

int main()
{
	double num;																// number to read the file
	int tempCount = 0;
	
	ifstream inFile;														// create file object (Reading)
	
	
	inFile.open("P5Fractions.txt");											// Open Input  File
	outFile.open("OutputF.txt");												// Open Output File
	outFile << "\t\tFraction(1)\tFraction(2)\tSum\n\n"; 					// Output File Header
	while(inFile >> num)													// Continue As Long There's a Number
	{
		tempCount++;														// Count Occurances (of Numbers being Inputted) for the Calculation
		
		switch(tempCount)													// Based On the Count, Assign Numbers
		{
			case 1:
				num1 = num;													// Numerator (Fraction   One)
				break;
			case 2:
				den1 = num;													// Denomenator (Fraction One)
				break;
			case 3: 
				num2 = num;													// Numerator (Fraction   Two)
				break;
			case 4:
				den2 = num;													// Denominator (Fraction Two)
				checkNumber(num1,den1,num2,den2);							// Send Them for Calculations in the Function
				tempCount = 0;												// Reset the Count
				
				break;
		}
		
	}
	inFile.close();															// Close the Input File
	cout << "Data Saved Successfully! (Output.txt)\n";						// Message User for an Update
	outFile.close();														// Close the Output File

}
void checkNumber(int n1,int d1,int n2,int d2)
{
	if(d1 == d2)
	{
		numA = (n1 +n2);												// Addition of Numerators
		denA = d1;														// Addition of Denominators
		
		bool nIsNegative,dIsNegative;
		/*****Convert Negative to Positive******/
		if(numA < 0)
		{
			numA = numA * (-1);
			nIsNegative = true;
		}
		if(denA < 0)
		{
			denA = denA * (-1);
			dIsNegative = true;
		}
		//cout << numA << " " << d1 << endl;
		gcf(numA, denA);														// Simplify using function
		
		if(nIsNegative == true)
			numA = numA * (-1);
	    if(dIsNegative == true)
			denA   =   denA * (-1);

		outFile << "\t\t" << n1 << " / " << d1 << "\t\t" << n2 << " / "
				<< d2 << " \t\t" << numA << " / " << denA << endl; 
	}
	else if(d1 == 0 || d2 == 0)
	{
		outFile << "\t\t" << n1 << " / " << d1 << "\t\t" << n2 << " / "
				<< d2 << " \t\t" << "ERROR: CANNOT DIVIDE BY 0\n";
	}
}
void gcf(int n, int d)
{
	int big,small, remain, answer;
	
	
	//*****Determine the Larger Number*****//
	if(n > d)
	{
		big = n,small = d;
	}															
	else
	{
		big = d,small = n;
	}
	do
	{
		
		answer = big / small;
		remain = big - (small * answer);	
		
		if(remain != 0)
		{
			big   = small;
			small = remain;	
		}
	}while(remain < 0 || remain > 0);
		numA = n / answer;
		denA = d / answer;
}
	
	
		
