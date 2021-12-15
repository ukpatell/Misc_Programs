/***********************************
Name : Umangkumar Patel
Date : September 8, 2019
Proff: Daniel, Fahringer
Class: CPS 161- II
Progr: Temperature Conversion
	   (Fahrenheit to Celsius)
***********************************/

#include<iostream>
using namespace std;

int main()
{
	double temp,celcius; // declares the variables
	
	cout << "\tTemperature Conversion" << endl; // title 
	cout << "\t______________________" << endl;
	cout << endl;
	cout << "\tEnter temperature in Farenheit(Press -1 to exit)"<<endl; // Instructions and exit methods for the user
	cout << "\t------------------------------------------------" << endl;
	cout << endl;

	cout << endl;
	while(temp  != -1) // revoke method keeps asking until presed
	{	
		cout << "\tFahrenheit: ";
		cin >> temp; 													// user input
		celcius = (5.0/9.0) * (temp - 32.0);							// formula for conversion
		cout << "\t"<< temp << " degrees Fahrenheit = " 
			 << celcius << " degrees Ceclsius" << endl;					// display the results
		cout << endl;
	}
	cout << "Thank you for using Temperature 1.0";						// display when finished
	return 0;
}
