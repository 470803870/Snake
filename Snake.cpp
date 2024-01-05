#include "Snake.hpp"
bool Snake::move(std::deque<Vector> &snake, Vector &apple, const int &direction, const short &height, const short &width)
{
    bool GameOver = false;
    // ����snake�ƶ��������
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

    // �ƶ���������Ƿ��������ǽ��
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

    // �����ƶ����snake
    setCursor(next);
    _PRINT_CIRCULAR;
    snake.push_back(next);

    // �Ե�ƻ�������´���һ����ƻ��
    if (next == apple)
    {
        apple = apple::createApple(snake, height, width);
        setCursor(apple);
        _PRINT_APPLE;
    }
    // û�Ե�ƻ����snakeȥ��β��
    else
    {
        setCursor(snake.front());
        _PRINT_CLEAR;
        snake.pop_front();
    }
    setCursor({-1, height});
    return GameOver;
}