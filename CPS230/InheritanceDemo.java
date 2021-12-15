/***************************
Name: Umangkumar Patel
Date: October 27, 2019
Prof: Fahringer, Daniel
Prog: Inheritance
      Demo Class
****************************/
import javax.swing.JOptionPane;

public class InheritanceDemo 
{
   public static void main( String args[] )
   {
      Point point       = new Point(5,2);                         // ................X..Y..     
      Circle circle     = new Circle(4,6,2);                    // ........Radius..X..Y..
      Cylinder cylinder = new Cylinder(7,4,8,7);                  // Height..Radius..X..Y..

      String output;
      
      output = "\n             Point(Section)\n" +
               point.toString() 
             +"\n\n            Circle(Section)\n" +
             circle.toString() + "\n\n            Cylinder(Section)\n"  +
             cylinder.toString();


      JOptionPane.showMessageDialog( null, output,
         "Inheritance",
         JOptionPane.INFORMATION_MESSAGE );

      System.exit( 0 );
   }

}  // end class Test
