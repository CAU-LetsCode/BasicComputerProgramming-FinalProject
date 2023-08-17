#include "game3.h"


int g3_timetic = 1499;

//�����ð����� ������ ����ϰ� �ϴ� �Լ�
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

//������ Ÿ�� Ȯ�� ���ϴ� �Լ�
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
//������ Ÿ�� �Լ�
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
//������ �Լ�
void g3delay(clock_t n)

{
	clock_t begin = clock();
	while (clock() - begin < n);

}
//�������µ� �ɸ��� �ð� ���� �Լ�
void item_one(char*** graphic, int a)
{
	g3_timetic = 999;
	system("cls");
	g3show_graphic(graphic, a);
	g3delay(500);
}
//�������� �� �ɸ��� �ð� ���� �Լ�
void item_two(char*** graphic, int a)
{
	g3_timetic = 1999;
	system("cls");
	g3show_graphic(graphic, a);
	g3delay(500);
}
//���� ������ �Լ�
void one_line_down(int a, char*** graphic, int** q, int b, int c)
{
	del_block(graphic, q, b, c);
	for (int i = 24; i < 25; i++)
	{
		graphic[i][10] = "��";
		graphic[i][11] = "��";
		graphic[i][12] = "��";
		system("cls");
		g3show_graphic(graphic, a);
		graphic[i][13] = "��";
		graphic[i][14] = "��";
		graphic[i][15] = "��";
		system("cls");
		g3show_graphic(graphic, a);
		graphic[i][16] = "��";
		graphic[i][17] = "��";
		system("cls");
		g3show_graphic(graphic, a);
		graphic[i][18] = "��";
		graphic[i][19] = "��";
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
//���� �ð��� �������� �ð� ���󺹱� �Լ�
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
	printf("                  �������� : %d\n", g3_point);
	//������ ���� ���
	if (a == 1)
	{
		printf("10�� ���� ���� ������ �����ɴϴ�.\n");
	}
	else if (a == 2)
	{
		printf("10�� ���� ���� ������ �����ɴϴ�.\n");
	}
	else if (a == 3)
	{
		printf("���� ���� �������ϴ�.\n");
	}
	return;
}

void g3row_clear(char*** graphic, int t)
{
	int i, j, k, high = 4;
	for (i = 24; i > high; i--)
	{
		if (is_row_full(graphic, i))//i���� ��á����
		{
			graphic[i][10] = "��";
			graphic[i][11] = "��";
			graphic[i][12] = "��";
			system("cls");
			g3show_graphic(graphic, t);
			graphic[i][13] = "��";
			graphic[i][14] = "��";
			graphic[i][15] = "��";
			system("cls");
			g3show_graphic(graphic, t);
			graphic[i][16] = "��";
			graphic[i][17] = "��";
			system("cls");
			g3show_graphic(graphic, t);
			graphic[i][18] = "��";
			graphic[i][19] = "��";
			system("cls");
			g3show_graphic(graphic, t);
			for (k = i; k > high; k--)//i����� ���� ��
			{
				for (j = 10; j < 20; j++)//��� ����
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


//���̢�

