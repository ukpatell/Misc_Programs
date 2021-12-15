/***********************************
Name : Umangkumar Patel
Date : September 15, 2019
Proff: Daniel, Fahringer
Class: CPS I 161
Progr: Assignment #2
	   Co-Ordinates:
	   Distance & Midpoint Calculator
***********************************/

#include<iostream>
#include<stdlib.h>
#include<cmath>							// Math Library
#include<unistd.h>
using namespace std;

void intro();							// Instructions / Intro
void getCo();							// Gets Co-Ordinates from User
int calcDistance(int,int,int,int);		// Calculates Distance
int calcMidpoint(int,int,int,int);		// Calculates MidPoint
void displayP();							// Display

int x,y,xx,yy;							// Co-Ordinates
int main()
{
	unsigned int sleep(unsigned int seconds);		// Pauces the system for # seconds
		system("Color 09");
	intro();
		system("Color 05");
		sleep(2);
	getCo();
		system("Color 06");
		cout<<"Calculating the distance...\n";
		sleep(2);
	calcDistance(x,y,xx,yy);
		system("Color 02");
		cout<<"Calculating the midpoint...\n";
		sleep(2);
	calcMidpoint(x,y,xx,yy);
		sleep(2);
		system("color A5");
	displayP();
	return 0;
}

void intro()
{
	cout << "Instructions: \n";
	cout << "\tEnter Co-Ordinates and it will calculate\n";
	cout << "\tDistance and Mid-Point between given points\n";
}

void getCo()
{	
	cout<<"\tEnter X1:\t";
	cin >> x;
	cout<<"\tEnter Y1:\t";
	cin >> y;
	cout<<"\tEnter X2:\t";
	cin >> xx;
	cout<<"\tEnter Y2:\t";
	cin >> yy;	
}

int calcDistance(int x, int y, int xx, int yy)
{
	double pair1 = pow((xx-x),2);
	cout<<pair1;
	double pair2 = pow((yy-y),2);
	cout<<pair2;
	double distance = sqrt(pair1+pair2);
	system("CLS");
	cout <<endl;
	cout<<"\tDistance: \t" << distance << endl;
}
int calcMidpoint(int x, int y, int xx, int yy)
{
	double pair1 = (x + xx) / 2.0;
	double pair2 = (y + yy) / 2.0;
	cout<<endl;
	system("color 07");
	cout<<"\tMidpoint: \t( " << pair1 << " ," << pair2 << " )" << endl;
}
void displayP()
{
	cout << "\tPoints: \t("<<x<<" , " <<y << " )\t("
	     << xx << " , " << yy << " )\n";
}
