/**************************
Name: Umangkumar Patel
Date: February 2, 2020
Prof: Fahringer, Daniel
Prog: Coin Driver Program
**************************/
#include "UPCoin.h"
#include<iostream>
using namespace std;

int main()
{
	const int SIZE = 3;						// Constant Size
	UPCoin *coin[SIZE];						// To Instantiate Objects v. loop w. ptr
	
	int year, quantity;						// Variables
	double faceVal, marketVal;
	string description;
	
	for(int x = 0; x < SIZE; x++)			// Instantiate Objects of Coin
	{
		coin[x] = new UPCoin();				// Create Objects
	}
	
	for(int y = 0; y < SIZE; y++)			// Loop for Inputting Data
	{
		system("color f5");					// System Color Change
		system("cls");						// Clear Screen
		
		cout << "Data Entry For Coin ( " << y << " )\n";
		
		cout << "\tYear        :\t";				// Input Year
		cin  >> year;
		coin[y]->setYear(year);					// Pass Year as an Accessor Method
		
		cout << "\tQuantity    :\t";				// Input Quantity
		cin >> quantity;
		coin[y]->setQuant(quantity);				// Pass Quantity as an Accessor Method
		
		cout << "\tFace Value  :\t";				// Input Face Value
		cin >> faceVal;
		coin[y]->setFaceVal(faceVal);			// Pass F.V. as an accessor method
		
		cout << "\tMarket Value:\t";				// Input Market Value
		cin >> marketVal;
		coin[y]->setMarketVal(marketVal);		// Pass M.V. As an accessor method
		
		cout << "\tDescription :\t";				// Input Description
		cin >> description;
		coin[y]->setDescription(description);	// Pass Descript. as an Accessor method
	}
	
	system("color f3");
	system("cls");
	
	for(int i = 0; i < SIZE; i++)
	{
		cout << "Coin [ " << (i+1) << " ]\n";
		cout << "-----------\n";
		
		cout << "\tYear         : " << coin[i]->getYear() << endl;
		cout << "\tQuantity     : " << coin[i]->getQuant() << endl;
		cout << "\tDescription  : " << coin[i]->getDescription() << endl;
		cout << "\tFace Value   : $ " << coin[i]->getFaceVal() << endl;
		cout << "\tMarket Value : $ " << coin[i]->getMarketVal() << endl;
		cout << "\tDifference   : $ " << coin[i]->difference() << endl;
		cout << endl;	
	}
	cout << "*Total**Collection**: $ " << UPCoin::totalVal << endl;
	return 0;
}
