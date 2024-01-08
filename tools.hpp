#pragma once
#include <Windows.h>
#include <iostream>
#include "Vector.hpp"

void setCursor(const Vector &vec);
void setColor(int color);
void setBackColor();
void hideCursor();
void printApple(const Vector &vec);
void printClear(const Vector &vec);
void printCircular(const Vector &vec);
void printSquare(const Vector &vec);

#define _PRINT_SQUARE   std::cout << "��";
#define _PRINT_CIRCULAR std::cout << "��";
#define _PRINT_APPLE    std::cout << "��";
#define _PRINT_CLEAR    std::cout << "  ";