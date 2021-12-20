package Proj1;

import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileReader;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

/**
 * Main class to perform all file operations
 */

/*
   FEEDBACK:

   SUBMITTED FILES
      Missing file containing sample run -5

   DOCUMENTATION
      Missing Name and project description -3

   NOTE:
      you forgot to add a break statement after the switch case for option 3
 */

public class Main {
   // instance variables
   private static RandomAccessFile file;
   private static String filename;

   /**
    * Main function
    * 
    * @param args
    */
   public static void main(String[] args) {

      int option;
      Scanner scanner = new Scanner(System.in); // create new scanner instance
      do {

         option = showMenu(scanner); // call show menu function and recieves option selected by user

         switch (option) {
            case 1:
               createRandomAccessFile(scanner);
               break;
            case 2:
               displayRandomAccessFile(scanner);
               break;
            case 3:
               retrieveRecord(scanner);
            case 4:
               modifyRecord(scanner);
               break;
            case 5:
               addRecord(scanner);
               break;
            case 6:
               deleteRecord(scanner);
               break;
            case 7:
               break;
            default:
               System.out.println("Invalid option selected. Try again");
               ;
         }

      } while (option != 7);

      scanner.close();
   }

   /**
    * Function which display menu and returns option selected by user
    * 
    * @param scanner
    * @return int
    */
   public static int showMenu(Scanner scanner) {
      System.out.println("1 - Create a random-access file");
      System.out.println("2 - Display a random-access file");
      System.out.println("3 - Retrieve a record");
      System.out.println("4 - Modify a record");
      System.out.println("5 - Add a new record");
      System.out.println("6 - Delete a record");
      System.out.println("7 - Exit");
      System.out.print("Enter your choice: ");
      int option = scanner.nextInt();
      scanner.nextLine();
      return option;
   }

   /**
    * Function to create a random access file
    * 
    * @param scanner
    */
   public static void createRandomAccessFile(Scanner scanner) {

      System.out.print("Enter input file name: ");
      String inFile = scanner.nextLine();

      System.out.print("Enter file name: ");
      filename = scanner.nextLine(); // set the instance variable
      try {
         file = new RandomAccessFile(filename, "rw");
         file.seek(0);
         FileReader reader = new FileReader(inFile);
         BufferedReader breader = new BufferedReader(reader);
         String line = breader.readLine();
         while (line != null) {
            String[] data = line.split(" ");
            Student std = new Student();
            std.setData(data[0], data[1], Integer.parseInt(data[2]), Double.parseDouble(data[3]));
            std.writeToFile(file);
            line = breader.readLine();
         }
         breader.close();
         reader.close();
         file.close();
      } catch (IOException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
      }
   }

   /**
    * Function to display records
    * 
    * @param scanner
    */
   public static void displayRandomAccessFile(Scanner scanner) {
      System.out.print("Enter file name: ");
      String filename = scanner.nextLine();
      try {
         file = new RandomAccessFile(filename, "rw");
         file.seek(0);
         Student std = new Student();
         char opt = 'N';
         do {
            switch (opt) {
               case 'N':
                  try {
                     int count = 0;
                     while (true) {
                        std.readFromFile(file);
                        if (std.getID() != -1)
                           System.out.println(std.toString());

                        count++;
                        if (count == 5) {
                           break;
                        }
                     }
                  } catch (EOFException e) {
                     // TODO: handle exception
                  }

                  break;
               case 'D':
                  try {
                     while (true) {
                        std.readFromFile(file);
                        if (std.getID() != -1)
                           System.out.println(std.toString());
                     }
                  } catch (Exception e) {
                     // TODO: handle exception
                  }

                  break;

               default:
                  System.out.println("Invalid selection. Try again");
                  break;
            }

            System.out.println("Next Screen (N)");
            System.out.println("Display All (D)");
            System.out.println("Return to Main Menu (M)");
            opt = scanner.nextLine().toUpperCase().charAt(0);
         } while (opt != 'M');

      } catch (IOException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
      }
   }

   public static void retrieveRecord(Scanner scanner) {
      System.out.print("Enter a record number: ");
      int num = scanner.nextInt();
      num = num - 1;
      Student std = new Student();
      try {
         file.seek(num * std.size());
         std.readFromFile(file);
         System.out.println(std.toString());
      } catch (EOFException e) {
         System.out.println("No record found");
      } catch (IOException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
      }
   }

   public static void modifyRecord(Scanner scanner) {
      System.out.print("Enter a record number: ");
      int num = scanner.nextInt();
      scanner.nextLine();
      num = num - 1;
      Student std = new Student();
      try {
         file = new RandomAccessFile(filename, "rw");
         file.seek(num * std.size());
         std.readFromFile(file);
         if (std.getID() == -1) {
            throw new EOFException();
         }
         System.out.println(std.toString());

         System.out.println("Modify Record (Leave empty if you want to keep previous value)");
         System.out.print("Enter First Name: ");
         String fname = scanner.nextLine();
         System.out.print("Enter Last Name: ");
         String lname = scanner.nextLine();
         System.out.print("Enter ID: ");
         String idText = scanner.nextLine();
         int id = -1;
         if (!idText.isEmpty()) {
            id = Integer.parseInt(idText);
         }

         System.out.print("Enter GPA: ");

         double gpa = -1;
         String gpaText = scanner.nextLine();
         if (!gpaText.isEmpty()) {
            gpa = Double.parseDouble(gpaText);
         }

         if (!fname.isEmpty()) {
            std.setFirst(fname);
         }
         if (!lname.isEmpty()) {
            std.setLast(lname);
         }
         if (!lname.isEmpty()) {
            std.setLast(lname);
         }
         if (gpa >= 0) {
            std.setGPA(gpa);
         }
         if (id > 0) {
            std.setID(id);
         }
         file.seek(num * std.size());
         std.writeToFile(file);
      } catch (EOFException e) {
         System.out.println("No record found");
      } catch (IOException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
      }
   }

   public static void addRecord(Scanner scanner) {
      Student std = new Student();
      try {
         file = new RandomAccessFile(filename, "rw");
         file.seek(file.length());
         System.out.println("Add a record");
         System.out.print("Enter First Name: ");
         String fname = scanner.nextLine();
         System.out.print("Enter Last Name: ");
         String lname = scanner.nextLine();
         System.out.print("Enter ID: ");
         int id = scanner.nextInt();
         System.out.print("Enter GPA: ");
         Double gpa = scanner.nextDouble();

         std.setData(fname, lname, id, gpa);
         std.writeToFile(file);
      } catch (IOException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
      }
   }

   public static void deleteRecord(Scanner scanner) {
      System.out.print("Enter a record number: ");
      int num = scanner.nextInt();
      scanner.nextLine();
      num = num - 1;
      Student std = new Student();
      try {
         file = new RandomAccessFile(filename, "rw");
         file.seek(num * std.size());
         std.readFromFile(file);
         if (std.getID() == -1) {
            throw new EOFException();
         }
         std.setID(-1);
         file.seek(num * std.size());
         std.writeToFile(file);
      } catch (EOFException e) {
         System.out.println("No record found");
      } catch (IOException e) {
         // TODO Auto-generated catch block
         e.printStackTrace();
      }
   }
}
