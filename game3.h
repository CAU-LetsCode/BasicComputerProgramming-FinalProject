#include "main.h"

int g3_point;

int istimeto_item(int a);
int item_decide();
int item_type(int a, char*** graphic, int** q, int b, int c);
void g3delay(clock_t n);
void item_one(char*** graphic, int a);
void item_two(char*** graphic, int a);
void one_line_down(int a, char*** graphic, int** q, int b, int c);
void item_exit(int a);

void g3show_graphic(char*** p, int a);
void g3row_clear(char*** graphic, int t);