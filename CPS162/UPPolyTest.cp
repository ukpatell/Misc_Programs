/***********************
Name: Umangkumar Patel
Date: February 9, 2020
Prof: Fahringer, Daniel
Prog: Polynomials 
      Driver Program
***********************/
#include "UPPolynomials.h"
#include<iostream>
using namespace std;

int main()
{
    int choice;                         // Choice Variable for Menu
	UPPolynomials p1,p2;                // Objects for 2 Polynomials
	p1.in1();                           // Call Input for Polynomial #1
	p2.in2();                           // Call Input for Polynomial #2
    
    
    p1.menu();                          // Display Menu
    do 
    {
        cout << "Choice......:   ";
        cin  >> choice;                     // Input Choice
        switch(choice)
        {
            case 1:
                p1.showPoly(1);             // Displays Polynomials 1
                system("PAUSE");
                system("CLS");
                p1.menu();
                break;
            case 2:
                p2.showPoly(2);             // Displays Polynomials 2
                system("PAUSE");
                system("CLS");
                p1.menu();
                break;
            case 3:
                p1.addPoly(1);
                system("PAUSE");
                system("CLS");
                p1.menu();
                break;
            case 4:
                p2.addPoly(2);
                system("PAUSE");
                system("CLS");
                p1.menu();
            case 5:
                // Missing SUM CODE
                cout << "Unable to execute.\n";
                system("PAUSE");
                system("CLS");
                p1.menu();
                break;
            case 6:
                // Missing DIFF CODE
                cout << "Unable to execute.\n";
                system("PAUSE");
                system("CLS");
                p1.menu();
            case 7:
                p1.multiply();
                system("PAUSE");
                system("CLS");
                p1.menu();
            case 8:
                cout << "Exiting the program...\n"; // Exiting the program
                exit(0);
                break;
            default:
                cout << "Invalid Choice.\n";        // Default Exit/Choice
                system("PAUSE");
                system("CLS");
                p1.menu();
                break;
        }   
    }while(choice != 8);
	return 0;
}
