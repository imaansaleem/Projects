import random

# Knapsack problem inputs
weights = [2, 5, 10, 5]
profit = [40, 30, 50, 10]
knapsackCapacity = 16

# Genetic algorithm parameters
populationSize = 50
chromosomeLength = len(weights)
tournamentSize = 3
mutationRate = 0.1
generations = 100


# Generate initial population
def generate_individual():
    generationList = []
    for i in range(chromosomeLength):
        generationList.append(random.randint(0, 1))
    return generationList


def generate_population():
    population = []
    for i in range(populationSize):
        population.append(generate_individual())
    return population


# Fitness evaluation
def evaluate_fitness(chromosome):
    totalProfit = 0
    totalWeight = 0
    for i in range(chromosomeLength):
        totalProfit += (chromosome[i] * profit[i])
        totalWeight += (chromosome[i] * weights[i])
    if totalWeight > knapsackCapacity or totalWeight == 0:
        return -1  # Penalize solutions that exceed knapsack capacity
    return totalProfit


def bestSolution(solution):
    maxi = -999
    winner = []
    for i in range(len(solution)):
        Maximum = evaluate_fitness(solution[i])
        if maxi < Maximum:
            maxi = Maximum
            winner = solution[i]
    return maxi, winner


# Tournament selection
def tournament_selection(population):
    maxi = -999
    selected_parents = []
    tournament = []
    winner = []
    for i in range(populationSize):
        for j in range(tournamentSize):
            tournament.append(population[random.randint(0, populationSize - 1)])
        maxi, winner = bestSolution(tournament)
        selected_parents.append(winner)
    return selected_parents


# Crossover
def crossover(parent1, parent2):
    crossover_point = random.randint(1, chromosomeLength - 1)
    child = parent1[:crossover_point] + parent2[crossover_point:]
    return child


# Mutation
def mutate(chromosome):
    for i in range(chromosomeLength):
        if random.random() < mutationRate:
            chromosome[i] = 1 - chromosome[i]  # Flip the bit
    return chromosome


# Genetic algorithm
def geneticAlgorithm():
    population = generate_population()
    for generation in range(generations):
        # Select parents through tournament selection
        parents = tournament_selection(population)

        # Create offspring through crossover and mutation
        offspring = []
        while len(offspring) < populationSize:
            parent1 = parents[random.randint(0, len(parents) - 1)]
            parent2 = parents[random.randint(0, len(parents) - 1)]
            child = crossover(parent1, parent2)
            child = mutate(child)
            offspring.append(child)

        # Replace the current population with the offspring
        population = offspring

    # Find the best solution in the final population

    maxi, best = bestSolution(population)
    return maxi, best


def main():
    bestSol, bestFitness = geneticAlgorithm()

    print("Best solution:", bestSol)
    print("Best fitness:", bestFitness)


main()
