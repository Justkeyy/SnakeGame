#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

#include "const10.h"
#include "game10.h"
#include "SnakeInfo10.h"
#include "field10.h"
#include "food10.h"
#include "winconsole10.h"
#include "Init.h"

using namespace std; // использую проостранство имен std для потокового ввода-вывода
/***************************************************************/

int main()
{
	srand(time(NULL));

	gameStruct game_s = {};
	int TimeOutTemp = 100;
	int snakesizeTemp = 0;
	int FieldRowsTemp = 0;
	int FieldColumnsTemp = 0;
	int InitSnakeX = 1;
	int InitSnakeY = 1;
	char KeysTemp;

	pre_init_game(&game_s, TimeOutTemp, snakesizeTemp, FieldRowsTemp, FieldColumnsTemp, InitSnakeX, InitSnakeY, KeysTemp);

///////////////////////////////////////////////////////////////////////////

	init_game(&game_s, TimeOutTemp, snakesizeTemp, FieldRowsTemp, FieldColumnsTemp, InitSnakeX, InitSnakeY, KeysTemp); // Инициализация игрового поля

	std::cout << "Press any key to start, press Esc for quit ..." << "\n";

	exec_game(&game_s);

	destroy_field(&game_s.field_s);

	std::cout << "Game over!" << "\n";

	return 0;

}


	
