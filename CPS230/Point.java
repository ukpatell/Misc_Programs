/***********************
Name: Umangkumar Patel
Date: October 27, 2019
Prof: Fahringer, Daniel
Prog: Inheritance
      Point (Super) 
      Class
************************/
class Point
{
      protected int x, y;                                         // Coordinates of the Point
       
      public Point()                                              // Default Constructor
      { 
         setPoint( 0, 0 );                                        // Default Point (Implicit)
      }

      public Point( int xCoordinate, int yCoordinate )            // Constructor with Parameters
      { 
         setPoint( xCoordinate, yCoordinate );                    // Sets the Points
      }
      
      public void setPoint( int xCoordinate, int yCoordinate )    // Set X and Y Co-Ordinates for the Plane
      {
         x = xCoordinate;
         y = yCoordinate;
      }
  
      public int getX()                                           // Get X                                    
      { 
         return x; 
      }

   
      public int getY()                                           // Get Y
      { 
         return y; 
      }

      public String toString()                                    // toString
      { 
         return " Point:                   ( " + x + ", " + y + " )";
      }
} 