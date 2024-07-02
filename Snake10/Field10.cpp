#include <iostream>

#include "const10.h"
#include "field10.h"
#include "winconsole10.h"


void clear_field(fieldStruct* field_s)
{
	for (int i = 1; i <= (field_s->FieldRows - 2); ++i)
	{
		for (int j = 1; j <= (field_s->FieldColumns - 2); ++j)
		{
			field_s->field[i][j] = field_symbol;
		}
	}
}

void create_field(fieldStruct* field_s)
{
	field_s->field = new char* [field_s->FieldRows];
	for (int i = 0; i < field_s->FieldRows; i++)
	{
		field_s->field[i] = new char[field_s->FieldColumns];
	}
}

void init_field(fieldStruct* field_s)
{
	create_field(field_s);

	for (int i = 0; i <= (field_s->FieldColumns - 1); ++i)
	{
		field_s->field[0][i] = border_symbol;
	}

	for (int i = 1; i <= (field_s->FieldRows - 2); ++i)
	{
		field_s->field[i][0] = border_symbol;
		field_s->field[i][field_s->FieldColumns - 1] = border_symbol;
	}

	for (int i = 0; i <= (field_s->FieldColumns - 1); ++i)
	{
		field_s->field[field_s->FieldRows-1][i] = border_symbol;
	}

	clear_field(field_s);
}

void print_field(fieldStruct* field_s)
{
	int	x = 0, y = 0;
	setCursorPosition(x,y);

	std::cout << "\n";

	for (int i = 0; i <= (field_s->FieldRows - 1); ++i)
	{
		for (int j = 0; j <= (field_s->FieldColumns - 1); ++j)
		{
			std::cout << field_s->field[i][j];
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

void destroy_field(fieldStruct* field_s)
{
	for (int i = 0; i < field_s->FieldRows; i++)
	{
		delete[] field_s->field[i];
	}
	delete[] field_s->field;
}



