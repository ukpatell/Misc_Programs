/***********************************
Name : Umangkumar Patel
Date : September 8,2019
Proff: Daniel, Fahringer
Class: Object Oriented Programming
Progr: Sonnett 18
       Read the File,gives freq. 
       alphabets(11)
***********************************/

import java.util.*; // Scanner Class
import java.io.*;   // Throw I/O Exception
import java.io.BufferedReader;
import java.io.FileReader;

public class Sonnet
{
   public static void main(String args[]) throws IOException
   {
         
      //File       myFile = new File("file.txt");                  // Instance of File Input
      
      /*if(!myFile.exists())                                           // Checks if the file exists before opening
      {
         System.out.println("File Not Found");
         System.exit(0);
      }*/
      
      //Scanner inputFile = new Scanner(myFile);                       // Passing reference to object as source of input to Scanner constructor
      BufferedReader br = new BufferedReader(new FileReader("file.txt"));
      StringBuilder  sb = new StringBuilder();
      
      String line = br.readLine();
      while(line != null)
      {
         sb.append(line);
         line = br.readLine();
      }
      String oneLine = sb.toString();
      //System.out.println(oneLine);                                   Display to check the one line
      
      //while(inputFile.hasNext())                                     // Reads the file till the end
      //{        
            //String line = inputFile.nextLine();                      // Gets a line from the text file
            String noPLine = oneLine.replaceAll("[\\W]", "");           // (\\W -- Non-Word Characters) and White Space gets removed
            String finline = noPLine.toLowerCase();                  // takes the previous line and converts the alpha to lower-case
            System.out.println(finline);                             // Display to check the results
   
                        
           //static final int MAX_CHAR = 256;                         // MAX characters ASCII

            int count[] = new int[256]; 
  
            int len = finline.length(); 
  
            // Initialize count array index 
            for (int i = 0; i < len; i++) 
               count[finline.charAt(i)]++; 
  
               // Create an array of given String size 
               char ch[] = new char[finline.length()]; 
               for (int i = 0; i < len; i++) 
               { 
                  ch[i] = finline.charAt(i); 
                  int find = 0; 
                  for (int j = 0; j <= i; j++) 
                  { 
                     // If any matches found 
                     if (finline.charAt(i) == ch[j])  
                        find++;                 
                  } 
  
                  if (find == 1)  
                  System.out.println("Number of Occurrence of " + 
                  finline.charAt(i) + " is:" + count[finline.charAt(i)]);   
               }    
      //}        
      //inputFile.close();                                             // Closes the File
   }
   
}

/*******************
Program Incomplete
: Only Gets the occurances of the alphabets
********************/