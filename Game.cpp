#include "Game.hpp"

Game::Game(const int width, const int height)
    : GameOver(false), m_apple(Vector(-1, -1)), width(width), height(height),
      m_map(std::vector<std::vector<int>>(width, std::vector<int>(height, 0)))
{
    srand((unsigned int)time(0));
};

void Game::run()
{
    while (true)
    {
        map();
        Snake();
        Apple();
        draw();
        if (GameOver)
        {
            std::cout << "Game Over!" << std::endl;
            break;
        }
        move();
    }
}

void Game::draw()
{
    // 游戏界面的上边框
    for (size_t i = 0; i < 2 * width; i++)
        std::cout << "-";
    std::cout << "\n";

    // 根据map每一行绘制
    for (size_t y = 0; y < height; y++)
    {
        std::cout << "|";
        for (size_t x = 0; x < width; x++)
        {
            if (m_map[x][y] == 0)
                std::cout << "  ";
            else if (m_map[x][y] == 1)
                std::cout << "〇";
            else if (m_map[x][y] == 2)
                std::cout << "〇";
        }
        std::cout << "|\n";
    }

    // 游戏界面的下边框
    for (size_t i = 0; i < 2 * width; i++)
        std::cout << "-";
    std::cout << std::endl;
}

void Game::map()
{
    // 清空屏幕
    system("cls");

    // 游戏区域全部置为0
    for (size_t y = 0; y < height; y++)
        for (size_t x = 0; x < width; x++)
            m_map[x][y] = 0;
}

void Game::Snake()
{
    for (size_t i = 0; i < m_snake.idx.size(); i++)
    {
        // 根据Snake的每一个点判断是否有出界、自身碰撞等游戏结束的情况
        Vector snake = m_snake.idx[i];
        if (snake.x >= width || snake.x < 0 || snake.y >= height || snake.y < 0 || m_map[snake.x][snake.y] == 1)
        {
            // 标记游戏结束
            GameOver = true;
            break;
        }
        // 在map中标记Snake的坐标
        m_map[snake.x][snake.y] = 1;
    }
}

void Game::Apple()
{
    // 如果苹果被吃，随机生成一个新的苹果
    if (m_apple == Vector(-1, -1))
    {
        int random, x, y;
        while (true)
        {
            random = rand() % (width * height);
            x = random % width;
            y = random / width;
            if (m_map[x][y] != 1)
                break;
        }
        m_apple = Vector(x, y);
        m_map[x][y] = 2;
    }
    // 苹果没被吃，在map中标记苹果的坐标
    else
    {
        m_map[m_apple.x][m_apple.y] = 2;
    }
}

void Game::move()
{
    // 每0.5秒行动一格
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // UP    W 119
    // DOWN  S 115
    // LEFT  A 97
    // RIGHT D 100
    // 获取键盘输入W、A、S、D
    int keyPress = 0;
    while (_kbhit())
    {
        keyPress = _getch();
    }
    // 计算snake移动后的坐标
    m_snake.move(keyPress, m_apple);
}