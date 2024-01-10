#include "Game.hpp"

Game::Game(const Vector &map)
    : m_map(map), m_score(0)
{
    // ���������
    srand((unsigned int)time(0));
    // �˵���ʼ��
    m_menu = &Menu::get();
}

Game &Game::get()
{
    // ��ȡ����
    static Game m_instace({26, 26});
    return m_instace;
}

void Game::run()
{
    int onceAgain = Yes;
    while (onceAgain == Yes)
    {
        // ѡ���Ѷ�
        m_menu->selectDifficulty();
        // ��ʼ��Ϸ
        Gamestart();
        // ��Ϸ����
        GameOver(onceAgain);
    }
}

void Game::Gamestart()
{
    // �ߣ���ʼ����������
    Snake snake = Snake(RIGHT, {{0, 0}, {1, 0}});
    // ƻ�������ݵ�ͼ���ߵ�λ�ô����������
    Apple apple = Apple(snake.getVector(), m_map);
    // �ٶȣ�ѡ���Ѷ��µ��ٶ�
    int speed = m_menu->getDifficulty().m_speed;
    // ��Ϸ������־
    bool isGameOver = false;
    // ���Ƶ�ͼ
    map(snake.getVector(), apple.getVector());
    // ���Ʋ˵�
    m_menu->print();

    // ��Ϸѭ��
    while (true)
    {
        // �����ٶ��ж�һ��
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));

        // ��ȡ��������W��A��S��D
        getDirectionFromKeyBoard(snake.getdirection());

        // ���ƶ�
        isGameOver = snake.move(m_map);

        // �Ƿ�Ե�ƻ��
        isEatApple(snake, apple);

        // ���·���
        m_menu->update(m_score);

        // ���ع��
        hideCursor();

        // ��Ϸ������������Ϸѭ��
        if (isGameOver)
            break;
    }
}

void Game::GameOver(int &onceAgain)
{
    setColor(3);
    setCursor({30, 15});
    std::cout << "Game Over!\n";
    setCursor({29, 21});
    std::cout << "�Ƿ�����һ�֣�\n";
    setBackColor();
    setCursor({28, 22});
    std::cout << "��";
    setColor(3);
    setCursor({36, 22});
    std::cout << "��";

    int key = 0;
    while (true)
    {
        while (_kbhit())
        {
            key = _getch();
        }

        switch (key)
        {
        case 75:
            if (onceAgain == No)
                onceAgain = Yes;
            setBackColor();
            setCursor({28, 22});
            std::cout << "��";
            setColor(3);
            setCursor({36, 22});
            std::cout << "��";
            break;

        case 77:
            if (onceAgain == Yes)
                onceAgain = No;
            setColor(3);
            setCursor({28, 22});
            std::cout << "��";
            setBackColor();
            setCursor({36, 22});
            std::cout << "��";
            break;

        default:
            break;
        }
        if (key == 13)
            break;
        else
            key = 0;
    }
    setColor(3);
    setCursor({27, 26});
}

void Game::map(const std::deque<Vector> &snake, const Vector &apple)
{
    // �����Ļ
    system("cls");

    // ���Ƶ�ͼ
    // ��Ϸ������ϱ߿�
    std::cout << "  \n  ";
    for (short i = -1; i < m_map.x + 1; i++)
    {
        printSquare({i, -1});
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "\n";

    // ÿһ�л���
    for (short y = 0; y < m_map.y; y++)
    {
        std::cout << "  ��";
        for (short x = 0; x < m_map.x; x++)
            printClear({x, y});
        std::cout << "��\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // ��Ϸ������±߿�
    std::cout << "  ";
    for (short i = -1; i < m_map.x + 1; i++)
        printSquare({i, m_map.y});
    std::cout << std::endl;

    // �߻���
    for (auto &it : snake)
        printCircular(it);

    // ƻ������
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

void Game::isEatApple(Snake &snake, Apple &apple)
{
    // �Ե�ƻ�������´���һ����ƻ�������·���
    if (snake.getVector().back() == apple.getVector())
    {
        apple = Apple(snake.getVector(), m_map);
        printApple(apple.getVector());
        m_score += 10;
    }
    // û�Ե�ƻ������ȥ��β��
    else
    {
        printClear(snake.getVector().front());
        snake.getVector().pop_front();
    }
}