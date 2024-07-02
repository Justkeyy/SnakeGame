#pragma once
#include "const10.h"
#include "field10.h"
#include "food10.h"
#include "SnakeInfo10.h"
//#define step
#define	stop __asm nop

struct gameStruct
{
	bool game_on = true;
	int TimeOut;
	snakeStruct snake_s = {};
	foodStruct food_s = {};
	fieldStruct field_s = {};
};

void init_game(gameStruct* game_s, int TimeOutTemp, int snakesize, int Rows, int Columns, int SnakeX, int SnakeY, char Keys);
void set_snake(gameStruct* game_s);
void clear_snake(gameStruct* game_s);
void check_eating(gameStruct* game_s);
void check_snake(gameStruct* game_s);
void set_food(gameStruct* game_s);
void check_game(gameStruct* game_s);
char handle_cmd(gameStruct* game_s);
void next_step(gameStruct* game_s);
void exec_game(gameStruct* game_s);
void generate_food(gameStruct* game_s);





