#pragma once
#include "Snake.hpp"
#include "Apple.hpp"
#include "Menu.hpp"
#include <chrono>
#include <thread>
#include <conio.h>
#include <cstdlib>
#include <ctime>

class Game
{
private:
    Vector m_map; 
    int m_score;
    Menu *m_menu;
    
    Game(const Vector & map);
    void Gamestart();
    void map(const std::deque<Vector> &snake, const Vector &apple);
    void getDirectionFromKeyBoard(int &direction); 
    void isEatApple(Snake &snake, Apple &apple);

public:
    static Game &get();
    void run();
};