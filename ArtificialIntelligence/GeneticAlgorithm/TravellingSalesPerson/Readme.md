## Genetics Algorithm for Travelling Sales Person Problem

### Initialization
Create an initial population of potential solutions. Each solution is represented as a sequence of cities (routes).

### Fitness Evaluation
Calculate the fitness of each solution in the population. In the TSP, the fitness is the total distance traveled in a route. Shorter distances correspond to higher fitness values.

### Selection
Select a pair of parent solutions from the population to create offspring for the next generation. The selection process is typically based on the fitness values, giving higher fitness solutions a higher chance of being selected. Popular selection techniques include tournament selection and roulette wheel selection.

### Crossover
Perform crossover between the selected parents to create offspring. Crossover is a process where parts of the parent solutions are combined to create new solutions. In the TSP, a common crossover method is the Order Crossover (OX), which preserves the relative order of cities between the parents.

### Mutation
Introduce random changes to the offspring solutions to maintain diversity and explore new areas of the search space. Mutation typically involves swapping two cities in a route or randomly modifying a small portion of the route.

### Replacement
Replace some solutions in the current population with the offspring solutions to form the next generation. The replacement can be based on various criteria, such as elitism (keeping the best solutions from the current generation) or generational replacement (replacing the entire population).

### Termination
The termination condition can be a specific number of generations, reaching a satisfactory solution, or a predefined runtime.

### Solution Extraction
Once the algorithm terminates, the best solution (route) found in the final population represents the approximate solution to the TSP. The best route corresponds to the shortest distance traveled among the solutions.

The genetic algorithm iteratively applies these steps, allowing solutions to evolve over multiple generations. By combining selection, crossover, and mutation operations, the algorithm explores and exploits the search space to converge towards better solutions for the TSP.
