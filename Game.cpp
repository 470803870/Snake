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
    // ƻ��
    Apple apple = Apple(snake.getVector(), height, width);
    // ����
    int direction = RIGHT;
    // ��Ϸ������־
    bool isGameOver = false;
    // ���Ƶ�ͼ
    map(snake.getVector(), apple.getVector());
    // ��Ϸѭ��
    while (true)
    {
        // ÿ0.5���ж�һ��
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // ��ȡ��������W��A��S��D
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
    // �����Ļ
    system("cls");

    // ���Ƶ�ͼ
    // ��Ϸ������ϱ߿�
    for (short i = 0; i < width + 2; i++)
        _PRINT_SQUARE;
    std::cout << "\n";

    // ÿһ�л���
    for (short y = 0; y < height; y++)
    {
        _PRINT_SQUARE;
        for (short x = 0; x < width; x++)
            _PRINT_CLEAR;
        _PRINT_SQUARE;
        std::cout << "\n";
    }

    // ��Ϸ������±߿�
    for (short i = 0; i < width + 2; i++)
        _PRINT_SQUARE;
    std::cout << std::endl;

    // snake����
    for (auto &it : snake)
    {
        setCursor(it);
        _PRINT_CIRCULAR;
    }

    // ƻ������
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
    // �����������WASD����ô���򲻱�
    // ��������෴Ҳ����
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