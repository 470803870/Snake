#pragma once
#include <vector>

enum moves
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

struct Vector
{
    int x, y;
    Vector() : x(0), y(0) {}
    Vector(const int x, const int y) : x(x), y(y) {}
    bool operator==(const Vector &other)
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector &other)
    {
        return !(x == other.x && y == other.y);
    }
    void operator=(const Vector &other)
    {
        x = other.x;
        y = other.y;
    }
};

class Snake
{
public:
    std::vector<Vector> idx;

private:
    int keyBoard;

public:
    Snake() : idx({{0, 0}, {1, 0}}), keyBoard(RIGHT){};
    void move(const int move, Vector &apple);
};