/******************************************************************************
 *  Name      :  Umangkumar Patel
 *  Professor :  Fahringer, Daniel  
 *  Class     :  CPS 161 - JAVA VERSION
 *  Program   :  Co-Ordinates(Distance and Midpoint Calculator)
 ******************************************************************************/
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
import javafx.scene.layout.VBox;
import javafx.scene.layout.HBox;
import javafx.scene.layout.GridPane;
import javafx.geometry.Insets;
import javafx.scene.layout.BorderPane;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

public class  Coordinates extends Application
{  
   // Four Text Fields
   private TextField xField  = new TextField();
   private TextField yField  = new TextField();
   private TextField xxField = new TextField();
   private TextField yyField = new TextField();
   
   
   public static void main(String[] args) 
   {
      launch(args);
   }
   
   @Override
   public void start(Stage primaryStage)
   {
      // Prompt Labels
      Label xInput  = new Label("Enter X1: ");
      Label yInput  = new Label("Enter Y1: ");
      Label xxInput = new Label("Enter X2: ");
      Label yyInput = new Label("Enter Y2: ");
      
      // Button
      Button calculate = new Button("Calculate");
      calculate.setOnAction(new ButtonClickHandler());
      
      // Grid Pane
      GridPane gridPane = new GridPane();
      
      // Add labels and textfields in the grid pane
      gridPane.add(xField,1,0);
      gridPane.add(xInput,0,0);
      gridPane.add(yField,1,1);
      gridPane.add(yInput,0,1);
      gridPane.add(xxField,1,2);
      gridPane.add(xxInput,0,2);
      gridPane.add(yyField,1,3);
      gridPane.add(yyInput,0,3);
      gridPane.add(calculate,0,4);
      
      //Spaces
      gridPane.setVgap(10);
      gridPane.setHgap(10);
      gridPane.setPadding(new Insets(30));
      
      Scene scene = new Scene(gridPane);
      primaryStage.setScene(scene);
      primaryStage.setTitle("Co-Ordinates");
      primaryStage.show();
   }
  
  /***********Button**Event**Handler**************/
 class ButtonClickHandler implements EventHandler<ActionEvent>
   {
      @Override
      public void handle(ActionEvent event)
      {

         double x  = Double.parseDouble(xField.getText());
         double y  = Double.parseDouble(yField.getText());
         double xx = Double.parseDouble(xxField.getText());
         double yy = Double.parseDouble(yyField.getText());

         double pair1 = Math.pow((xx-x),2);
	      double pair2 = Math.pow((yy-y),2);
         
         double d   = Math.sqrt(pair1+pair2);
         double mX  = ((x + xx) / 2.0);
         double mY  = ((y + yy) / 2.0);
         
         DecimalFormat oneDec = new DecimalFormat("0.0");
         String output = "Points  :\t( " + x + " , " + y + " ) and ( " + xx + " , " + yy + " )\n" +
                         "Distance:\t" + d + "\n" +
                         "Midpoint:\t(" + mX + " , " + mY + " )\n";
         JOptionPane.showMessageDialog(null, output,
				"Results", JOptionPane.INFORMATION_MESSAGE); 
      }
  }

}