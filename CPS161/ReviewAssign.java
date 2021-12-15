/***********************************
Name : Umangkumar Patel
Date : August 28, 2019
Proff: Daniel, Fahringer
Class: CPS 161 _II
Progr: ReviewJava Problem 45
       Cylinder Calculation
***********************************/

import java.util.Scanner;

public class ReviewAssign
{
   public static void main(String[] args)
   {
      double[] sales = new double[10];
      int index;
      double largestSale = 0,sum = 0,average = 0;
      double smallestSale =0;
      Scanner input = new Scanner(System.in);
      
      for(int i=0; i < sales.length; i++)
      {
         sales[i] = 0; // Initializes the values of the array to 0 [A]
      }
      
      for(int i=0; i <sales.length;i++)
      {
         System.out.println("Sale " + (i+1) + " : ");
         sales[i] = input.nextDouble(); //Reads and stores the input in an array [B]
      }
      
      for(int i= sales.length-1; i > -1; --i)
      {
         System.out.println(sales[i]); // Prints the array list in reverse [C]
      }
      
      
      for(int i = 0; i < sales.length; i++)
      {
        
         sum = sum +sales[i]; // Calculates the sum [D]
         average = sum/sales.length; // Calculates the average
        
         
         if(largestSale <= sales[i])
            largestSale = sales[i];// Calculates the Largest            
      }
      
      smallestSale = largestSale; // resets the value of smallestSale
      
      for(int i = 0; i< sales.length; i++)
      {
         if(smallestSale >= sales[i]) // Calculates the smallest
            smallestSale = sales[i];
      }
      
      System.out.println("Sum : " + sum + "Average: " + average);
      System.out.println("Largest: " + largestSale);   
      System.out.println("Smallest: " + smallestSale);  
   }
}