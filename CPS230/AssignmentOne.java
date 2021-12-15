/***********************************
Name : Umangkumar Patel
Date : August 30, 2019
Proff: Daniel, Fahringer
Class: Object-Oriented Programming
Progr: Assignment One
***********************************/

import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class AssignmentOne 
{
   public static void main(String[] args)
    {
       char theta = '\u03F4'; // theta symbol generator

       // Creates the Textfield
       JTextField OppSide = new JTextField(); 
       JTextField AdjSide = new JTextField();
       
       // Displays the tenx input field for user
       Object[] print = {"Length of Opposite Side: ", OppSide,"Length of Adjacent Side: ", AdjSide }; 
       int option = JOptionPane.showConfirmDialog(null, print, "Right-Triangle Calculation", JOptionPane.OK_CANCEL_OPTION);

       if (option == JOptionPane.OK_OPTION)
       {
          String o = OppSide.getText(); // Gets the Opposite Side Length
          String a = AdjSide.getText(); // Gets the ADjacent Side Length
          double sum = Double.parseDouble(o)*Double.parseDouble(o) + Double.parseDouble(a)*Double.parseDouble(a);
          double h = Math.sqrt(sum);    // Calculate the Hypotenuse
           // Calculates / Prepares the Trig Values and Hypotenuse for display
          String result = "Hypotenuse: "+ h +" \n" + 
                          "Sin     " + theta + " :" + o + "/" +h+ "\n" +                      
                          "Cos     " + theta + " :" + a + "/" +h +"\n"+ 
                          "Tan     " + theta + " :" + o + "/" +a +"\n"+ 
                          "Csc     " + theta + " :" + h + "/" +0 +"\n"+
                          "Sec     " + theta + " :" + h + "/" +a +"\n"+ 
                          "Cot     " + theta + " :" + a + "/" +o +"\n";

          JOptionPane.showMessageDialog(null, result); // Displays the result w.u.o. MessageDialog
       } 
       else 
       {
          System.out.println("User has cancelled!"); // Displays if User hits cancel
       }
   }
}


