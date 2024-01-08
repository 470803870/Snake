#include "tools.hpp"

void setCursor(const Vector &vec)
{
    COORD position = {(vec.x + 2) * 2, vec.y + 2};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE |
                                                            BACKGROUND_BLUE |
                                                            BACKGROUND_GREEN |
                                                            BACKGROUND_RED);
}

void hideCursor()
{
    setCursor({-1, 27});
}

void printApple(const Vector &vec)
{
    setCursor(vec);
    _PRINT_APPLE
}

void printClear(const Vector &vec)
{
    setCursor(vec);
    _PRINT_CLEAR
}

void printCircular(const Vector &vec)
{
    setCursor(vec);
    _PRINT_CIRCULAR
}

void printSquare(const Vector &vec)
{
    setCursor(vec);
    _PRINT_SQUARE
}
