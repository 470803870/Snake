#pragma once
#include <deque>
#include "vector.hpp"
#include "tools.hpp"
#include "apple.hpp"
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
public:
    static bool move(std::deque<Vector> &snake, Vector &apple, const int &direction, const short &height, const short &width);
};