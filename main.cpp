#include <iostream>
#include "Game.hpp"
#include "Snake.hpp"


int main()
{
    Game myGame = Game(16, 16);
    myGame.run();
    return 0;
}