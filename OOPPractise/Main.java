import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create an ArrayList to store the student data
        ArrayList<Student> students = new ArrayList<>();

        // Read the CSV file and populate the students list
        try {
            File file = new File("students_dataset.csv");
            Scanner scanner = new Scanner(file);

            // Skip the header row
            String l = scanner.nextLine();
            String[] r = l.split(",");
            System.out.println("-----------------------------------------------------------Student Data-----------------------------------------------------------\n");
            System.out.format("%-21s%-20s%-20s%-20s%-19s%-20s%-20s%-20s\n",r[0],r[1],r[2],r[3],r[4],r[5],r[6],r[7]);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] records = line.split(",");

                //converting string to integer (credit hours)
                int intValue = Integer.parseInt(records[5]);

                //converting string to boolean (isTA)
                //if records[6] is yes it will store true else false
                boolean boolValue = records[6].equalsIgnoreCase("Yes");

                //converting string to double
                double d = Double.parseDouble(records[4]);

                System.out.format("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",records[0],records[1],records[2],records[3],records[4],records[5],records[6],records[7]);
                //System.out.print(records[0] + "\t" + records[1] + "\t" + records[2] + "\t" + records[3] + "\t" + records[4] + "\t");
                //System.out.println(records[5] + "\t" + records[6] + "\t" + records[7] + "\t");
                // First Name   Last Name    Major   GPA   TA   Advisor Degree	Credit Hours
                Student student = objectSelection(records[0], records[1], records[2], d, boolValue, records[7], records[3],intValue);
                students.add(student);
            }

            System.out.println("File Reading done!");
            scanner.close();

        } catch (FileNotFoundException e) {
            System.out.println("Error: Could not open file.");
        }

        // Now we have the student data in the students ArrayList
        // We can answer the questions using this data

        //Answer to question no 1
        System.out.println("How many Teaching Assistants (TA) do we have? Display their names");
        numberOfTA(students);
        System.out.println("\n-------------------------------------------\n");

        //Answer to question no 2
        System.out.println("What is the full information of the students whose GPA is more than 3.75?\n");
        studentDisplay(students);
        System.out.println("\n-------------------------------------------\n");

        //Answer to question no 3
        System.out.println("What are the average credit hours of the Biology Major?\n");
        System.out.println("Average credit hours of Biology Major: " + biologyMajor(students));
        System.out.println("\n-------------------------------------------\n");

        //Answer to question no 4
        System.out.println("What is the average GPA of the students whose degree is B.S.?\n");
        System.out.println("Average GPA of B.S. degree students: " + averageGPA(students));
        System.out.println("\n-------------------------------------------\n");

        //Answer to question no 5
        System.out.println("Display the list of degrees along with the total credit hours\n");
        listOfDegrees(students);
        System.out.println("\n-------------------------------------------\n");
    }

    public static Student objectSelection(String firstName, String lastName, String major,double gpa, boolean isTA, String advisor, String degree,int intValue){
        if(degree.equalsIgnoreCase("PhD"))
            return new PhDStudent(firstName, lastName, major, gpa, isTA, advisor,intValue);

        else if(degree.equalsIgnoreCase("B.S."))
            return new BSStudent(firstName, lastName, major, gpa, isTA, advisor,intValue);

        else if(degree.equalsIgnoreCase("M.S"))
            return new MSStudent(firstName, lastName, major, gpa, isTA, advisor,intValue);

        else
            return new Undeclared(firstName, lastName, major, gpa, isTA, advisor,intValue);
    }

    public static void numberOfTA(ArrayList<Student> students){
        int numTA = 0;
        System.out.println("\nTA Names: ");
        for (Student student : students) {
            if (student.isTA()) {
                System.out.println(student.getFirstName() + " " + student.getLastName());
                numTA++; // calculate the number of TA's
            }
        }
        System.out.println("Total Number of TAs: " + numTA);
    }

    public static void studentDisplay(ArrayList<Student> students){
        System.out.println("Information of Students with GPA greater than 3.75");
        for (Student student : students) {
            if (student.getGpa() > 3.75) {
                System.out.println(student + "\n");
            }
        }
    }

    public static double biologyMajor(ArrayList<Student> students){
        int numBiology = 0;
        int totalCreditHours = 0;
        for (Student student : students) {
            if (student.getMajor().equalsIgnoreCase("Biology")) {
                numBiology++;
                totalCreditHours += student.getCreditHours();
            }
        }
        return (double) totalCreditHours / numBiology;
    }

    public static double averageGPA(ArrayList<Student> students){
        int numBS = 0;
        double totalGpa = 0;

        for (Student student: students) {
            if (student instanceof BSStudent) {
                numBS++;
                totalGpa += student.getGpa();
            }
        }

        return totalGpa / numBS;
    }
    public static void listOfDegrees(ArrayList<Student> students){
        System.out.println("Total Credit Hours: ");

        for (Student student: students) {
            if (student instanceof PhDStudent) { // check if element is an PhDStudent
                System.out.println("Phd: " + student.getTotalCreditHours());
                break; // stop searching once an PhDStudent is found
            }
        }

        for (Student student: students) {
            if (student instanceof MSStudent) {
                System.out.println("M.S: " + student.getTotalCreditHours());
                break;
            }
        }

        for (Student student: students) {
            if (student instanceof BSStudent) {
                System.out.println("B.S: " + student.getTotalCreditHours());
                break;
            }
        }

        for (Student student: students) {
            if (student instanceof Undeclared) {
                System.out.println("Undeclared: " + student.getTotalCreditHours());
                break;
            }
        }
    }

}
