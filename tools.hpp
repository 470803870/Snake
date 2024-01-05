#pragma once
#include <Windows.h>
#include "vector.hpp"
#include <iostream>

void setCursor(const Vector &vec);

#define _PRINT_SQUARE   std::cout << "¡ö";
#define _PRINT_CIRCULAR std::cout << "¡ñ";
#define _PRINT_APPLE    std::cout << "¡ï";
#define _PRINT_CLEAR    std::cout << "  ";