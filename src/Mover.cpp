//
// Created by nieme on 2022-02-16.
//

#include "Mover.h"

Mover::Mover() {
    m_row = 0;
    m_col = 0;
}

Mover::~Mover() {

}

void Mover::move(int row, int col) {
    // Move spot
    this->m_row = row;
    this->m_col = col;

    // Write # sign on new spot
    this->maze.write(m_row, m_col, '#');


}

// Helper function add a space to the path as needed
void Mover::add_to_path(int row, int col) {
    Coordinates spot = {row, col};
    this->path.push(spot);
}

// function to determine movement direction
void Mover::search_for_move() {
    int move_code = is_move_available(this->get_row(), this->get_col());
    switch (move_code) {
        // Move right
        case 1:
            add_to_path(m_row, m_col);
            move(this->get_row(), this->get_col()+1);
            break;
        // Move Down
        case 2:
            add_to_path(m_row, m_col);
            move(this->get_row()+1, this->get_col());
            break;
        // Move Left
        case 3:
            add_to_path(m_row, m_col);
            move(this->get_row(), this->get_col()-1);
            break;
        // Move Up
        case 4:
            add_to_path(m_row, m_col);
            move(this->get_row()-1, this->get_col());
            break;
        default:
            break;
    }
}

// Function to return a number depending on which direction a move is available
int Mover::is_move_available(int row, int col) {
    // look right col+1
    if (is_space_available(row, col+1)) {
        return 1;
    }// then down row+1
    else if (is_space_available(row+1, col)) {
        return 2;
    } // then left col-1
    else if (is_space_available(row, col-1))     {
        return 3;
    } // then up row-1
    else if (is_space_available(row-1, col)) {
        return 4;
    }
    else {
        return -1;
    }
}

// Function to check if a space satisfies specific criteria for movement
bool Mover::is_space_available(int row, int col) {
    Coordinates temp = Coordinates(row, col);
    Coordinates most_recent = this->backtrack_path.peek();
    if (this->maze.get_char(row, col) != '+'
        && this->maze.get_char(row, col) != '-'
        && this->maze.get_char(row, col) != '|'
        && this->maze.get_char(row, col) != '#'
        && (temp != most_recent)
        && !have_been_here(temp)) {
        return true;
    } else {
        return false;
    }
}

// A function to evaluate if you have been here before. Return true if you have, otherwise return false
bool Mover::have_been_here(Coordinates spot) {
    auto space = this->backtrack_path.return_top();
    while (space != nullptr) {
        if (space->m_data != spot) {
            space = space->m_next;
        } else {
            return true;
        }
    }
    return false;
}

void Mover::back_track() {
    // Get the top of the path
    auto top = this->path.peek();

    // Get current spot
    Coordinates current_spot = Coordinates(this->get_row(), this->get_col());

    // While the current spot is not a junction
    while (is_move_available(current_spot.get_row(), current_spot.get_col()) == -1) {

        // Clear space mover is currently resting on
        this->maze.write(current_spot.get_row(), current_spot.get_col(), ' ');

        // Push current spot onto failed path stack
        this->backtrack_path.push(current_spot);

        // Move to next spot
        this->move(top.get_row(), top.get_col());

        // Pop spot from path stack
        this->path.pop();

        // Reset to new top of path stack
        top = this->path.peek();

        // Reset current location
        current_spot = Coordinates(this->get_row(), this->get_col());
    }
}

void Mover::solve() {
    // This is the maze exit, the bottom right corner
    Coordinates exit = Coordinates(49, 50);
    Coordinates current_spot = Coordinates(this->get_row(), this->get_col());
    // set a while loop for the exit condition, so it keeps going until solved
    while (exit != current_spot) {
        // Keep going until you can find no acceptable moves
        while(is_move_available(this->get_row(), this->get_col()) != -1) {
            this->search_for_move();
            current_spot = Coordinates(this->get_row(), this->get_col());
            if (exit == current_spot) {
                break;
            }
        }
        // When there are no more acceptable moves, backtrack to the last crossroads
        back_track();
    }
}

int Mover::get_row() {
    return this->m_row;
}

int Mover::get_col() {
    return this->m_col;
}



