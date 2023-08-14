## Randomized Depth-First Search Maze

This maze generation algorithm uses a recursive approach called Randomized Depth-First Search on a hexagonal grid.

## Recursive Implementation
The depth-first search algorithm for maze generation can be described using the following recursive routine:

1. Given a current cell as a parameter.
2. Mark the current cell as visited.
3. While the current cell has any unvisited neighbor cells:
  3.1 Choose one of the unvisited neighbors.
  3.2 Remove the wall between the current cell and the chosen cell.
  3.3 Invoke the routine recursively for the chosen cell.
