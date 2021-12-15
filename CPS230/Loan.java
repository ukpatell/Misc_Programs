/***************************
Name: Umangkumar Patel
Date: December 7, 2019
Prof: Fahringer, Daniel
Prog: Buy A Car Calculator
***************************/
import javax.swing.JOptionPane;
import java.lang.Math;
import java.text.DecimalFormat;   
import java.io.FileOutputStream;
import java.io.PrintWriter;

public class Loan
{
                                                                                             // Variables
      private static double principle,interest,i;
      private static int    years,payments,tP;
      private static double monthlyAmount;
      private static PrintWriter writer;
      private static DecimalFormat df; 
      private static int page = 0;
      private static double intTotal = 0.0;
      public static void main(String[] args) throws Exception
      {
  
         getInput();                                                                       // Method to get the input
         computeMonthly();                                                                 // Method to compute monthly amount
         createWriter();                                                                   // Method to create writer
         createHeader();                                                                   // Method to write header to file
         outputData();                                                                     // Method to write data   to file
         JOptionPane.showMessageDialog(null,"Please Open Output.txt..", "Output Successfull",JOptionPane.INFORMATION_MESSAGE); // Display Done. Message
      }
      public static void getInput()
      {                                                                                    // Input
         principle = Double.parseDouble(JOptionPane.showInputDialog(null,"Enter Principle"));
         interest  = Double.parseDouble(JOptionPane.showInputDialog(null,"Enter Interest "));
         years     = Integer.parseInt(JOptionPane.showInputDialog(null,"Enter Years"));
         payments  = Integer.parseInt(JOptionPane.showInputDialog(null,"Enter Payments"));
         
      }
      public static void computeMonthly()
      {
         // Calculation
         df = new DecimalFormat("0.00  ");                                                // Decimal Format Setter
         interest /= 100;                                                                 // Convert Interest
         i = interest / payments;                                                         // Monthly Interest
         tP = years * payments;                                                           // Total # of Payments
         double r = Math.pow(1+i,tP);                                                     // Compute ***
         monthlyAmount =((principle * i * r)/(r-1));                                      // Compute Am.Mount
         monthlyAmount = Math.round(monthlyAmount * 100.0) / 100.0;                       // Round Two Decimals
      }
      public static void createWriter() throws Exception
      {
         writer = new PrintWriter("Output.txt", "UTF-8");                                 // Create Writer
      }
      public static void createHeader()
      {                                                                                   // Header(Title)
         writer.println("\t\t\t\t\tAuto Loan Payment Table");
         writer.println();
         writer.println("-----------------------------------------"+
                        "-----------------------------------------"+
                        "-----------------------------------------");                     // Data Header(Sub-title)
         writer.println("Pricipal= $ " + principle +
                        "\tAnnual Rate= " + interest + " %" +
                        "\tTotal Payments= " + payments + 
                        "\tPayment Amount= $ " + monthlyAmount +"\n");
         writer.println();
         writer.println();
         writer.println("Month\tPrincipal\t\tInterest Payment\tPrincipalPay\tEnding Balance\n\n"); // Column Title
         writer.println("-----------------------------------------"+
                        "-----------------------------------------"+
                        "-----------------");
         page++;                                                                          // Increment Page Count
      }
      public static void outputData() throws Exception
      {
         Double P = principle,I,PP,EP;
         for(int n = 1; n <= tP; n++)                                                     // Continue to end of payment
         {
              I  = P * i;                                                                 // Calculate Interest
                 /**/I  = Math.round(I * 100.0) / 100.0;                                  // Round
                     intTotal += I;
              PP = monthlyAmount - I;
                 /**/PP = Math.round(PP * 100.00) / 100.00;                               // Round
              EP = P - PP;
                 /**/EP = Math.round(EP * 100.00) / 100.0; 
              if(n == tP)
                  EP = 0.00;
              writer.println(n+"\t$ "+ df.format(P) + "\t\t$ " + df.format(I) + "\t\t$ " + df.format(PP) + "\t\t$ " + df.format(EP));
              P = EP;                                                                     // Set the EP to Priciple
              if(n % 24 == 0 && n!= tP)                                                   // Page Count Display
              {   
                      writer.println("-----------------------------------------"+
                        "------Page " + page +"--------------------------------"+
                        "----------");
                      writer.println();
                       createHeader();                                                    // Call to CreateHeader
              }
              else if(n == tP)                                                            // Last Accumulative Total of Interest
              {
                       intTotal = Math.round(intTotal * 100.0) / 100.0;
                       writer.println();
                       writer.println("\t\t\t\tTotal Interest Paid: $ " + intTotal);
                       writer.println("-----------------------------------------"+
                        "------END------------------------------"+
                        "----------");
              }
              
         }
         writer.close();                                                                // Close the writer 
      }
}