/***********************************
Name : Umangkumar Patel
Date : September 5, 2019
Proff: Daniel, Fahringer
Class: Object-Oriented Programming
Progr: Back in the Saddle
***********************************/


import java.util.*;

public class Matrice
{ 

//**********************MAIN**FILE****************************************//
   public static void main(String[] args)
   {
      
      int rows=0,columns=0;
      
      
      Scanner input = new Scanner(System.in);
      for(int m = 1; m <= 5; m++)
      {
         do
         {
            System.out.println(m + ") Rows: ");
            rows = input.nextInt();

            System.out.println(m + ") Columns: ");
            columns = input.nextInt();
            
         }while(rows < 1 || rows > 6 || columns < 1 || columns > 6);  // Out of Range Validation

         int[][] matrix = new int[rows][columns];
      
         System.out.println( m + " Matrice Number: ");
         for(int x = 0; x < rows; x++)
         {
            for(int y = 0; y < columns; y++)
            {
               matrix[x][y] = input.nextInt();
            }
         }
         System.out.println("Matrix: ");
         for(int i = 0; i < rows; i++)
         {
            for(int j = 0; j < columns; j++)
            {
               System.out.print(matrix[i][j]+"\t");
            }
            System.out.println();
         }   
         saddlePoint(matrix);
      }
      System.out.println("Thank You for Using Saddle 1.0");
   }

//********************RESIDED*****CLASS***********************************//
   static void saddlePoint(int[][] matrix)
   {
      for(int i = 0; i < matrix.length; i++)
      {
         int rowMax = matrix[i][0]; // Based on the row, max numbers for the array
         int colIndex = 0;
         boolean thisSaddlePoint = true;
      
         // Find the largest number in the row(ith)
      
         for(int j = 1; j < matrix[i].length; j++)
         {
            if(matrix[i][j] >  rowMax)
            {
               rowMax = matrix[i][j];
               colIndex = j;
            }
         }
      
         // Find if rowMax is also the largest number in its coloum
      
         for(int j =0; j < matrix.length; j++)
         {
            if(matrix[j][colIndex] > rowMax)
            {
               thisSaddlePoint = false;//Once it find its, it will break it
               break;
            }
         }
      
         if(thisSaddlePoint)
            System.out.println("Saddle Point: " + rowMax);

       }
    }
}
    
    