//
// Created by nieme on 2022-02-16.
//

#ifndef ASSIGNMENT_2_COORDINATES_H
#define ASSIGNMENT_2_COORDINATES_H

#include <iostream>

class Coordinates {
private:
    int m_row;
    int m_col;
public:
    Coordinates(int row, int col);

    // Getters
    int get_row();
    int get_col();

    friend std::ostream& operator<<(std::ostream& output, Coordinates coordinates);
    bool operator!=(Coordinates coordinates);
    bool operator==(Coordinates coordinates);
};


#endif //ASSIGNMENT_2_COORDINATES_H
