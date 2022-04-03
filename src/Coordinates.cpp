//
// Created by nieme on 2022-02-16.
//

#include "Coordinates.h"

Coordinates::Coordinates(int row, int col) : m_row(row), m_col(col) {}

std::ostream &operator<<(std::ostream &output, Coordinates coordinates) {
    output << "Row: " << coordinates.m_row << " Col: " << coordinates.m_col << std::endl;
    return output;
}

int Coordinates::get_row() {
    return this->m_row;
}

int Coordinates::get_col() {
    return this->m_col;
}

bool Coordinates::operator!=(Coordinates coordinates) {
    return (this->m_row != coordinates.m_row) || (this->m_col != coordinates.m_col);
}

bool Coordinates::operator==(Coordinates coordinates) {
    return (this->m_row == coordinates.m_row) && (this->m_col == coordinates.m_col);
}

