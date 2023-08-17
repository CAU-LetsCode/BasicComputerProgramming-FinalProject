#include "game2.h"

int g2_point = 0;
int tempPoint = 0;
int g2_timetic = 1499;
int stage = 1;

void g2_delay(clock_t n)

{
	clock_t start = clock();
	while (clock() - start < n);

}

void StageUp()
{
	if (g2_point - tempPoint == 2000 && g2_timetic > 500)
	{
		stage += 1;
		printf("\n         스테이지가 하나 올라갑니다.");
		g2_delay(1000);
		tempPoint = g2_point;
		g2_timetic -= 300;
	}
}

void g2show_graphic(char*** p)
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
	printf("                  현재점수 : %d", g2_point);
	printf("\n                  현재 스테이지 :%d", stage);
	return;
}

void g2row_clear(char*** graphic)
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
			g2show_graphic(graphic);
			graphic[i][13] = "▣";
			graphic[i][14] = "▣";
			graphic[i][15] = "▣";
			system("cls");
			g2show_graphic(graphic);
			graphic[i][16] = "▣";
			graphic[i][17] = "▣";
			system("cls");
			g2show_graphic(graphic);
			graphic[i][18] = "▣";
			graphic[i][19] = "▣";
			system("cls");
			g2show_graphic(graphic);
			for (k = i; k > high; k--)//i행부터 위로 쭉
			{
				for (j = 10; j < 20; j++)//모든 열에
				{
					graphic[k][j] = graphic[k - 1][j];
				}
			}
			i++;
			high++;
			g2_point += 1000;

		}
	}
	StageUp();
}


//□■▩▣

