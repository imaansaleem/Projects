//+---+---+---+---+---+---+
//| .   .   . |           |
//+---+---+   +---+---+   +
//|       | .   .   . |   |
//+   +---+---+---+   +   +
//|               | . |   |
//+   +---+---+   +   +   +
//|   |   |       | . |   |
//+   +   +   +---+   +   +
//|       |         .   . |
//+---+---+---+---+---+---+

//Recursive implementation
//Randomized depth-first search on a hexagonal grid
//The depth-first search algorithm of maze generation is frequently implemented using backtracking. This can be described with a following recursive routine:
//
//1Given a current cell as a parameter
//2Mark the current cell as visited
//3While the current cell has any unvisited neighbour cells
//   1Choose one of the unvisited neighbours
//   2Remove the wall between the current cell and the chosen cell
//   3Invoke the routine recursively for a chosen cell
//which is invoked once for any initial cell in the area.
