/***************************
Name: Umangkumar Patel
Date: November 26, 2019
Prof: Fahringer, Daniel
Prog: Skateboards
****************************/
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.scene.layout.HBox;
import javafx.scene.control.Label;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.GridPane;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.collections.ObservableList;
import javafx.scene.control.SelectionMode;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Insets;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javax.swing.JOptionPane;

public class skateBoard extends Application
{
   double price = 0;
   VBox deckVBox, truckVBox, wheelVBox, totalVBox;
   TitledPane deckPane, truckPane, wheelPane, totalPane;
   ComboBox<String> deckCBox, truckCBox, wheelCBox;
   ListView<String> tListView;
   
   @Override
   public void start(Stage primaryStage)
   {
      // Create a Header for the App
      Label titleLabel = new Label("Skateboard");
      HBox  titleHBox = new HBox(1);
      titleHBox.setAlignment(Pos.CENTER);
      titleLabel.setFont(Font.font("Copperplate", FontWeight.BOLD, 25));
      titleHBox.getChildren().add(titleLabel);      
      
      // Declare Elements--------------------------------//
      
      GridPane gridPane = new GridPane();
      Button order;
      //---------DECK PANE----------------------//
       deckVBox = new VBox();
       deckCBox = new ComboBox();
       deckCBox.getItems().addAll("Master Thrasher","The Dictator", "The Street King");
       deckVBox.getChildren().addAll(deckCBox);
       deckPane = new TitledPane("Select Deck", deckVBox);
       deckPane.setCollapsible(false);
       deckPane.setPrefHeight(75);
   
       //-------TRUCK PANE---------------------//
       truckVBox = new VBox();
       truckCBox = new ComboBox();
       truckCBox.getItems().addAll("7.75 inch Axle", "8.0 inch Axle", "8.5 inch Axle");
       truckVBox.getChildren().addAll(truckCBox);
       truckPane = new TitledPane("Truck Assemblies", truckVBox);
       truckPane.setCollapsible(false);
       deckPane.setPrefHeight(75);

       //------ WHEEL PANE---------------------//
       wheelVBox = new VBox();
       wheelCBox = new ComboBox();
       wheelCBox.getItems().addAll("51", "55", "58", "61");
       wheelVBox.getChildren().addAll(wheelCBox);
       wheelPane = new TitledPane("Wheels", wheelVBox);
       wheelPane.setCollapsible(false);
       wheelPane.setPrefHeight(75);
       
       //------ TOTAL PANE --------------------//
       totalVBox = new VBox();
       tListView = new ListView();
       tListView.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
       tListView.getItems().addAll("Grip Tape", "Bearings", "Riser Pads", "Nuts & Bolts");
       totalVBox.getChildren().addAll(tListView);
       totalPane = new TitledPane("Miscellaneous", totalVBox);
       totalPane.setCollapsible(false);
       totalPane.setPrefHeight(100);
       
       // ------ BUTTON_------------------------//
       order = new Button("Submit Order");
       order.setPrefWidth(75);
       // -------BUTTON EVENT-------------------//
       order.setOnAction(e -> SubmitButtonClick());
     

      //************Final GridPane*************//
      gridPane.add(titleHBox,0,0);
      gridPane.add(deckPane,1,0);
      gridPane.add(truckPane,2,0);
      gridPane.add(wheelPane,3,0);
      gridPane.add(totalPane,4,0);
      gridPane.add(order,5,0);
      //************Final Output***************//
      Scene scene = new Scene(gridPane);
      primaryStage.setTitle("Skate-Board");
      primaryStage.setScene(scene);
      primaryStage.show();
            
   }
   private void SubmitButtonClick()
   {
     String deckBox  = deckCBox.getValue();
     String truckBox = truckCBox.getValue();
     String wheel    = wheelCBox.getValue();
     double dPrice=0.00,tPrice=0.00, wPrice=0.00, mPrice=0.00;
     
     if(deckBox.equals("Master Thrasher")) { dPrice = 60.00;}
     if(deckBox.equals("The Dictator")) { dPrice = 45.00;}
     if(deckBox.equals("The Street King")) { dPrice = 50.00;}
     
     if(truckBox.equals("7.75 inch Axle")) { tPrice = 35.00;}
     if(truckBox.equals("8.0 inch Axle")) { tPrice = 40.00;}
     if(truckBox.equals("8.5 inch Axle")) { tPrice = 45.00;}
     
     if(wheel.equals("51")) { wPrice = 20.00;}
     if(wheel.equals("55")) { wPrice = 22.00;}
     if(wheel.equals("58")) { wPrice = 24.00;}
     if(wheel.equals("61")) { wPrice = 28.00;}
     
     ObservableList<String> selections = 
      tListView.getSelectionModel().getSelectedItems();
     String[] itemArray = selections.toArray(new String[0]);
     String m = "";
     for(int i=0; i <itemArray.length; i++)
     {
      if(itemArray[i].equals("Grip Tape"))
        { mPrice += 10.00; m += "\nGrip Tape    : $10.00"; }
      if(itemArray[i].equals("Bearings"))
        { mPrice += 30.00; m += "\nBearing Pads : $30.00"; }
      if(itemArray[i].equals("Riser Pads"))
        { mPrice += 2.00; m +=  "\nRiser Pad    : $2.00"; }
      if(itemArray[i].equals("Nuts & Bolts"))
        { mPrice += 3.00; m +=  "\nNuts $ Bolts : $3.00"; }
      }
    price = dPrice + tPrice + wPrice + mPrice;
    String output = deckBox + " : " + dPrice + "\n" +
                   truckBox + " : " + tPrice + "\n" +
                   wheel    + " : " + wPrice + "\n" +
                   m;
   JOptionPane.showMessageDialog(null,output);

   }
   
   public static void main(String[] args)
   {
      launch(args);
   }
}