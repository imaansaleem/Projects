## Homework: Employee Class and Comparator Documentation

### Objective

The objective of this coding exercise is to create an `Employee` class and demonstrate its functionality along with the use of a `netSalaryComparator` comparator. The `Employee` class encapsulates employee information, calculates net salaries, and provides sorting capabilities based on net salaries.

### Employee Class

The `Employee` class represents an individual employee and includes the following attributes:

- `id`: Employee ID (integer)
- `name`: Employee name (String)
- `salary`: Employee salary (double)
- `numberOfDependents`: Number of dependents (integer)
- `netSalary`: Calculated net salary after deductions (double)

The class provides the following methods:

- Constructor: Initializes an `Employee` object with the provided ID, name, salary, and number of dependents. The net salary is calculated based on the formula provided in the constructor.
- Getter methods: `getId()`, `getName()`, `getSalary()`, `getNumberOfDependents()`, `getNetSalary()`
- Setter methods: `setId(int id)`, `setName(String name)`, `setSalary(double salary)`, `setNumberOfDependents(int numberOfDependents)`
- `toString()`: Generates a string representation of the employee in the format `[id, name, netSalary]`
- `equals(Object obj)`: Compares two `Employee` objects based on their net salaries. Returns `true` if the net salaries are equal, `false` otherwise.

The class also defines a static `netSalaryComparator` comparator using Java's `Comparator` interface. This comparator is utilized for comparing two employees based on their net salaries, enabling sorting of employees.

### main Class

The `main` class contains the `main` method, serving as the entry point of the program. It demonstrates the functionality of the `Employee` class and the `netSalaryComparator` by:

1. Creating three `Employee` objects with different attributes.
2. Adding the `Employee` objects to an `ArrayList`.
3. Sorting the list of employees based on net salaries in ascending order using the `netSalaryComparator`.
4. Displaying the sorted list of employees.

### Requirements Fulfilled by the Code

1. The `Employee` class encapsulates employee information and provides methods for data manipulation and retrieval.
2. The `Employee` constructor calculates the net salary based on the provided salary and number of dependents.
3. The `equals` method enables meaningful equality comparisons between `Employee` objects based on their net salaries.
4. The static `netSalaryComparator` comparator allows sorting of employees based on net salaries.
5. The `main` class demonstrates the use of the `Employee` class and the `netSalaryComparator` by creating and sorting a list of employees.

By fulfilling these requirements, the code provides a practical implementation for managing and sorting employee data based on net salaries.
