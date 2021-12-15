/***************************
Name: Umangkumar Patel
Date: October 27, 2019
Prof: Fahringer, Daniel
Prog: Inheritance
      Circle   (Sub. Point) 
      Cylinder (Sub. Circle)
****************************/
public class Cylinder extends Circle 
{
   protected double height;  
   
   public Cylinder()                                        // Default Constructor
   {
      setHeight( 0 );                                       // Default Height (Implicit)
   }

   public Cylinder(double cHei,double cRad,int xC,int yC)   // Constructor w. Super Point w. Parameters
   {
      super(cRad, xC, yC);                                  // Super goes first
      setHeight(cHei);                                      // Set Height for Cylinder
   }

   public void setHeight( double cHeight )                  // Height Setter   
   { 
      height = cHeight;
   }
   
   public double getHeight()                                // Height Getter
   {
      return height; 
   }
   
   public double calcSurfaceArea()                          // Surface Area Calculation
   {
      return (2 * super.calcArea() + 2 * Math.PI * radius * height);
   }
   
   public double calcVolume()                               // Volume Calculation
   { 
      return (super.calcArea() * height); 
   }
 
   public String toString()                                 // toString
   {
      return (super.toString() + 
              "\n Height                 " + height +
              "\n Volume                 " + calcVolume() +
              "\n Surface Area           " + calcSurfaceArea());    
   }
}