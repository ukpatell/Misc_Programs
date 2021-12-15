/***********************************
Name : Umangkumar Patel
Date : September 8,2019
Proff: Daniel, Fahringer
Class: CPS 161-II
Progr: Temperature Conversion[JAVA]
       Fahrenheit to Celsius
***********************************/

import java.util.*;

public class convertTemperature

{
   public static void main(String args[]) 
   {
      double temp =0,celcius; // declares the variables
	   Scanner input = new Scanner(System.in);         // input objext
      
      
	   System.out.println( "\tTemperature Conversion"); // title 
	   System.out.println( "\t______________________");
	   System.out.println();
	   System.out.println( "\tEnter temperature in Farenheit(Press -1 to exit)"); // Instructions and exit methods for the user
	   System.out.println( "\t------------------------------------------------");
	   System.out.println();

	   System.out.println();
	   while(temp  != -1) // revoke method keeps asking until presed
	   {	
	   	System.out.print( "\tFahrenheit: ");
	   	temp = input.nextDouble();
         											// user input
	   	celcius = (5.0/9.0) * (temp - 32.0);							// formula for conversion
	   	System.out.println( "\t"+ temp +" degrees Fahrenheit = " 
			     + celcius +" degrees Celsius");					// display the results
		   System.out.println();
	   }
	   System.out.println( "\tThank you for using Temperature 1.0");				// display when finished

   }

}