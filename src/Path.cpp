//
// Created by nieme on 2022-02-16.
//

#include "Path.h"

void Path::push(Coordinates num) {
    auto new_spot = new Spot();
    new_spot->m_data = num;
    new_spot->m_next = m_top;
    m_top = new_spot;
}

Coordinates Path::peek() {
    if (m_top != nullptr) {
        return m_top->m_data;
    } else {
        return {-1, -1};
    }
}

void Path::pop() {
    if (m_top != nullptr) {
        auto node = m_top;
        m_top = m_top->m_next;
        delete node;
    } else {
        std::cout << "You gotta move forwards before ya can move backwards." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, Path &path) {
    auto node = path.m_top;
    while (node != nullptr) {
        output << node->m_data << std::endl;
        node = node->m_next;
    }
    return output;
}

// Feels like im defeating the purpose of the stack here, but this is used for determining if you have already landed on a spot before
Spot* Path::return_top() {
    if (m_top != nullptr){
        return m_top;
    } else {
        return nullptr;
    }
}


