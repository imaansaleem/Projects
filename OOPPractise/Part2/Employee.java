import java.util.Comparator;

public class Employee {
    private int id;
    private String name;
    private double salary;
    private int numberOfDependents;
    private double netSalary;

    public Employee(int id, String name, double salary, int numberOfDependents) {
        this.id = id;
        this.name = name;
        this.salary = salary;
        this.numberOfDependents = numberOfDependents;
        netSalary = salary*0.91 + (numberOfDependents*0.01*salary);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public int getNumberOfDependents() {
        return numberOfDependents;
    }

    public double getNetSalary() {
        return netSalary;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setNumberOfDependents(int numberOfDependents) {
        this.numberOfDependents = numberOfDependents;
    }

    public String toString(){
        return "[" + id + ',' + name + ',' + netSalary +"]";
    }

    @Override
    public boolean equals(Object obj) {

        //If obj and this are the same instance, it means they refer to the same memory location in the heap, so they must be equal.
        if (obj == this) {
            return true;
        }

        //the object being compared with the current object (this) must be an instance of the Employee class.
        else if (!(obj instanceof Employee)) {
            return false;
        }

        //else net salary of all the data members of employee class
        Employee emp = (Employee) obj;
        return emp.getNetSalary() == this.getNetSalary();
    }

    public static Comparator<Employee> netSalaryComparator = new Comparator<Employee>() {
        @Override
        public int compare(Employee emp1, Employee emp2) {
            double netSalary1 = emp1.getNetSalary();
            double netSalary2 = emp2.getNetSalary();

            //If emp1 should come before emp2 in the sorted list, return a negative number
            if (netSalary1 < netSalary2) {
                return -1;
            }

            //If emp1 should come after emp2 in the sorted list, return a positive number
            else if (netSalary1 > netSalary2) {
                return 1;
            }

            //If emp1 and emp2 have the same order in the sorted list, return 0.
            else {
                return 0;
            }
        }
    };
}
