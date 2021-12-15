#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
using namespace std;


double length,width,height;		// Global Variables
double diameter, jHeight;		// ................
double clearance = 0.25;		// Default clearance

//void decFormat(double,double,double,double,double);
bool checkUp(double,double,double,double,double);

int main()
{
	double num;					// number to read the file
	int tempCount = 0;
	ifstream inFile;			// create file object (Reading)
	ofstream outFile;			// create file object (Output)
	
	inFile.open("P4Boxes.txt");
	outFile.open("Output.txt");
	outFile << "Length\tWidth\tHeight\tDiameter\tJHeight\tFits?\n\n"; 
	while(inFile >> num)
	{
		tempCount++;
		
		switch(tempCount)
		{
			case 1:
				length = num;
				break;
			case 2:
				width = num;
				break;
			case 3: 
				height = num;
				break;
			case 4:
				diameter = num;
				break;
			case 5:
				jHeight = num;
				checkUp(length,width,height,diameter,jHeight);
				//decFormat(length,width,height,diameter,jHeight);
				if(checkUp(length,width,height,diameter,jHeight) == true)
				{
					outFile << setprecision(1) << fixed;
					outFile<<  length << "\t" << width << "\t" << height << "\t" <<diameter << "\t\t" << jHeight << "\tFits\n";
				}
				else
				{
					outFile<<length << "\t" << width << "\t" << height << "\t" <<diameter << "\t\t" << jHeight << "\tDoesn't Fit\n";
				}
				tempCount = 0;
				break;		
		}
		
	}
	inFile.close();
	cout << "Data Saved Successfully! (Output.txt)\n";
	outFile.close();

}
bool checkUp(double len, double wid, double hgt, double dia, double jhgt)
{
	len = len - clearance;
	wid = wid - clearance;
	hgt = hgt - clearance;
	
	if(jhgt < len && dia < wid && dia < hgt)
		return true;
	if(jhgt < hgt && dia < len && dia < wid)
		return true;
	if(jhgt < wid && dia < len && dia < hgt)
		return true;
	else
		return false;
}

