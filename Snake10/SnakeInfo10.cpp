#include <iostream>
#include <conio.h>
#include "const10.h"
#include "winconsole10.h"
#include "Snakeinfo10.h"

void init_snake(snakeStruct* snake_s, int FieldColumns, int FieldRows)
{
	////////////////////////////////////////////////////////////////////
	//Заполнение значений массива координат змейки

	switch (snake_s->kyes)
	{
	case Left:
	{
		for (int i = 1; i <= snake_s->SnakeSize - 1; i++)
		{
			snake_s->snake_x[i] = snake_s->snake_x[i - 1] + 1;
			if (snake_s->snake_x[i] == (FieldColumns - 1))
			{
				snake_s->snake_x[i] = 1;
			}
			else if (snake_s->snake_x[i] == 0)
			{
				snake_s->snake_x[i] = (FieldColumns - 2);
			}
			snake_s->snake_y[i] = snake_s->snake_y[i - 1];
		}
		break;
	}
	case Right:
	{
		for (int i = 1; i <= snake_s->SnakeSize - 1; i++)
		{
			snake_s->snake_x[i] = snake_s->snake_x[i - 1] - 1;
			if (snake_s->snake_x[i] == (FieldColumns - 1))
			{
				snake_s->snake_x[i] = 1;
			}
			else if (snake_s->snake_x[i] == 0)
			{
				snake_s->snake_x[i] = (FieldColumns - 2);
			}
			snake_s->snake_y[i] = snake_s->snake_y[i - 1];
		}
		break;
	}
	case Up:
	{
		for (int i = 1; i <= snake_s->SnakeSize - 1; i++)
		{
			snake_s->snake_y[i] = snake_s->snake_y[i - 1] + 1;
			if (snake_s->snake_y[i] == (FieldRows - 1))
			{
				snake_s->snake_y[i] = 1;
			}
			else if (snake_s->snake_y[i] == 0)
			{
				snake_s->snake_y[i] = (FieldRows - 2);
			}
			snake_s->snake_x[i] = snake_s->snake_x[i - 1];
		}
		break;
	}
	case Down:
	{
		for (int i = 1; i <= snake_s->SnakeSize - 1; i++)
		{
			snake_s->snake_y[i] = snake_s->snake_y[i - 1] - 1;
			if (snake_s->snake_y[i] == (FieldRows - 1))
			{
				snake_s->snake_y[i] = 1;
			}
			else if (snake_s->snake_y[i] == 0)
			{
				snake_s->snake_y[i] = (FieldRows - 2);
			}
			snake_s->snake_x[i] = snake_s->snake_x[i - 1];
		}
		break;
	}
	}
	char* savep = &snake_s->savedir;
	*savep = snake_s->kyes;
}

void move_snake(snakeStruct* snake_s)
{
	int temp_x[L];
	int temp_y[L];
	for (int i = 0; i < L; i++)
	{
		temp_x[i] = snake_s->snake_x[i];
		temp_y[i] = snake_s->snake_y[i];
	}

	switch (snake_s->savedir)
	{
	case Left:
	{
		snake_s->snake_x[0] = snake_s->snake_x[0] - 1;
		snake_s->snake_y[0] = snake_s->snake_y[0];

		for (int i = 1; i < snake_s->SnakeSize; i++)
		{
			snake_s->snake_x[i] = temp_x[i-1];
			snake_s->snake_y[i] = temp_y[i-1];
		}
		break;
	}
	case Right:
	{
		snake_s->snake_x[0] = snake_s->snake_x[0] + 1;
		snake_s->snake_y[0] = snake_s->snake_y[0];

		for (int i = 1; i < snake_s->SnakeSize; i++)
		{
			snake_s->snake_x[i] = temp_x[i - 1];
			snake_s->snake_y[i] = temp_y[i - 1];
		}
		break;
	}
	case Up:
	{
		snake_s->snake_x[0] = snake_s->snake_x[0];
		snake_s->snake_y[0] = snake_s->snake_y[0] - 1;

		for (int i = 1; i < snake_s->SnakeSize; i++)
		{
			snake_s->snake_x[i] = temp_x[i - 1];
			snake_s->snake_y[i] = temp_y[i - 1];
		}
		break;
	}
	case Down:
	{
		snake_s->snake_x[0] = snake_s->snake_x[0];
		snake_s->snake_y[0] = snake_s->snake_y[0] + 1;

		for (int i = 1; i < snake_s->SnakeSize; i++)
		{
			snake_s->snake_x[i] = temp_x[i - 1];
			snake_s->snake_y[i] = temp_y[i - 1];
		}
		break;
	}
	}
}
