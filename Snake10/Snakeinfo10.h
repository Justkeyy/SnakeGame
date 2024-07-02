#pragma once
//#include "game10.h"

struct snakeStruct
{
	int SnakeSize;
	int snake_x[L];
	int snake_y[L];
	char savedir;
	char kyes;
};

void init_snake(snakeStruct* snake_s, int FieldColumns, int FieldRows);
void move_snake(snakeStruct* snake_s);

