/***********************************
Name : Umangkumar Patel
Date : August 28, 2019
Proff: Daniel, Fahringer
Class: CPS 161 _II
Progr: ReviewJava Problem 46
       Cylinder Calculation
       CLASS FILE
***********************************/
public class Cylinder
{
      //Instance Variables
      private double radius=0;
      private double height=0;
      private double surfArea=0;
      private double volume=0; 

      public Cylinder() // Default Constructor with no paramaters
      {
         System.out.println("Construcator has been called");
      }
      public Cylinder(double radius, double height) //Input Constructor
      {
         this.radius = radius;
         this.height = height;
      }
      //************************Get**Methods*************************//
      public double getRadius()
      {
         return radius;
      }
      public double getHeight()
      {
         return height;
      }
      //************************Set**Methods**************************//
      public void setRadius(double radi)
      {
         radi = radius;
      }
      public void setHeight(double heigh)
      {
         heigh = height;
      }
      /*************************Calculation***************************/
      public double SurfaceArea()
      {
         double surfArea = (2 * 3.14159 * radius * height) + (2 * 3.14159 * radius *radius); // Formula
         return surfArea;
      }
      public double Volume()
      {
         double volume = 3.14159 * radius * radius * height;
         return volume;
      }
      public String toString()
      {
         return "Cylinder [Radius: " + radius + " Height: "+ height +"]";
      }
}
      
      