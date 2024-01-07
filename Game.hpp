#pragma once
#include "Snake.hpp" 
#include <chrono>
#include <thread>
#include <conio.h>
#include <cstdlib>
#include <ctime>

class Game
{
private:
    short height, width;
    Game(const short &height, const short &width);

public:
    static Game &get();
    void run();
    void map(const std::deque<Vector> &snake, const Vector &apple);
    void getDirection(int &direction);
};