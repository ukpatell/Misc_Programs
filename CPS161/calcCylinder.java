/***********************************
Name : Umangkumar Patel
Date : August 28, 2019
Proff: Daniel, Fahringer
Class: CPS 161 _II
Progr: ReviewJava Problem 46
       Cylinder Calculation
***********************************/

public class calcCylinder
{
   public static void main(String[] args)
   {
      Cylinder cylinder = new Cylinder(1,1); // Create an object with radius and height
      System.out.println("Volume      : " + cylinder.Volume());
      System.out.println("Surface Area: " + cylinder.SurfaceArea());
      System.out.println(cylinder.toString());
   }  
}