/***********************
Name: Umangkumar Patel
Date: October 27, 2019
Prof: Fahringer, Daniel
Prog: Inheritance
      Circle (Sub. Point) 
************************/
class Circle extends Point
{
   protected double radius;                     
   
   public Circle()                                        // Default Constructor
   {
      setRadius(0);                                       // Default Radius (Implicit)
   }

   public Circle(double cRadius, int xCoordinate, int yCoordinate) // Constructor w. Super Point w. Parameters                              
   {
      super(xCoordinate, yCoordinate);                    // Super goes first
      setRadius(cRadius);                                 // Sets the Radius
   }

   public void setRadius(double cRadius)                  // Set Radius of Circle
   { 
      radius = cRadius;
   }

   public double getRadius()                              // Get Radius of Circle
   { 
      return radius;                                        
   }

   public double calcArea()                               // Calculate Area
   { 
      return Math.PI * radius * radius; 
   }
   
   public double calcCircumference()                      // Calculate Area
   { 
      return (2 * Math.PI * radius); 
   }
   
   public String toString()                               // toString
   { 
      return super.toString()   + 
           "\n Radius                 " + radius             +
           "\n Area                   " + calcArea()         +
           "\n Circumference     " + calcCircumference();
   }
}