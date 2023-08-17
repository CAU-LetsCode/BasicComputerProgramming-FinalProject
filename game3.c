#include "game3.h"


int g3_timetic = 1499;

//일정시간마다 아이템 사용하게 하는 함수
int istimeto_item(int a)
{
	if ((clock() - a) % 20000 == 0)
	{
		int type = item_decide();
		return type;
	}
	else
		return -1;
}

//아이템 타입 확률 정하는 함수
int item_decide()
{
	int num = rand() % 100;
	if (num < 40)
	{
		return 1;
	}
	else if (num >= 40 && num < 80)
	{
		return 2;
	}
	else if (num >= 80 && num < 100)
	{
		return 3;
	}
}
//아이템 타입 함수
int item_type(int a, char*** graphic, int** q, int b, int c)
{
	switch (a)
	{
	case 1:
		item_one(graphic, a);
		break;
	case 2:
		item_two(graphic, a);
		break;
	case 3:
		one_line_down(a, graphic, q, b, c);
		break;
	}
}
//딜레이 함수
void g3delay(clock_t n)

{
	clock_t begin = clock();
	while (clock() - begin < n);

}
//내려오는데 걸리는 시간 감소 함수
void item_one(char*** graphic, int a)
{
	g3_timetic = 999;
	system("cls");
	g3show_graphic(graphic, a);
	g3delay(500);
}
//내려오는 데 걸리는 시간 증가 함수
void item_two(char*** graphic, int a)
{
	g3_timetic = 1999;
	system("cls");
	g3show_graphic(graphic, a);
	g3delay(500);
}
//한줄 내리는 함수
void one_line_down(int a, char*** graphic, int** q, int b, int c)
{
	del_block(graphic, q, b, c);
	for (int i = 24; i < 25; i++)
	{
		graphic[i][10] = "▣";
		graphic[i][11] = "▣";
		graphic[i][12] = "▣";
		system("cls");
		g3show_graphic(graphic, a);
		graphic[i][13] = "▣";
		graphic[i][14] = "▣";
		graphic[i][15] = "▣";
		system("cls");
		g3show_graphic(graphic, a);
		graphic[i][16] = "▣";
		graphic[i][17] = "▣";
		system("cls");
		g3show_graphic(graphic, a);
		graphic[i][18] = "▣";
		graphic[i][19] = "▣";
		system("cls");
		g3show_graphic(graphic, a);
		g3delay(500);
	}
	for (int i = 24; i > 4; i--)
	{
		for (int j = 10; j < 20; j++)
		{
			graphic[i][j] = graphic[i - 1][j];
		}
	}
	put_block(graphic, q, b, c);
}
//일정 시간후 내려가는 시간 원상복귀 함수
void item_exit(int a)
{
	g3_timetic = 1499;
}


void g3show_graphic(char*** p, int a)
{
	int i, j = 0;
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			printf("%s", p[i][j]);
		}
		printf("\n");
	}
	printf("                  현재점수 : %d\n", g3_point);
	//아이템 설명 출력
	if (a == 1)
	{
		printf("10초 동안 블럭이 빠르게 내려옵니다.\n");
	}
	else if (a == 2)
	{
		printf("10초 동안 블럭이 느리게 내려옵니다.\n");
	}
	else if (a == 3)
	{
		printf("블럭이 한줄 지워집니다.\n");
	}
	return;
}

void g3row_clear(char*** graphic, int t)
{
	int i, j, k, high = 4;
	for (i = 24; i > high; i--)
	{
		if (is_row_full(graphic, i))//i열이 꽉찼으면
		{
			graphic[i][10] = "▣";
			graphic[i][11] = "▣";
			graphic[i][12] = "▣";
			system("cls");
			g3show_graphic(graphic, t);
			graphic[i][13] = "▣";
			graphic[i][14] = "▣";
			graphic[i][15] = "▣";
			system("cls");
			g3show_graphic(graphic, t);
			graphic[i][16] = "▣";
			graphic[i][17] = "▣";
			system("cls");
			g3show_graphic(graphic, t);
			graphic[i][18] = "▣";
			graphic[i][19] = "▣";
			system("cls");
			g3show_graphic(graphic, t);
			for (k = i; k > high; k--)//i행부터 위로 쭉
			{
				for (j = 10; j < 20; j++)//모든 열에
				{
					graphic[k][j] = graphic[k - 1][j];
				}
			}
			i++;
			high++;
			g3_point += 1000;

		}
	}
}


//□■▩▣

