#include "Menu.hpp"

Menu::Menu() : m_level(I), m_difficulty()
{
    m_difficulty = {{I, difficulty("简单模式", 500)},
                    {II, difficulty("普通模式", 400)},
                    {III, difficulty("困难模式", 300)},
                    {IV, difficulty("炼狱模式", 200)}};
}

Menu &Menu::get()
{
    static Menu instance;
    return instance;
} 

int Menu::selectDifficulty()
{
    setColor(3);
    std::cout << "请选择游戏难度：\n";
    std::cout << "（上下键选择，回车确认）\n";
    for (auto &it : m_difficulty)
    {
        if (it.first == m_level)
            setBackColor();
        else
            setColor(3);
        setCursor(Vector({-1, (short)(it.first + 3)}));
        std::cout << it.second.m_string;
    }

    while (true)
    {
        int key = _getch();
        while (_kbhit())
        {
            key = _getch();
        }
        switch (key)
        {
        case 72:
            if (m_level != I)
                --m_level;
            break;
        case 80:
            if (m_level != IV)
                ++m_level;
            break;
        default:
            break;
        }

        for (auto &it : m_difficulty)
        {
            if (it.first == m_level)
                setBackColor();
            else
                setColor(3);
            setCursor(Vector({-1, (short)(it.first + 3)}));
            std::cout << it.second.m_string;
        }

        if (key == 13)
            break;
    }

    return m_level;
}

const difficulty Menu::getDifficulty() const
{
    for (auto it : m_difficulty)
    {
        if (it.first == m_level)
            return it.second;
    }
    return {};
}

void Menu::print()
{
    setCursor({29, 0});
    std::cout << "贪吃蛇";
    setCursor({27, 1});
    std::cout << "难度：";
    setCursor({32, 2});
    std::cout << m_difficulty[m_level].m_string;
    setCursor({32, 3});
    std::cout << "得分：";
    setCursor({32, 4});
    std::cout << "0";
}

void Menu::update(int m_score)
{
    setCursor({32, 4});
    std::cout << m_score;
}