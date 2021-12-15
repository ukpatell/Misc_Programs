/***********************************
Name : Umangkumar Patel
Date : September 22, 2019
Proff: Daniel, Fahringer
Class: CPS I 161
Progr: Assignment #3
	   Salaries
	   Calculate Weekly Pay
	   base on Salary Code entered
***********************************/


#include<iostream>
#include<iomanip>
using namespace std;



double tempSalary;
double grossPay;
double tempTax;
double health	  = 27.85;
int Read_EmployeeID;		// Global Employee ID
int Salary_Code;			// Global salary Code

int	   countDigit(int);
double calcManager();
double calcTax();
double calcHealth();
double calcFactory(double);
double calcSales(int);
double calcPiece(int);
void displayResults();
void displayCode();	

int main()
{
	double hours;			// Input Hours
	int sales;				// Input Sales
	int widget;				// Input Widget
	int inputAgain;			// Rerun
	
	do
	{	
		system("color 08");
		system("CLS");									// Clears the screen, for Rerun
		do
		{	
			cout << "Employee ID(####): ";	
			cin >> Read_EmployeeID;						// Input Employee ID
		}while(countDigit(Read_EmployeeID) != 4);		// Employee Digit Input Validation
		
		displayCode();									// Display Salary Codes
		
		do
		{
			cout << "Salary Code: ";			
			cin >> Salary_Code;							// Input Salary Code
			
		}while(Salary_Code <  1 || Salary_Code > 4);	// Salary Code Input Validation
		
		switch(Salary_Code)								// According to Salary Code...
		{
			case 1:
				calcManager();							// Calculates Manager's Pay
				calcTax();								// Calcuates Tax based on ^
				calcHealth();							// Deducts Health, after Taxes have been cut
				break;
			case 2:
				cout << endl;
				cout << "Enter Hours: ";
				cin >> hours;							// Inputs Hours
				calcFactory(hours);						// Calculates Factory Worker's based on hours entered
				calcTax();								// calculates tax ^	
				calcHealth();							// Taxes off deductions
				break;
			case 3:	
				cout << endl;
				cout << "Enter # of Sales: ";			
				cin >> sales;							// Input sales
				calcSales(sales);						// calculates pay based on sales entered
				calcTax();								// calculates tax 
				calcHealth();							// Takes off health
				break;
			case 4:
				cout << endl;
				cout << "Enter # of Widgets: ";
				cin >> widget;							// Inputs widgets entered
				calcPiece(widget);						// Calculates pay based on widgets entered/produced
				calcTax();								// Calculates tax based on pay
				break;
		}
		
		system("CLS");
		displayResults();
		
		tempSalary = 0;
		
		cout<<endl;
		cout << "Input Again (0/1): ";
		cin >> inputAgain;
		
	}while(inputAgain != 0 );
	return 0;
}

int countDigit(int number) 
{
	int count =0;
	while (number != 0)
	{
		number = number / 10;
		++count;
	}
	return count;
} 
void displayCode()
{
	cout << endl;
	cout << "------Salary-Code(s)-------\n";
	cout << "Code 1:\tManager\n";
	cout << "Code 2:\tFactory Worker\n";
	cout << "Code 3:\tSales\n";
	cout << "Code 4:\tPieceworker\n";
	cout << "---------------------------\n";
}
double calcManager()
{
	tempSalary  = 51500 / 52;
    grossPay	= tempSalary;
    return tempSalary;
}
double calcTax()
{
	tempTax      = (grossPay * 0.19);
	tempSalary   = grossPay - tempTax;
	return tempTax;
}
double calcHealth()
{
	tempSalary = tempSalary - health;
	return health;
}
double calcFactory(double hours)
{
	 double rate = 13.85;
	 if(hours > 40)
	 {
		tempSalary = ((40 * rate) + ((hours - 40) * (rate * 1.5)));
		grossPay   = tempSalary;
       	return tempSalary;
	 }
	 else
	 {
		tempSalary = (hours * rate);
		grossPay = tempSalary;
       	return tempSalary;
	 }
}
double calcSales( int sales)
{
	 tempSalary = 250 + (0.057 * sales);
	 grossPay = tempSalary;
       return tempSalary;
}
double calcPiece(int widget)
{
	tempSalary = (11.30 * widget);
	grossPay = tempSalary;
       return tempSalary;
}
void displayResults()
{
	system("color a");
	system("CLS");
	cout << "Employee ID\t" << "Gross\t" << "\tTaxes\t\t" << "Deductions\t" << "Net\t" << endl;
	cout << "______________________________________________________________________________" << endl;
	switch(Salary_Code)
	{
	
		case 1:
			cout << Read_EmployeeID << fixed << setprecision(2) << "\t\t$" << grossPay << "\t\t$" << calcTax() << "\t\t$" << calcHealth() << "\t\t$" << tempSalary << endl;
			break;
		case 2: 
			cout << Read_EmployeeID << fixed << setprecision(2) << "\t\t$" << grossPay << "\t\t$" << tempTax << "\t\t$" << calcHealth() << "\t\t$" << tempSalary << endl;
			break;
		case 3:
			cout << Read_EmployeeID << fixed << setprecision(2) << "\t\t$" << grossPay << "\t\t$" << calcTax() << "\t\t$" << calcHealth() << "\t\t$" << tempSalary << endl;
			break;
		case 4:
			cout << Read_EmployeeID << fixed << setprecision(2) << "\t\t$" << grossPay << "\t\t$" << calcTax() << "\t\t$" << "0.00" << "\t\t$" << tempSalary << endl;
			break;
	}
}



