import random


def initialize(cities_count):
    population = []
    cities = [0] * cities_count
    for i in range(0, cities_count, 1):
        cities[i] = i

    # retain starting index as person needs to return to its place
    for i in range(populations):
        c = cities[1:]
        random.shuffle(c)
        shuffled = [cities[0]] + c + [0]
        population.append(shuffled)
    return population


def fitnessEvaluation(cities, population1):
    distance = 0
    for i in range(len(population1) - 1):
        current = population1[i]
        next = population1[i + 1]
        distance += cities[current][next]
    return distance


def Selection(fitness, id):
    total = sum(fitness)
    cumulativeProbabilty = 0
    probability = [0] * len(fitness)
    rand = random.uniform(0, 1)
    for i in range(len(fitness)):
        probability[i] = fitness[i] / total

        # We need to select will minimum distance
        # probability[i] = 1 - probability[i]

        # select a floating value between 0 and 1
        cumulativeProbabilty += probability[i]
        if rand <= cumulativeProbabilty and i != id:
            return i
    return -1


def crossover(parent1, parent2):
    offspring = [0] * (len(parent1) - 2)
    start = random.randint(1, len(offspring))
    end = random.randint(1, len(offspring))
    childIndex = 0
    if start > end:
        offspring[end:start] = parent1[end + 1:start + 1]
        childIndex = start % len(offspring)
    else:
        offspring[start:end] = parent1[start + 1:end + 1]
        childIndex = end % len(offspring)

    for city in range(1, len(parent2) - 1):
        if parent2[city] not in offspring:
            offspring[childIndex] = parent2[city]
            childIndex = (childIndex + 1) % len(offspring)
    offspring.append(0)
    offspring.insert(0, 0)
    return offspring


def mutation(parent):
    start = random.randint(1, len(parent) - 2)
    end = random.randint(1, len(parent) - 2)
    offspring = parent
    offspring[start], offspring[end] = offspring[end], offspring[start]


def evolvePopulations(population, fitness):
    offspring = []
    while len(offspring) < len(population):
        parent1 = Selection(fitness, -1)
        parent2 = Selection(fitness, parent1)
        child = crossover(population[parent1], population[parent2])
        offspring.append(child)
    return offspring


def TSP(Cities):
    population = initialize(len(Cities))

    for j in range(generations):
        fitness = [0] * len(population)
        for i in range(len(population)):
            fitness[i] = fitnessEvaluation(Cities, population[i])
        population = evolvePopulations(population, fitness)

    # best will be the minimum of all populations
    best_route = min(population)
    return best_route


populations = 10
generations = 1000


def main():
    Cities = [
        [0, 2, 9, 10, 10],
        [2, 0, 6, 4, 5],
        [9, 6, 0, 3, 3],
        [10, 4, 3, 0, 1],
        [10, 4, 3, 10, 0]
    ]

    r = TSP(Cities)
    print("Best Route:", r)
    print("Cost:", fitnessEvaluation(Cities, r))


main()
