#include "Snake.hpp"
void Snake::move(const int move, Vector &apple)
{
    if (move == UP || move == DOWN || move == LEFT || move == RIGHT)
        keyBoard = move;

    Vector next;
    switch (keyBoard)
    {
    case UP:
        next = idx[idx.size() - 1];
        --next.y;
        idx.push_back(next);
        if (next != apple)
            idx.erase(idx.begin());
        else
            apple = Vector(-1, -1);
        break;
    case DOWN:
        next = idx[idx.size() - 1];
        ++next.y;
        idx.push_back(next);
        if (next != apple)
            idx.erase(idx.begin());
        else
            apple = Vector(-1, -1);
        break;
    case LEFT:
        next = idx[idx.size() - 1];
        --next.x;
        idx.push_back(next);
        if (next != apple)
            idx.erase(idx.begin());
        else
            apple = Vector(-1, -1);
        break;
    case RIGHT:
        next = idx[idx.size() - 1];
        ++next.x;
        idx.push_back(next);
        if (next != apple)
            idx.erase(idx.begin());
        else
            apple = Vector(-1, -1);
        break;
    default:
        break;
    }
}