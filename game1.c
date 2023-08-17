#include "game1.h"

typedef long clock_t;

int g1_point = 0;
void g1_delay(clock_t n)

{
	clock_t start = clock();
	while (clock() - start < n);

}
void g1_show_graphic(char*** p)
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
	clock_t t_ime = clock();
	int t = t_ime / 1000;
	printf("		현재점수 : %d", g1_point);

}
void Multiplication_table(char*** p)
{
	int dan, num;
	int user;

	srand(time(NULL));
	printf("\n구구단을 외자.");
	dan = rand() % 18 + 2;
	num = rand() % 18 + 2;
	printf("%d * %d = \a\n ", dan, num);
	scanf("%d", &user);
	if (user == dan * num) {
		printf(" 정답입니다.");
		g1_point += 500;
	}
	else {
		printf("틀렸습니다. 정답은 %d입니다.\n", dan * num);
		g1_point -= 1000;
	}
	return;
}