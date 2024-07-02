#pragma once

struct foodStruct
{
	int food_x = 0;
	int food_y = 0;
	bool food_flag = false;
};

void init_food(foodStruct* food_s);