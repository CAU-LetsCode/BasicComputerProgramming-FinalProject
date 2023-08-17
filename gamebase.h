#include "main.h"

int point;

void nums_to_arr(int** p, int a, int b, int c, int d, int e, int f, int g, int h);
int spin(int n);
int anti_spin(int n);
void show_graphic(char*** p);
int arrow(char key);
int anti_arrow(char key);
void show_coords(int** block_coors, int* location);
void coor_to_coor(int** p, int** q);

void block_type_to_coors(int** p, int blocktype, int spinvalue);
void put_block(char*** p, int** q, int a, int b);
void del_block(char*** p, int** q, int a, int b);
void move_coors(int* location, int key);
int can_put(char*** graphic, int** block_coors, int* location);

int is_row_full(char*** graphic, int r);
void row_clear(char*** graphic);
#pragma once
