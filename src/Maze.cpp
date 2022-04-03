//
// Created by nieme on 2022-02-16.
//

#include "Maze.h"

// Getters
int Maze::get_width() {
    return this->MAZE_WIDTH;
}

int Maze::get_height() {
    return this->MAZE_HEIGHT;
}

char Maze::get_char(int row, int col) {
    return maze[row][col];
}

// For writing a specific symbol to a specific spot
void Maze::write(int row, int col, char symbol) {
    maze[row][col] = symbol;
}

// Function to read in a maze from a file.
void Maze::read_maze_from_file(std::string name) {
    int line_count = 0;
    int col_count;
    try {
        std::ifstream file_reader(name);
        std::string line;
        while (file_reader) {
            getline(file_reader, line);
            col_count = 0;
            for (char ch : line) {
                this->write(line_count, col_count, ch);
                col_count++;
            }
            line_count++;
            if (line_count >= 51) {
                break;
            }
        }
    } catch (std::ifstream::failure& e) {
        std::cerr << "Error Reading from File";
    } catch (...) {
        std::cerr << "A general error occurred while trying to read from file";
    }

}

void Maze::write_maze_to_file(std::string name) {
    try {
        std::ofstream file_writer(name);
        for (int row = 0; row < this->get_height(); row++) {
            for (int col = 0; col < this->get_width(); col++) {
                // This comparison to NULL is giving me warnings, but it also works, so I am unsure of the proper approach to take with this
                if (this->get_char(row, col) == NULL) {
                    continue;
                }
                file_writer << this->get_char(row, col);
            }
            file_writer << std::endl;
        }
    } catch (std::ofstream::failure& e) {
        std::cerr << "Error writing Maze solution to file.";
    } catch (...) {
        std::cerr << "A general Error occurred while trying to write to file";
    }

}

std::ostream &operator<<(std::ostream &output, Maze &maze) {
    // use nested for loops to traverse maze of symbols
    for (int row = 0; row < maze.get_height(); row++) {
        for (int col = 0; col < maze.get_width(); col++) {
            // If the character is a carriage return or simple a null value dont bother outputting it
            if (maze.get_char(row, col) == NULL) {
                continue;
            }
            output << maze.get_char(row, col);
        }
        // Insert a line break after every line
        output << std::endl;
    }
    return output;
}