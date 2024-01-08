#include "Game.hpp"

Game::Game(const Vector &map)
    : m_map(map), m_score(0)
{
    // 随机数种子
    srand((unsigned int)time(0));
    // 菜单初始化
    m_menu = &Menu::get();
}

Game &Game::get()
{
    // 获取单例
    static Game m_instace({26, 26});
    return m_instace;
}

void Game::run()
{
    // 选择难度
    m_menu->selectDifficulty();
    // 开始游戏
    Gamestart();
}

void Game::Gamestart()
{
    // 蛇：初始化方向、坐标
    Snake snake = Snake(RIGHT, {{0, 0}, {1, 0}});
    // 苹果：根据地图和蛇的位置创建随机坐标
    Apple apple = Apple(snake.getVector(), m_map);
    // 速度：选择难度下的速度
    int speed = m_menu->getDifficulty().m_speed;
    // 游戏结束标志
    bool isGameOver = false;
    // 绘制地图
    map(snake.getVector(), apple.getVector());
    // 绘制菜单
    m_menu->print();

    // 游戏循环
    while (true)
    {
        // 根据速度行动一格
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));

        // 获取键盘输入W、A、S、D
        getDirectionFromKeyBoard(snake.getdirection());

        // 蛇移动
        isGameOver = snake.move(m_map);

        // 是否吃到苹果
        isEatApple(snake, apple);

        // 更新分数
        m_menu->update(m_score);

        // 隐藏光标
        hideCursor();

        // 游戏结束则跳出游戏循环，打印Game Over
        if (isGameOver)
        {
            setCursor({27, 26});
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
    std::cout << "  \n  ";
    for (short i = -1; i < m_map.x + 1; i++)
    {
        printSquare({i, -1});
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "\n";

    // 每一行绘制
    for (short y = 0; y < m_map.y; y++)
    {
        std::cout << "  ■";
        for (short x = 0; x < m_map.x; x++)
            printClear({x, y});
        std::cout << "■\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // 游戏界面的下边框
    std::cout << "  ";
    for (short i = -1; i < m_map.x + 1; i++)
        printSquare({i, m_map.y});
    std::cout << std::endl;

    // 蛇绘制
    for (auto &it : snake)
        printCircular(it);

    // 苹果绘制
    printApple(apple);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void Game::getDirectionFromKeyBoard(int &direction)
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

void Game::isEatApple(Snake &snake, Apple &apple)
{
    // 吃到苹果，重新创建一个新苹果，更新分数
    if (snake.getVector().back() == apple.getVector())
    {
        apple = Apple(snake.getVector(), m_map);
        printApple(apple.getVector());
        m_score += 10;
    }
    // 没吃到苹果，蛇去掉尾部
    else
    {
        printClear(snake.getVector().front());
        snake.getVector().pop_front();
    }
}