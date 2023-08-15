public class Undeclared extends Student{
    private int creditHours;
    private static int totalCreditHours = 0;
    public Undeclared(String firstName, String lastName, String major,double gpa, boolean isTA, String advisor, int creditHours) {
        super(firstName, lastName, major, gpa, isTA, advisor);
        this.creditHours = creditHours;
        totalCreditHours+=creditHours;
    }

    //Overriden function
    public int getCreditHours() {
        return creditHours;
    }

    //Overriden function
    public int getTotalCreditHours() {
        return totalCreditHours;
    }

    public String toString() {
        System.out.print(super.toString());
        return "Degree: Undeclared\nCredit Hours: " + creditHours;
    }
}
