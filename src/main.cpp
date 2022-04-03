#include <iostream>
#include "Mover.h"

int main(int argc, char** argv) {

    // Testing Maze Solver
    Mover maze_mover;
    if(argc > 1) {
        maze_mover.maze.read_maze_from_file(argv[1]);
    } else {
        maze_mover.maze.read_maze_from_file("../tests/test.txt");
    }

    // Testing Solving algorithm
    maze_mover.solve();
    std::cout << maze_mover.maze;

    // Testing writing to file
    if(argc > 2) {
        maze_mover.maze.write_maze_to_file(argv[2]);
    } else {
        maze_mover.maze.write_maze_to_file("../solved/mazesolution.txt");
    }

    return 0;
}