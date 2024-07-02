#include <conio.h>
#include <iostream>
#include <windows.h>

#include "const10.h"
#include "SnakeInfo10.h"
#include "field10.h"
#include "food10.h"
#include "game10.h"


void init_game(gameStruct* game_s, int TimeOutTemp, int snakesize, int Rows, int Columns, int SnakeX, int SnakeY, char Keys)
{
system("cls");
#ifdef step

#else
	game_s->TimeOut = TimeOutTemp;
#endif

	game_s->snake_s.SnakeSize = snakesize;
	game_s->snake_s.snake_x[0] = SnakeX;
	game_s->snake_s.snake_y[0] = SnakeY;
	game_s->snake_s.kyes = Keys;
	game_s->field_s.FieldColumns = Columns;
	game_s->field_s.FieldRows = Rows;

	init_field(&game_s->field_s);
	init_snake(&game_s->snake_s, game_s->field_s.FieldColumns, game_s->field_s.FieldRows);
	init_food(&game_s->food_s);
	set_snake(game_s);
	print_field(&game_s->field_s);
}

void next_step(gameStruct* game_s)
{
	set_food(game_s);
	clear_snake(game_s);
	check_eating(game_s);
	move_snake(&game_s->snake_s);
	check_snake(game_s);
	set_snake(game_s);
	print_field(&game_s->field_s);
	check_game(game_s);
}

void exec_game(gameStruct* game_s)
{
	game_s->snake_s.savedir = handle_cmd(game_s);
	do
	{
		next_step(game_s);
#ifdef step
	game_s->snake_s.savedir = handle_cmd(game_s);
#else 
		Sleep(game_s->TimeOut);
		if (_kbhit())
		{
			game_s->snake_s.savedir = handle_cmd(game_s);
		}
#endif 
	} while (game_s->game_on);

}

void set_snake(gameStruct* game_s)
{
	for (int i = 1; i <= (game_s->snake_s.SnakeSize - 1); i++)
	{
		game_s->field_s.field[game_s->snake_s.snake_y[i]][game_s->snake_s.snake_x[i]] = Tail;
	}
	
	game_s->field_s.field[game_s->snake_s.snake_y[0]][game_s->snake_s.snake_x[0]] = Head;
}

void clear_snake(gameStruct* game_s)
{
	for (int i = 0; i <= (game_s->snake_s.SnakeSize - 1); ++i)
	{
		game_s->field_s.field[game_s->snake_s.snake_y[i]][game_s->snake_s.snake_x[i]] = field_symbol;
	}
}

void generate_food(gameStruct* game_s)
{
	while (!game_s->food_s.food_flag)
	{
		int R1 = (rand() % (game_s->field_s.FieldColumns - 2));
		int R2 = (rand() % (game_s->field_s.FieldRows - 2));
		if (game_s->field_s.field[R2][R1] == field_symbol)
		{
			game_s->food_s.food_x = R1;
			game_s->food_s.food_y = R2;
			game_s->food_s.food_flag = true;
		}
	}
}

void set_food(gameStruct* game_s)
{
	if (game_s->snake_s.SnakeSize < ((game_s->field_s.FieldRows - 2) * (game_s->field_s.FieldColumns - 2)))
	{
		generate_food(game_s);
		game_s->field_s.field[game_s->food_s.food_y][game_s->food_s.food_x] = food_symbol;
	}
	else
	{
		game_s->game_on = false;
	}
}

void check_eating(gameStruct* game_s)
{
	if (game_s->food_s.food_x == game_s->snake_s.snake_x[0] && game_s->food_s.food_y == game_s->snake_s.snake_y[0])
	{
		game_s->food_s.food_flag = false;
		++game_s->snake_s.SnakeSize;
		switch (game_s->snake_s.savedir)
		{
		case Left:
		{
			game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 2] + 1;
			game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 2];
			break;
		}
		case Right:
		{
			game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 2] - 1;
			game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 2];
			break;
		}
		case Up:
		{
			game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 2] - 1;
			game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 2];
			break;
		}
		case Down:
		{
			game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_y[game_s->snake_s.SnakeSize - 2] - 1;
			game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 1] = game_s->snake_s.snake_x[game_s->snake_s.SnakeSize - 2];
			break;
		}
		}
	};
}
	
void check_snake(gameStruct* game_s) // Проверка на совпадение с границей
{
	for (int i = 0; i <= (game_s->snake_s.SnakeSize - 1); i++)
	{
		if (game_s->snake_s.snake_x[i] == 0) // left
		{
			game_s->snake_s.snake_x[i] = game_s->field_s.FieldColumns - 2;
		}
		else if (game_s->snake_s.snake_x[i] == (game_s->field_s.FieldColumns - 1)) //right
		{
			game_s->snake_s.snake_x[i] = 1;
		}
	};
	for (int i = 0; i <= (game_s->snake_s.SnakeSize - 1); i++)
	{
		if (game_s->snake_s.snake_y[i] == 0) // Down
		{
			game_s->snake_s.snake_y[i] = game_s->field_s.FieldRows - 2;
		}
		else if (game_s->snake_s.snake_y[i] == (game_s->field_s.FieldRows - 1)) //Up
		{
			game_s->snake_s.snake_y[i] = 1;
		}
	};
}

char handle_cmd(gameStruct* game_s)
{

	char kyes1 = _getch();
	if (kyes1 == Esc)
	{
		game_s->game_on = false;
	}
	else if (kyes1 == -32)
	{
		kyes1 = _getch();
	}
	// Проверка на разворот на 180 градусов
	if ((game_s->snake_s.savedir == 75 && kyes1 == 77) || (game_s->snake_s.savedir == 77 && kyes1 == 75))
	{
		kyes1 = game_s->snake_s.savedir;
	}

	if ((game_s->snake_s.savedir == 72 && kyes1 == 80) || (game_s->snake_s.savedir == 80 && kyes1 == 72))
	{
		kyes1 = game_s->snake_s.savedir;
	}

	return kyes1;
}

void check_game(gameStruct* game_s)
{
	if (game_s->snake_s.SnakeSize == (L -1))
	{
		game_s->game_on = false;
	}

	for (int i = 1; i < L; i++)
	{
			if ((game_s->snake_s.snake_y[0] == game_s->snake_s.snake_y[i]) && (game_s->snake_s.snake_x[0] == game_s->snake_s.snake_x[i]))
			{
				game_s->game_on = false;
			}
	}
}


