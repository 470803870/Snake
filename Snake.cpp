#include "Snake.hpp"
bool Snake::move(std::deque<Vector> &snake, Vector &apple, const int &direction, const short &height, const short &width)
{
    bool GameOver = false;
    // 计算snake移动后的坐标
    Vector next = snake.back();
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

    // 移动后的坐标是否是自身或墙壁
    if (next.x >= width || next.x < 0 || next.y >= height || next.y < 0)
    {
        GameOver = true;
    }

    for (auto it : snake)
    {
        if (it == next)
        {
            GameOver = true;
            break;
        }
    }

    // 绘制移动后的snake
    setCursor(next);
    _PRINT_CIRCULAR;
    snake.push_back(next);

    // 吃到苹果，重新创建一个新苹果
    if (next == apple)
    {
        apple = apple::createApple(snake, height, width);
        setCursor(apple);
        _PRINT_APPLE;
    }
    // 没吃到苹果，snake去掉尾部
    else
    {
        setCursor(snake.front());
        _PRINT_CLEAR;
        snake.pop_front();
    }
    setCursor({-1, height});
    return GameOver;
}