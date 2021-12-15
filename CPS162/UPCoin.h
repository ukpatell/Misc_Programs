/************************
Name: Umangkumar Patel
Date: February 2, 2020
Prof: Fahringer, Daniel
Prog: Coin Specification
      File(Header)
************************/
#ifndef UPCOIN_H
#define UPCOIN_H

#include<iostream>
#include<string>
using namespace std;

class UPCoin
{
	private:
		int year;						// Year: Coin was minted
		int quant;						// Quantity on hand of the coin
		double faceVal;					// Original Value of the Coin
		double marketVal;				// Current  Value of the Coin
		string description;				// Description of the coin
		
	public:
		UPCoin()
		{cout << "Coin Created" << endl; }	// Default Constructor
		~UPCoin()
		{cout << "Coin Destroyed" << endl;}	// Default Destructor
		
										// ******Mutators*******
		static double totalVal;			// STATIC totalVal
		void setYear(int);				// Sets the Year
		void setQuant(int);				// Sets the Quantity
		void setFaceVal(double);		// Sets the Face-Value
		void setMarketVal(double);		// Sets the Market-Value
		void setDescription(string);	// Sets the Description		
		
										// ******Accessors*******
		int    getYear();				// Gets Year
		int    getQuant();				// Gets Quantitiy
		double getFaceVal();			// Gets Face-Value
		double getMarketVal();			// Gets Market-Value
		string getDescription();		// Gets Description
		static double getTotalVal();	// Gets STATIC totalVal
		
		double difference();			// FaceVal - MarketVal
		
		static void init()				// Static Resetter
		{ totalVal = 0;
		}	
};

#endif
