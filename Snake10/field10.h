#pragma once

struct fieldStruct
{
	int FieldRows;
	int FieldColumns;
	char** field;
};

void clear_field(fieldStruct* field_s);
void init_field(fieldStruct* field_s);
void print_field(fieldStruct* field_s);
void create_field(fieldStruct* field_s);
void destroy_field(fieldStruct* field_s);
