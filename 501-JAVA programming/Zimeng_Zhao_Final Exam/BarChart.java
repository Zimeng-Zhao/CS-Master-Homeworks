package application;

import java.util.Scanner;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.scene.shape.Rectangle;
public class BarChart extends Application{

	
	public void start(Stage primaryStage) throws IllegalArgumentException {
		Scanner input = new Scanner(System.in);
		int Project = 0;
		int Quiz = 0;
		int Midterm = 0;
		int Final = 0;
		System.out.println("Please enter the percentage of Project : ");
		Project = input.nextInt();
		System.out.println("Please enter the percentage of Quiz : ");
		Quiz = input.nextInt();
		System.out.println("Please enter the percentage of Midterm : ");
		Midterm = input.nextInt();
		System.out.println("Please enter the percentage of Final : ");
		Final = input.nextInt();
		if(Project + Quiz + Midterm + Final != 100) {
			Alert errorAlert = new Alert(AlertType.ERROR);
			errorAlert.setHeaderText("Input not valid");
			errorAlert.setContentText("Total percentage not equal to 100");
			errorAlert.showAndWait();
		}
		else {
			Rectangle r1 = new Rectangle(5, 300 - Project * 3, 60, Project * 3);
			r1.setStroke(Color.RED);
			r1.setFill(Color.RED);
			Rectangle r2 = new Rectangle(105, 300 - Quiz * 3, 60, Quiz * 3);
			r2.setStroke(Color.BLUE);
			r2.setFill(Color.BLUE);
			Rectangle r3 = new Rectangle(205, 300 - Midterm * 3, 60, Midterm * 3);
			r3.setStroke(Color.GREEN);
			r3.setFill(Color.GREEN);
			Rectangle r4 = new Rectangle(305, 300 - Final * 3, 60, Final * 3);
			r4.setStroke(Color.YELLOW);
			r4.setFill(Color.YELLOW);
			
			Group group = new Group();
			group.getChildren().addAll(new Text(5, 300 - Project * 3 - 5, "Project--" + Project + "%"), r1,
					new Text(105, 300 - Quiz * 3 - 5, "Quiz--" + Quiz + "%"), r2,
					new Text(205, 300 - Midterm * 3 - 5, "Midterm--" + Midterm + "%"), r3,
					new Text(305, 300 - Final * 3 - 5, "Final--" + Final + "%"), r4);
			Scene scene = new Scene(new BorderPane(group), 500, 300);
			primaryStage.setScene(scene);
			primaryStage.show();
		}
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		launch();
	
	}

}
