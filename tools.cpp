#include "tools.hpp"

void setCursor(const Vector &vec)
{
    COORD position = {(vec.x + 1) * 2, vec.y + 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}