#include "Game.hpp"

Game::Game(const short &width, const short &height)
    : width(width), height(height)
{
    srand((unsigned int)time(0));
}

Game& Game::get()
{
    static Game m_instace(16, 16);
    return m_instace;
}

void Game::run()
{
    // snake
    Snake snake = Snake();
    // 苹果
    Apple apple = Apple(snake.getVector(), height, width);
    // 方向
    int direction = RIGHT;
    // 游戏结束标志
    bool isGameOver = false;
    // 绘制地图
    map(snake.getVector(), apple.getVector());
    // 游戏循环
    while (true)
    {
        // 每0.5秒行动一格
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // 获取键盘输入W、A、S、D
        getDirection(direction);

        isGameOver = snake.move(apple, direction, height, width);

        if (isGameOver)
        {
            setCursor({-1, (short)(height + 1)});
            std::cout << "Game Over!" << std::endl;
            break;
        }
    }
}

void Game::map(const std::deque<Vector> &snake, const Vector &apple)
{
    // 清空屏幕
    system("cls");

    // 绘制地图
    // 游戏界面的上边框
    for (short i = 0; i < width + 2; i++)
        _PRINT_SQUARE;
    std::cout << "\n";

    // 每一行绘制
    for (short y = 0; y < height; y++)
    {
        _PRINT_SQUARE;
        for (short x = 0; x < width; x++)
            _PRINT_CLEAR;
        _PRINT_SQUARE;
        std::cout << "\n";
    }

    // 游戏界面的下边框
    for (short i = 0; i < width + 2; i++)
        _PRINT_SQUARE;
    std::cout << std::endl;

    // snake绘制
    for (auto &it : snake)
    {
        setCursor(it);
        _PRINT_CIRCULAR;
    }

    // 苹果绘制
    setCursor(apple);
    _PRINT_APPLE;

    setCursor({-1, height});
}

void Game::getDirection(int &direction)
{
    int key = 0;
    while (_kbhit())
    {
        key = _getch();
    }
    // 如果按键不是WASD，那么方向不变
    // 如果方向相反也不变
    switch (key)
    {
    case UP:
        if (direction != DOWN)
            direction = key;
        break;
    case DOWN:
        if (direction != UP)
            direction = key;
        break;
    case LEFT:
        if (direction != RIGHT)
            direction = key;
        break;
    case RIGHT:
        if (direction != LEFT)
            direction = key;
        break;
    default:
        break;
    }
}