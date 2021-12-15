//
//  main.cpp
//  UPHash
//
//  Created by Umangkumar Patel on 4/11/20.
//  Copyright © 2020 Umangkumar Patel. All rights reserved.
//
#include <iostream>
#include "UPHash.h"
#include "UPHash.cpp"
#include <fstream>
#include <string>
using namespace std;

void menu();                // Menu Function
int main()
{
    
    string line;                        // File Function
    string IDCode = "";
    string name = "";                 // Variables
    double quantity;
    double price;

    ifstream myFile ("/Users/jayswaminarayan/Desktop/xCPP/xCode/UPHash/C162P7candy.txt");   // File Path
    if (myFile.is_open())
    {
      while (!myFile.eof())
      {
          UPHash c;
        
          IDCode = line;                 // Equals to ID_Code
          getline(myFile,line);
          name=line;               // Equals to Name
          getline(myFile,line);
          quantity=atof(line.c_str()); // Converts String to Integer & Equals
          getline(myFile,line);
          price=atof(line.c_str());    // Converts String to Double & Equals
          
          c.insert(IDCode,name,quantity,price);              // Function for adding structure to Array
      }
      myFile.close();
    }

    else cout << "Unable to open file";
    
    menu();
    return 0;
}
void menu()
{
    int c;
    do
    {
        system("cls");                                          // Clears the Screen
        system("color f3");                                     // Color Change
        cout << "\n\t\t\tCandy Factory Point-Of-Sale System";   // Title
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        cout << "Available Commands:\n\t";                      // Commands
        cout << "1. Check Availability\t2. Purchase\n\t";
        cout << "3. Delivery          \t4. Inventory Report\n\t";
        cout << "5. Exit\n\n";
        cout << "Command #: ";
        cin >> c;
        
    }while(c != 5);                                             // Termination Value
    cout << "~~~~~~~~~~~~~~~~~~~\n";                            // Termination Message
    cout << "Exited Successfully\n";
    cout << "~~~~~~~~~~~~~~~~~~~\n";
    
    
    
}
void available()
{
    
}
void purchase()
{
    
}
void delivery()
{
    
}
void inventory()
{
    
}

