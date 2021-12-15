/**********************
Name: Umangkumar Patel
Date: November 8, 2019
Prof: Fahringer, Daniel
Prof: Exception Payroll
      Test Program
**********************/
import java.io.*;
import javax.swing.*;

public class PayRollTest
{
   public static void main(String[] args)
   {
      //***********************Default*************************//
      
      Payroll pay = new Payroll("Umang", 1234);
      pay.setPayRate(12);
      pay.setHoursWorked(40);
      JOptionPane.showMessageDialog(null,pay);
      
      //*****************No_Parameters_Exception_Test**********//
      try{ Payroll pay1 = new Payroll(); }
      catch( Exception e) {JOptionPane.showMessageDialog(null,e.getMessage(),"Warning: Payroll()",JOptionPane.ERROR_MESSAGE); }
      
      //*****************No_Name_______Exception_Test**********//
      try{   pay.setName(""); }
      catch( Exception e ) { JOptionPane.showMessageDialog(null,e.getMessage(),"Warning: setName()",JOptionPane.ERROR_MESSAGE);}
      
      //*****************InvalidID_____Exception_Test**********//
      try {  pay.setIdNumber(0); }
      catch (Exception e) { JOptionPane.showMessageDialog(null,e.getMessage(),"Warning: setID(0)",JOptionPane.ERROR_MESSAGE); }
      
      //*****************HoursWorked___Exception_Test**********//
      try {  pay.setHoursWorked(-1); }
      catch (Exception e) { JOptionPane.showMessageDialog(null,e.getMessage(),"Warning: setHoursWorked(-1)",JOptionPane.ERROR_MESSAGE); }
      
      //*****************PayRate  _____Exception_Test**********//
      try {  pay.setPayRate(26); }
      catch (Exception e) { JOptionPane.showMessageDialog(null,e.getMessage(),"Warning: setPayRate(26)",JOptionPane.ERROR_MESSAGE); }
      
      
      
    }
}
