#pragma once
const char Tail = '#'; // символ хвоста
const char Head = '@'; // символ головы
const char field_symbol = ' '; // символ поля
const char border_symbol = '*'; // символ границы
const int L = 50; // Максимальный размер змейки
enum dirrection {Left = 75, Right = 77, Up = 72, Down = 80, Esc = 27};
const char food_symbol = '+'; // символ еды