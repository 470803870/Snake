#pragma once
#include <deque>
#include <iostream>
#include "tools.hpp" 

enum directions
{
    // UP    W 119
    // DOWN  S 115
    // LEFT  A 97
    // RIGHT D 100
    UP = 119,
    DOWN = 115,
    LEFT = 97,
    RIGHT = 100
};

class Snake
{
private:
    std::deque<Vector> m_snake;
    int m_direction;

    const Vector getNext() const;
    bool GameOver(const Vector &next, const Vector &map) const;
    void addNext(const Vector &next);

public:
    Snake(const directions & direction, const std::deque<Vector> & snake)
        : m_direction(direction), m_snake(snake){}
    bool move(const Vector &map);
    std::deque<Vector> &getVector();
    int &getdirection();
};