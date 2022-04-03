//
// Created by nieme on 2022-02-16.
//

#ifndef ASSIGNMENT_2_PATH_H
#define ASSIGNMENT_2_PATH_H

#include <iostream>
#include "Coordinates.h"

class Spot {
public:
    Coordinates m_data {-1, -1};
    Spot *m_next {nullptr};
};

class Path {
private:
    Spot *m_top {nullptr};
public:
    Path() = default;
    virtual ~Path() = default;

    // General stack methods
    void push(Coordinates num);
    Coordinates peek();
    void pop();

    // This was for traversing the failed path looking for a match
    Spot* return_top();

    friend std::ostream& operator<<(std::ostream &output, Path &path);
};


#endif //ASSIGNMENT_2_PATH_H
