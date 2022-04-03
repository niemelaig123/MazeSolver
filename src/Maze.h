//
// Created by nieme on 2022-02-16.
//

#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <iostream>
#include <fstream>

class Maze {
private:
    const static int MAZE_WIDTH = 52;
    const static int MAZE_HEIGHT = 51;
    char maze[MAZE_HEIGHT][MAZE_WIDTH]{};
    //FileStream *file_stream;
public:
    Maze() = default;
    virtual ~Maze() = default;

    // Methods

    // For accessing maze information
    int get_width();
    int get_height();
    char get_char(int row, int col);

    // for writing to the maze
    void write(int row, int col, char symbol);
    void read_maze_from_file(std::string name);
    void write_maze_to_file(std::string);

    friend std::ostream& operator<<(std::ostream &output, Maze &maze);
};


#endif //ASSIGNMENT_2_MAZE_H
