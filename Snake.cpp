#include "Snake.hpp"

bool Snake::move(const Vector &m_map)
{
    // 计算蛇移动后的坐标
    const Vector next = getNext();

    // 移动后的坐标是否是自身或墙壁
    bool isGameOver = GameOver(next, m_map);

    // 绘制移动后的格子
    printCircular(next);

    // 增加坐标
    addNext(next);

    // 返回是否结束游戏
    return isGameOver;
}

const Vector Snake::getNext() const
{
    Vector next = m_snake.back();
    switch (m_direction)
    {
    case UP:
        --next.y;
        break;
    case DOWN:
        ++next.y;
        break;
    case LEFT:
        --next.x;
        break;
    case RIGHT:
        ++next.x;
        break;
    default:
        break;
    }
    return next;
}

bool Snake::GameOver(const Vector &next, const Vector &map) const
{
    bool GameOver = false;

    if (next.x >= map.x || next.x < 0 || next.y >= map.y || next.y < 0)
    {
        GameOver = true;
    }

    for (auto it : m_snake)
    {
        if (it == next)
        {
            GameOver = true;
            break;
        }
    }

    return GameOver;
}

std::deque<Vector> &Snake::getVector()
{
    return m_snake;
}

void Snake::addNext(const Vector &next)
{
    m_snake.push_back(next);
}

int &Snake::getdirection()
{
    return m_direction;
}