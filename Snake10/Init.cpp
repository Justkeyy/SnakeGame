#include<iostream>
#include <conio.h>
#include "Init.h"

void pre_init_game(gameStruct* game_s, int& TimeOutTemp, int& snakesizeTemp, int& FieldRowsTemp, int& FieldColumnsTemp, int& InitSnakeX, int& InitSnakeY, char& KeysTemp)
{
#ifdef step

#else
	std::cout << "Enter initial game parametrs" << "\n";
	std::cout << "TimeOut (< 100 ms) = " << "\n";
	do
	{
		std::cin >> TimeOutTemp;
	} while (TimeOutTemp < 100);
#endif

	std::cout << "Enter game field parametrs: X & Y lenght :" << "\n";
	std::cout << "Minimal X lenght = 5, maximal X lenght = 25. Your X lenght = " << "\n";
	do
	{
		std::cin >> FieldColumnsTemp;
		if (FieldColumnsTemp >= 5 && FieldColumnsTemp <= 25)
		{
			break;
		}
		else
		{
			std::cout << "Wrong value! \n";
		}
	} while (1);

	std::cout << "Minimal Y lenght = 5, maximal Y lenght = 25. Your Y lenght = " << "\n";
	do
	{
		std::cin >> FieldRowsTemp;
		if (FieldRowsTemp >= 5 && FieldRowsTemp <= 25)
		{
			break;
		}
		else
		{
			std::cout << "Wrong value! \n";
		}
	} while (1);

	std::cout << "Enter initial snake size > 0 (1, 2, ... 5)" << "\n";
	do
	{
		std::cin >> snakesizeTemp;
		if (snakesizeTemp <= 0 || snakesizeTemp > 5)
		{
			std::cout << "Incorrect size!" << "\n";
		}
		else
		{
			break;
		}
	} while (1);

	std::cout << "Enter initial vertical position of snake" << "\n";

	do
	{
		std::cin >> InitSnakeX;
		if (InitSnakeX <= 0 || InitSnakeX >= (FieldColumnsTemp - 1))
		{
			std::cout << "Incorrect location!" << "\n";
		}
		else
		{
			break;
		}
	} while (1);

	std::cout << "Enter initial horizontal position of snake" << "\n";

	do
	{
		std::cin >> InitSnakeY;
		if (InitSnakeY <= 0 || InitSnakeY >= (FieldRowsTemp - 1))
		{
			std::cout << "Incorrect location!" << "\n";
		}
		else
		{
			break;
		}
	} while (1);


	std::cout << "Enter initial movement dirrection (arrows: left or right) or ESC for quit" << "\n";
	bool notenter = true;
	do {
		KeysTemp = _getch();
		if (KeysTemp == Esc)
		{

		}

		else if (KeysTemp == -32)

		{
			KeysTemp = _getch();
		}
		KeysTemp = static_cast <unsigned int> (KeysTemp);

		switch (KeysTemp)
		{
		case Left:
			notenter = false;
			break;
		case Right:
			notenter = false;
			break;
		case Up:
			notenter = false;
			break;
		case Down:
			notenter = false;
			break;
		case Esc:
			std::cout << "Game over!" << "\n";
			notenter = false;
			game_s->game_on = false;
			exit(1);
		default:
			std::cout << "Not correct key!" << "\n";
		}
	} while (notenter);
}
