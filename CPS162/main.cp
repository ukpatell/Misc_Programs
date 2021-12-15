/******************************************************************************
Name: Umangkumar Patel
Date: February 23, 2020
Prof: Fahringer, Daniel
Prog: Double Fibonacci
      Sequence
*******************************************************************************/
#include "UPDoubleFibClass.h"
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    UPDoubleFibClass fib;                       // Creates Object
    int choice,num1,num2,s;                     // Local Variables
    
    system("color f3");                         // Color Change
    fib.menu();
    
    while(true)                                 // Loop
    {
        cout << "\n\tEnter Option:\t";
        cin >> choice;                          // Choice from Menu
        
        switch(choice)
        {
            case 1:
                {
                cout << "Enter Number #1: ";
                cin  >> num1;
                cout << "Enter Number #2: ";
                cin  >> num2;
                cout << "Enter Sequence#: ";
                cin  >> s;
                if(s <= 2)
                { cout << "ERROR: Sequence Must Be Greater Than 2\n"; break;}
                fib.create(num1);               // Input Numbers
                fib.create(num2);
                for(int i = 2; i < s;i++)          // Loop Sequence
                {
                    int newNum = (num1 * 3) - num2;// Sequence Formula
                    fib.create(newNum);
                    num1 = num2;
                    num2 = newNum;
                }
                cout << "Sequence Created Succesfully...\n";
                system("PAUSE");
                system("cls");
                fib.menu();
                break; }
            case 2:
                cout << "Printing the List....." << endl;
                fib.display();
                system("PAUSE");
                system("cls");
                fib.menu();
                break;
            case 3:
                {
                cout << "\nEnter Number To Search/Count: ";
                int c;
                cin >> c;
                fib.checkCount(c);
                system("PAUSE");
                system("cls");
                fib.menu();
                break;
                }
            case 4: 
                {
                cout << "\nEnter Number For Prior: ";
                int p;
                cin >> p;
                fib.numBefore(p);
                system("PAUSE");
                system("cls");
                fib.menu();
                break;
                }
            case 5:
                {
                cout << "\nEnter Number For After: ";
                int a;
                cin >> a;
                fib.numAfter(a);
                system("PAUSE");
                system("cls");
                fib.menu();
                break;
                }
            case 6:
                cout << "\nEnter A Number to Delete: ";
                int d;
                cin >> d;
                fib.del(d);
                system("PAUSE");
                system("cls");
                fib.menu();
                break;
            case 7:
                cout << "Exiting The Program...\n";
                exit(0);
            default:
                cout << "Invalid Input!\n";
        }
        
    }
    
    return 0;
}

