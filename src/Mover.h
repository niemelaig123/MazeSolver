//
// Created by nieme on 2022-02-16.
//

#ifndef ASSIGNMENT_2_MOVER_H
#define ASSIGNMENT_2_MOVER_H

#include "Path.h"
#include "Maze.h"

class Mover {
private:
    int m_row;
    int m_col;
public:
    Path path;
    Path backtrack_path;
    Maze maze;
    Mover();
    virtual ~Mover();

    // Getters
    int get_row();
    int get_col();

    // Functions for traversing
    void move(int row, int col);
    void add_to_path(int row, int col);
    void search_for_move();
    Coordinates return_to_junction();
    void back_track();
    void clean_up_back_track(Coordinates spot);
    void solve();

    bool have_been_here(Coordinates spot);
    int is_move_available(int row, int col);
    bool is_space_available(int row, int col);

};


#endif //ASSIGNMENT_2_MOVER_H
