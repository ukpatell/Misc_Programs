/**
	Payroll class
	Chapter 6, Programming Challenge 5
*/

public class Payroll 
{
   private String name;          // Employee name
   private int idNumber;         // ID number
   private double payRate;       // Hourly pay rate
   private double hoursWorked;   // Number of hours worked

   /**
   	The constructor initializes an object with the
		employee's name and ID number.
		@param n The employee's name.
		@param i The employee's ID number.
   */
   public Payroll()                                 // Exception: Empty Parameters 
   {
      throw new RuntimeException("Blank Input. <string>Name, <int>Employee ID Required."); 
   }
   public Payroll(String n, int i) 
   {
      if(n == null)                                 // Exception: Name is Empty 
            throw new IllegalArgumentException("Invalid Input. Employee Name Field Cannot Be Empty.");
      else
            name = n;
       
      if(i <= 0)                                    // Exeption:  ID   is Negative or 0/ String
         throw new IllegalArgumentException("Invalid Input. Employee ID must be > 0(Numeric).");
      else
           idNumber = i;                            
   }

   /**
   	The setName sets the employee's name.
		@param n The employee's name.
   */

   public void setName(String n)
   {
       if(n.length() == 0)                          // Exception: Name is Empty
         throw new RuntimeException("Invalid Input. Name Field Cannot Be Empty.");
      else
            name = n;
   }

   /**
   	The setIdNumber sets the employee's ID number.
		@param i The employee's ID number.
   */
	
   public void setIdNumber(int i)
   {
      if(i <= 0)                                    // Exeption:  ID   is Negative or 0/ String
         throw new IllegalArgumentException("Invalid Input. Employee ID must be > 0(Numeric).");
      else
         idNumber = i;
   }

   /**
   	The setPayRate sets the employee's pay rate.
		@param p The employee's pay rate.
   */
	
   public void setPayRate(double p)
   {
      if(p < 0 || p > 25)                          // Exception:  PayRate is Negative or 25+
         throw new IllegalArgumentException("Invalid Input. Pay Rate must be (0-25).");
      else
         payRate = p;
   }

   /**
   	The setHoursWorked sets the number of hours worked.
		@param h The number of hours worked.
   */

   public void setHoursWorked(double h)
   {
      if(h < 0 || h > 84)                          // Exception:  Hours 0-84 is must
         throw new IllegalArgumentException("Invalid Input. Hours must be (0-84).");
      else
         hoursWorked = h;
   }

   /**
   	The getName returns the employee's name.
		@return The employee's name.
   */

   public String getName()
   {
      return name;
   }

   /**
   	The getIdNumber returns the employee's ID number.
		@return The employee's ID number.
   */
	
   public int getIdNumber()
   {
      return idNumber;
   }

   /**
   	The getPayRate returns the employee's pay rate.
		@return The employee's pay rate.
   */

   public double getPayRate()
   {
      return payRate;
   }

   /**
   	The getHoursWorked returns the hours worked by the
		employee.
		@return The hours worked.
   */


   public double getHoursWorked()
   {
      return hoursWorked;
   }

   /**
   	The getGrossPay returns the employee's gross pay.
		@return The employee's gross pay.
   */

   public double getGrossPay()
   {
      return hoursWorked * payRate;
   }
   public String toString()                           // Added toString
   {
      return "\nEmployee Payroll Data"+
         "\n\nName                : " + getName() +
           "\nID Number        : " + getIdNumber() +
           "\nHourly pay rate : " + getPayRate() +
           "\nHours worked   : " + getHoursWorked() +
           "\nGross pay         $ " +getGrossPay();
   }   
}

