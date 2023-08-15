public class Student {
    private String firstName;
    private String lastName;
    private String major;
    private double gpa;
    private boolean isTA;
    private String advisor;

    // Constructor, getters and setters

    public Student(String firstName, String lastName, String major,double gpa, boolean isTA, String advisor) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.major = major;
        this.gpa = gpa;
        this.isTA = isTA;
        this.advisor = advisor;
    }
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getMajor() {
        return major;
    }

    public double getGpa() {
        return gpa;
    }

    public boolean isTA() {
        return isTA;
    }


    @Override
    public String toString() {
        String TA = isTA ? "Yes" : "No";
        return "Name: " + firstName + " " + lastName + "\n" +
                "Major: " + major + "\n" +
                "GPA: " + gpa + "\n" +
                "TA: " + TA + "\n" +
                "Advisor: " + advisor + "\n";
    }

    public int getCreditHours() {
        return 3; // child class will specify credit hours
    }

    //Overriden function
    public int getTotalCreditHours() {
        return 3;
    }
}
