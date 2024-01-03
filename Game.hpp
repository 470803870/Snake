#pragma once
#include "Snake.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

class Game
{
private:
    std::vector<std::vector<int>> m_map;
    int height, width;
    Snake m_snake;
    Vector m_apple;
    bool GameOver;

public:
    Game(const int height, const int width);
    void run();
    void draw();
    void Apple();
    void map();
    void Snake();
    void move();
};