#pragma once
#include "tools.hpp"
#include <conio.h>
#include <unordered_map>

enum level
{
    I,
    II,
    III,
    IV
};

enum again
{
    Yes,
    No
};

struct difficulty
{
public:
    std::string m_string;
    int m_speed;

public:
    difficulty() : m_string(""), m_speed(500) {}
    difficulty(const std::string &string, int speed)
        : m_string(string), m_speed(speed) {}
};

class Menu
{
private:
    int m_level;
    std::unordered_map<int, difficulty> m_difficulty;

    Menu();

public:
    static Menu &get();
    int selectDifficulty();
    const difficulty getDifficulty() const;
    void print();
    void update(int m_score);
};