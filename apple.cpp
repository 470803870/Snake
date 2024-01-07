#include "Apple.hpp"

Apple::Apple(const std::deque<Vector> &m_snake, const short &height, const short &width)
{
    short random, x, y;
    bool notNull;
    while (true)
    {
        notNull = false;
        random = rand() % (width * height);
        x = random % width;
        y = random / width;
        for (auto it : m_snake)
        {
            if (it == Vector({x, y}))
                notNull = true;
        }
        if (!notNull)
            break;
    }
    m_apple = Vector(x, y);
}

const Vector Apple::getVector() const
{
    return m_apple;
}

void Apple::operator=(const Apple &apple)
{
    m_apple = apple.getVector();
}