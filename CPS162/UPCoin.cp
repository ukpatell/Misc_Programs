/************************
Name: Umangkumar Patel
Date: February 2, 2020
Prof: Fahringer, Daniel
Prog: Coin Implementation
      File
************************/
#include "UPCoin.h"
#include<iostream>

double UPCoin::totalVal;
void UPCoin::setYear(int y)
{
	if(y < 1000 || y > 2020)
	{
		cerr << "Invalid Range. Year set to 2000" << endl;
		year = 2000;
	}
	else
		year = y;
}
void UPCoin::setQuant(int q)
{
	if(q < 0)
	{
		cerr << "Invalid Range. Quantity set to 100" << endl;
		quant = 100;
	}
	else
	{
		quant = q;
	}
}
void UPCoin::setFaceVal(double fVal)
{
	if(fVal >= 0)
	{
		faceVal = fVal;
	}
	else
	{
		cerr << "Invalid Value. Value set to $1.00" << endl;
		faceVal = 5.00;
	}
}
void UPCoin::setMarketVal(double mVal)
{
	if(mVal >= 0)
	{
		marketVal = mVal;
		totalVal += marketVal * quant;
	}
	else
	{
		cerr << "Invalid Value. Value set to $10.00" << endl;
		marketVal = 10.00;
	}
}
void UPCoin::setDescription(string d)
{
	if(d.length() > 0)
	{
		description = d;
	}
	else
	{
		cerr << "Invalid Data. Exiting the Program." << endl;
		exit(1);
	}
}

int UPCoin::getYear()
{
	return year;
}
int UPCoin::getQuant()
{
	return quant;
}
double UPCoin::getFaceVal()
{
	return faceVal;
}
double UPCoin::getMarketVal()
{
	return marketVal;
}
double UPCoin::getTotalVal()
{
	return totalVal;
}
string UPCoin::getDescription()
{
	return description;
}
double UPCoin::difference()
{
	if(faceVal >= marketVal)
	{
		return (faceVal - marketVal);
	}
	else
		return (marketVal - faceVal);
}
