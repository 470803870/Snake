#pragma once
#include <Windows.h>
#include "vector.hpp"
#include <iostream>

void setCursor(const Vector &vec);

#define _PRINT_SQUARE   std::cout << "��";
#define _PRINT_CIRCULAR std::cout << "��";
#define _PRINT_APPLE    std::cout << "��";
#define _PRINT_CLEAR    std::cout << "  ";