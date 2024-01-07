#pragma once
#include <deque>
#include "Vector.hpp"
#include "tools.hpp"
#include "Apple.hpp"
#include <iostream>

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

    Vector getNext(const int &direction);
    bool GameOver(const Vector &next, const short &height, const short &width) const;
    void Snake::drawNext(const Vector &next, Apple &apple, const short &height, const short &width);

public:
    Snake();
    bool move(Apple &apple, const int &direction, const short &height, const short &width);
    std::deque<Vector> getVector() const;
};