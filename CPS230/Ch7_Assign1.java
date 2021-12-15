/************************************************
* Name   : Umang Patel
* Date   : September 15, 2019
* Program: Quaterback Revisit: User Friendly

/************************************************
* Student: 
* Date: 3/20/07
* Assignment Ch 7 #1
* Professor: Fahringer
*
*	This program will use dialog boxes to get
*	a quarterback's name, completed passes,
*	attempts, receiving yards, touchdowns, and
*	interceptions.  Using that data, I will
*	calculate statistics regarding the QB,
*	culminating in the QB rating.  This data,
*	along with the input, will be displayed in
*	a final dialog box.
*
**************************************************/


import java.util.*;
import java.lang.Math;      
import javax.swing.*;    
import java.text.DecimalFormat;            
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;
import javafx.scene.layout.BackgroundFill;

public class Ch7_Assign1 extends Application
{
     private TextField name              = new TextField();
     private TextField completedTemp     = new TextField();
     private TextField attemptsTemp      = new TextField();
     private TextField yardsTemp         = new TextField();
     private TextField touchdownsTemp    = new TextField();
     private TextField interceptionsTemp = new TextField();

   

     public static void main(String[] args)
     {
		   launch(args);
     }
     public void start(Stage primaryStage)
     {
         
         Label nameL  = new Label("Enter Name         ");
         Label cmptL  = new Label("Completed Passes   ");
         Label atmpL  = new Label("Attempted Passes   ");
         Label yardL  = new Label("Receiving Yards    ");
         Label tdwnL  = new Label("Enter Touchdowns   ");
         Label icpnL  = new Label("Intercepted Passes ");
     
         Button calculate = new Button("Calculate");
         calculate.setOnAction(new ButtonClickHandler());
         
         // Font for the input
         name.setStyle("-fx-text-inner-color: red");
         completedTemp.setStyle("-fx-text-inner-color: green");
         attemptsTemp.setStyle("-fx-text-inner-color: brown");
         yardsTemp.setStyle("-fx-text-inner-color: purple");
         touchdownsTemp.setStyle("-fx-text-inner-color: grey");
         interceptionsTemp.setStyle("-fx-text-inner-color: black");

         
         // Grid Pane
         GridPane gridPane = new GridPane();
                 
         gridPane.add(nameL,0,1);
         gridPane.add(name,0,0);
         gridPane.add(cmptL,1,1);
         gridPane.add(completedTemp,1,0);
         gridPane.add(atmpL,2,1);
         gridPane.add(attemptsTemp,2,0);
         gridPane.add(yardL,3,1);
         gridPane.add(yardsTemp,3,0);
         gridPane.add(tdwnL,4,1);
         gridPane.add(touchdownsTemp,4,0);
         gridPane.add(icpnL,5,1);
         gridPane.add(interceptionsTemp,5,0);
         gridPane.add(calculate,3,6);
           
         //Spaces
         gridPane.setVgap(10);
         gridPane.setHgap(10);
         gridPane.setPadding(new Insets(30));
         gridPane.setBackground(new Background(new BackgroundFill(Color.LIGHTBLUE, null, Insets.EMPTY)));
         Scene scene = new Scene(gridPane);
         primaryStage.setScene(scene);
         primaryStage.setTitle("Quaterback Rating");
         primaryStage.show();


			
		  										
      }		
			
         public static double calcCompletions(int comp, int attempt)
			{
				double comps = comp;
				double attempts = attempt;
				double compPerc = (comps/attempts)*100;
				return compPerc;				
			}
			
			public static double calcYGA(int yard, int attempt)
			{
				double yards = yard;
				double attempts = attempt;
				double YGA = (yards/attempts);
				return YGA;
			}	
				
			public static double calcTDResult(int td, int attempt)
			{
				double tds = td;
				double attempts = attempt;
				double tdPerc = (tds/attempts)*100;
				return tdPerc;			
			}
			
			public static double calcInter(int inter, int attempt)
			{
				double inters = inter;
				double attempts = attempt;
				double interPerc = (inters/attempts)*100;
				return interPerc;	
			}
			
			public static double qbRating(double comp, double yga, 
													double td, double inter)
			{	
				double compRating = (comp - 30.0)*.05;
				if (compRating < 0.0)
					compRating = 0.0;
				if (compRating > 2.375)
					compRating = 2.375;
					
				double ygaRating = (yga - 3.0)*0.25;
				if (ygaRating < 0.0)
					ygaRating = 0.0;
				if (ygaRating > 2.375)
					ygaRating = 2.375;
					
				double tdRating = (td*0.2);
				if (tdRating > 2.375)
					tdRating = 2.375;
					
				double intRating = 2.375 - (inter*0.25);
				if (intRating < 0.0)
					intRating = 0.0;	
				
				double rating = (compRating + ygaRating + 
										tdRating + intRating)/6 * 100;
				return rating;
			}					
		
	
	/*****************************************************************/	
class ButtonClickHandler implements EventHandler<ActionEvent>
   {
      @Override
      public void handle(ActionEvent event)
      {
            
            int completed = Integer.parseInt(completedTemp.getText());
				int attempted = Integer.parseInt(attemptsTemp.getText());			
          	int yard = Integer.parseInt(yardsTemp.getText());
				int touchdown = Integer.parseInt(touchdownsTemp.getText());
            int interception = Integer.parseInt(interceptionsTemp.getText());
            
            double compResult = calcCompletions(completed, attempted);
		      double ygaResult = calcYGA(yard, attempted);
		      double tdResult = calcTDResult(touchdown, attempted);
		      double interResult = calcInter(interception, attempted);
		      double rating = qbRating(compResult, ygaResult, 
										tdResult, interResult);

            
            
            
            DecimalFormat threeDec = new DecimalFormat("0.000");
		
		      String output = name.getText() + "'s quarterback rating is: " + 
											      threeDec.format(rating) + "." + 
			                   "\n" + "This is based upon the data you inputted:" +
			                   "\n" + "Completed Passes: " + completed + "." +
			                   "\n" + "Attempted Passes: " + attempted + "." +
			                   "\n" + "Receiving Yards: " + yard + "." +
			                   "\n" + "Touchdowns: " + touchdown + "." +
			                   "\n" + "Interceptions: " + interception + "." + "\n" +
			                   "\n" + "Percentage of Completions: " 
			               	  	   + threeDec.format(compResult) + "." +
			                   "\n" + "Average Yards Gained Per Attempt: " 
						               + threeDec.format(ygaResult) + "." +
			                   "\n" + "Percentage of Touchdowns: " 
						               + threeDec.format(tdResult) + "." + " % " +
			                   "\n" + "Percentage of Interceptions: " 
						               + threeDec.format(interResult) + "." + " % ";
			
			  JOptionPane.showMessageDialog(null, output,
				               "Quarterback Rating", JOptionPane.INFORMATION_MESSAGE);
                           
           System.exit(0);
			

      }
  }

}


