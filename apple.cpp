#include "apple.hpp"

Vector apple::createApple(const std::deque<Vector> &snake, const short &height, const short &width)
{
    short random, x, y;
    bool notNull;
    while (true)
    {
        notNull = false;
        random = rand() % (width * height);
        x = random % width;
        y = random / width;
        for (auto it : snake)
        {
            if (it == Vector({x, y}))
                notNull = true;
        }
        if (!notNull)
            break;
    }
    return {x, y};
}