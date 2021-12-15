#include<iostream>
#include<windows.h>
#include<string>
#include<iomanip>
//#include<conio.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);										// Set Console
																						// Functions
void displayMenu();																		// * Displays Menu
void displayEmpty();																	// * Displays empty Seats
void displaySeats();																	// * Displays All-Seats (Numeric Order + Names)
void displayAssigned();																	// * Displays Assigned Seats Only (Alphabetical)
void assignSeat();																		// * Assigns a Seat
void cancelSeat();																		// * Cancels a Seat

int choice;																				// Global Variable for Choice
const int SEATS = 12;																	// Global Const Seats
struct Flight																			// Flight Structure
{
	int	   seatNum;
	bool   isAvailable = true;
	string fName = "";
	string lName = "";
};

Flight f[SEATS];																		// Name a Flight Structure
					
int main()																				// Main Function
{

	do
	{
		displayMenu();
	}while(choice != 6);
	
	system("cls");
	system("color f2");
	cout << "\n\tHave a nice day!\n\n";
	Sleep(500);
	return 0;
}
void displayMenu()
{
	SetConsoleTextAttribute(hConsole, 8);
	cout << "To Launch Menu, ";
	system("pause");
	do
	{
		system("cls");																	// Clearing the System
		SetConsoleTextAttribute(hConsole, 43);											// Add an attribute of Color
		cout << "\n\t\t   Welcome to Podunk Airlines\t\t\n";								// Title
		cout << "\t------------------------------------------------\n";					// Underline the Title
		SetConsoleTextAttribute(hConsole, 13);											// Change Color of text
		cout << endl;
																									
		cout << "\t1. Available Seats\t2. All       Seats\n";	
		SetConsoleTextAttribute(hConsole, 10);											// Change Color of text						
		cout << "\t3. Assigned  Seats\t4. Reserve   Seat \n";
		SetConsoleTextAttribute(hConsole, 13);											// Change Color of text
		cout << "\t5. Cancel    Seat \t6. Quit      Program\n\n";
		SetConsoleTextAttribute(hConsole, 11);											// Change Color of text
		cout << "\tEnter Your Selection: ";
		cin  >> choice;
		if(choice < 1 || choice > 6)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "\n\tInvalid Input...Try Again...!";								// Input-Validation Message
			system("pause");
		}
	}while(choice < 1 || choice > 6);													// Input-Validation
		
	switch(choice)																		// List of Choice/Functions
	{
		case 1:
			displayEmpty();
			break;
		case 2:
			displaySeats();
			break;
		case 3:
			displayAssigned();
			break;
		case 4:
			assignSeat();
			break;
		case 5:
			cancelSeat();
			break;
		default:
			choice = 6;
			break;
	}
}
void displayEmpty()																	// Display Empty Seats Function
{
	cout << "\n";
	int counter = 0;																// Counter to Count Seats
	SetConsoleTextAttribute(hConsole, 23);
	cout << "\tAvailable Seats\n"													// Title
		 << "\t---------------\n\n";
	SetConsoleTextAttribute(hConsole, 8);
	for(int i = 0; i < 12; i++)
	{
		if(f[i].isAvailable) 														// If the Seat(s) is Available, Proceed
		{
			cout <<"\t" << i+1 << endl;
			counter++;																// Increment Counter
		}
	}
	cout << "\tTotal Seats Available: " << counter << endl;							// Print 
	SetConsoleTextAttribute(hConsole, 11);											
	displayMenu();																	// HOME(Menu)
}
void displaySeats()																	// Display All Seats Function
{
	SetConsoleTextAttribute(hConsole, 23);
	cout << "\tSeating Chart\n"														// Title
		 << "\t-------------\n\n";
		SetConsoleTextAttribute(hConsole, 10);
	cout << "\tSeat" << setw(15) <<"First Name" 									// Header
		 << setw(15) << "Last Name\n\n";
	SetConsoleTextAttribute(hConsole, 8);
	for(int i = 0; i < SEATS; i++)
	{
		cout << setw(10) << i+1 << setw(15) 										// Print Each Element
			 << f[i].fName << setw(15)
			 << f[i].lName << endl;

	}
	displayMenu();																	// HOME(Menu)
}
void displayAssigned()
{
	Flight temp;																	// Create a Temp Struct V.
	SetConsoleTextAttribute(hConsole, 23);
	cout << "\tPassengers List\n"													// Title
		 << "\t---------------\n\n";
		SetConsoleTextAttribute(hConsole, 10);
	cout << "\tSeat" << setw(15) <<"First Name" 									// Header
		 << setw(15) << "Last Name\n\n";
	SetConsoleTextAttribute(hConsole, 8);
	for( int i=1; i< SEATS; i++ )													// Bubble Sort Algorithm
    {
    	for( int j=0; j < SEATS-1; j++)
    	{
        	if(f[j].fName > f[j+1].fName)
        	{
            	temp = f[j];
            	f[j] = f[j+1];
            	f[j+1] = temp;
        	}
		}
		if(f[i].seatNum != 0)														//If SeatNum != 0; Print
    	{
    		cout << setw(10) << f[i].seatNum  << setw(15) 
			 << f[i].fName << setw(15)
			 << f[i].lName << endl;
		}
	}
	displayMenu();																	// HOME(Menu)
}
void assignSeat()
{
	int s;													
	string sfName, slName;															// Variables
	SetConsoleTextAttribute(hConsole, 23);
	cout << "\tAssigning a Seat\n"													// Title
		 << "\t----------------\n\n";
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\tEnter Last  Name  : ";												// Ask User (Last Name)
	cin  >> slName;	
	cout << "\tEnter First Name  : ";												// Ask User (First Name)
	cin  >> sfName;
	
	do {
	cout << "\tEnter Seat  Number: ";
	cin  >> s;
	}while(!f[s-1].isAvailable);													// Loop Until, Enter Valid(Empty) Seat
	
	f[s-1].seatNum = s;																// Set the Seat  Number
	f[s-1].lName = slName;															// Set the Last	 Name
	f[s-1].fName = sfName;															// Set the First Name
	f[s-1].isAvailable = false;														// SEt the Status to False
	
	displayMenu();																	// HOME(Menu)
}
void cancelSeat()
{
	int s;
	int sNum;																		// Variables
	string sName;
	cout << "\n";
	SetConsoleTextAttribute(hConsole, 23);
	cout << "\tCancel a Seat Reservation\n"											// Title
		 << "\t-------------------------\n";
	cout << "\tCancel With    :\t" << "(0) Seat  Number\n"							// Ask User (Option)
		 << "\t                \t(1) First Name\n\n";
	SetConsoleTextAttribute(hConsole, 8);
	
	cout << "\tEnter Choice (0/1): ";										
	cin  >> s;																					
	
	switch(s)																		// According to choice....
	{
		case 0:
			cout << "\n\tEnter Seat Number: ";										// Seat #, is selected
			cin  >> sNum;
			if(sNum>0 && sNum<=12)
			{
				SetConsoleTextAttribute(hConsole, 23);
				cout << "\n\tSeat: " << sNum << " has been cancelled\n";			// Print
				f[sNum - 1].fName = "";												// Remove First Name
				f[sNum - 1].lName = "";												// Remove Last  Name
				f[sNum - 1].isAvailable = true;										// Set the Available to True
			}
			else
				cout << "\n\tInvalid Entry...";										// If Given Seat# is not valid
			break;
		case 1:	
			cout << "\nEnter Last Name: ";											// Name is selected
			cin >> sName;
			for(int i = 0; i < SEATS; i++)
			{	
				if(sName == f[i].fName)												// If F.Name Match is Found
				{
					cout << "\n\tSeat: " << i+1 << " has been cancelled\n";
					f[i].fName = "";												// Remove F
					f[i].lName = "";												// Remove L Name
					f[i].isAvailable = true;										// Set the Available to True
				}
			}
			break;
		default:
			displayMenu();															// HOME(Menu)
	}
	displayMenu();
}
