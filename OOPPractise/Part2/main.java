import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        Employee emp1 = new Employee(111, "Jimmy Dean", 5256.32, 0);
        Employee emp2 = new Employee(598, "Jen Johnson", 47370, 5);
        Employee emp3 = new Employee(920, "Jan Jones", 47834.25, 1);
        System.out.println(emp1.equals(emp3));
        ArrayList<Employee> list = new ArrayList<>();
        list.add(emp1);
        list.add(emp2);
        list.add(emp3);

        // sort by net salary in ascending order
        list.sort(Employee.netSalaryComparator);

        for (Employee e : list)
            System.out.println(e);
    }
}
