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
    // ��Ϸ������ϱ߿�
    for (size_t i = 0; i < 2 * width; i++)
        std::cout << "-";
    std::cout << "\n";

    // ����mapÿһ�л���
    for (size_t y = 0; y < height; y++)
    {
        std::cout << "|";
        for (size_t x = 0; x < width; x++)
        {
            if (m_map[x][y] == 0)
                std::cout << "  ";
            else if (m_map[x][y] == 1)
                std::cout << "��";
            else if (m_map[x][y] == 2)
                std::cout << "��";
        }
        std::cout << "|\n";
    }

    // ��Ϸ������±߿�
    for (size_t i = 0; i < 2 * width; i++)
        std::cout << "-";
    std::cout << std::endl;
}

void Game::map()
{
    // �����Ļ
    system("cls");

    // ��Ϸ����ȫ����Ϊ0
    for (size_t y = 0; y < height; y++)
        for (size_t x = 0; x < width; x++)
            m_map[x][y] = 0;
}

void Game::Snake()
{
    for (size_t i = 0; i < m_snake.idx.size(); i++)
    {
        // ����Snake��ÿһ�����ж��Ƿ��г��硢������ײ����Ϸ���������
        Vector snake = m_snake.idx[i];
        if (snake.x >= width || snake.x < 0 || snake.y >= height || snake.y < 0 || m_map[snake.x][snake.y] == 1)
        {
            // �����Ϸ����
            GameOver = true;
            break;
        }
        // ��map�б��Snake������
        m_map[snake.x][snake.y] = 1;
    }
}

void Game::Apple()
{
    // ���ƻ�����ԣ��������һ���µ�ƻ��
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
    // ƻ��û���ԣ���map�б��ƻ��������
    else
    {
        m_map[m_apple.x][m_apple.y] = 2;
    }
}

void Game::move()
{
    // ÿ0.5���ж�һ��
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // UP    W 119
    // DOWN  S 115
    // LEFT  A 97
    // RIGHT D 100
    // ��ȡ��������W��A��S��D
    int keyPress = 0;
    while (_kbhit())
    {
        keyPress = _getch();
    }
    // ����snake�ƶ��������
    m_snake.move(keyPress, m_apple);
}