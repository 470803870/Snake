#include "Snake.hpp"
Snake::Snake()
{
    m_snake = std::deque<Vector>({{0, 0}, {1, 0}});
}

bool Snake::move(Apple &apple, const int &direction, const short &height, const short &width)
{

    // 计算snake移动后的坐标
    const Vector next = getNext(direction);

    // 移动后的坐标是否是自身或墙壁
    bool isGameOver = GameOver(next, height, width);

    // 绘制移动后的snake、苹果
    drawNext(next, apple, height, width);

    return isGameOver;
}

const Vector Snake::getNext(const int &direction) const
{
    Vector next = m_snake.back();
    switch (direction)
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

bool Snake::GameOver(const Vector &next, const short &height, const short &width) const
{
    bool GameOver = false;

    if (next.x >= width || next.x < 0 || next.y >= height || next.y < 0)
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

void Snake::drawNext(const Vector &next, Apple &apple, const short &height, const short &width)
{
    // 画出snake的下一格
    setCursor(next);
    _PRINT_CIRCULAR;
    m_snake.push_back(next);

    // 吃到苹果，重新创建一个新苹果
    if (next == apple.getVector())
    {
        apple = Apple(m_snake, height, width);
        setCursor(apple.getVector());
        _PRINT_APPLE;
    }
    // 没吃到苹果，snake去掉尾部
    else
    {
        setCursor(m_snake.front());
        _PRINT_CLEAR;
        m_snake.pop_front();
    }

    setCursor({-1, height});
}

const std::deque<Vector> &Snake::getVector() const
{
    return m_snake;
}