#include "gamebase.h"


int point;
int g1_point;
//편의함수
void nums_to_arr(int** p, int a, int  b, int  c, int  d, int  e, int  f, int  g, int  h)
{
	p[0][0] = a;
	p[0][1] = b;
	p[1][0] = c;
	p[1][1] = d;
	p[2][0] = e;
	p[2][1] = f;
	p[3][0] = g;
	p[3][1] = h;
	return;
}
int spin(int n)
{
	if (n == 3) return 0;
	else return n + 1;
}
int anti_spin(int n)
{
	if (n == 0) return 3;
	else return n - 1;
}
void show_graphic(char*** p)
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
	printf("                  현재점수 : %d", point);
	return;
}

int arrow(char key)
{
	switch (key)
	{
	case 72:
		return 0;
	case 75:
		return 1;
	case 77:
		return 3;
	case 80:
		return 2;
	default:
		return -1;
	}
}
int anti_arrow(char key)
{
	switch (key)
	{
	case 72:
		return 2;
	case 75:
		return 3;
	case 77:
		return 1;
	case 80:
		return 0;
	default:
		return -1;
	}
}
void show_coords(int** block_coors, int* location)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%3d%3d\n", location[0] + block_coors[i][0], location[1] + block_coors[i][1]);
	}
	return;
}
void coor_to_coor(int** p, int** q)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			p[i][j] = q[i][j];
		}
	}
	return;
}




/********블록관련**********/
//블럭정보를 받으면 중심기준 점들의 위치를 반환
void block_type_to_coors(int** p, int blocktype, int spinvalue)
{
	switch (blocktype)
	{
	case 0:
		switch (spinvalue)
		{
		case 0:
			nums_to_arr(p, -1, 0, 0, 0, 1, 0, 2, 0);
			return;
		case 1:
			nums_to_arr(p, 0, -1, 0, 0, 0, 1, 0, 2);
			return;
		case 2:
			nums_to_arr(p, -1, 0, 0, 0, 1, 0, 2, 0);
			return;
		case 3:
			nums_to_arr(p, 0, -1, 0, 0, 0, 1, 0, 2);
			return;
		}
	case 1:
		switch (spinvalue)
		{
		case 0:
			nums_to_arr(p, -1, -1, 0, -1, 0, 0, 0, 1);
			return;
		case 1:
			nums_to_arr(p, -1, 0, 0, 0, 1, 0, 1, -1);
			return;
		case 2:
			nums_to_arr(p, 0, -1, 0, 0, 0, 1, 1, 1);
			return;
		case 3:
			nums_to_arr(p, -1, 0, -1, 1, 0, 0, 1, 0);
			return;
		}
	case 2:
		switch (spinvalue)
		{
		case 0:
			nums_to_arr(p, 0, -1, 0, 0, 0, 1, -1, 1);
			return;
		case 1:
			nums_to_arr(p, -1, -1, -1, 0, 0, 0, 1, 0);
			return;
		case 2:
			nums_to_arr(p, 1, -1, 0, -1, 0, 0, 0, 1);
			return;
		case 3:
			nums_to_arr(p, -1, 0, 0, 0, 1, 0, 1, 1);
			return;
		}
	case 3:
		switch (spinvalue)
		{
		case 0:
			nums_to_arr(p, -1, 0, 0, 0, 0, 1, 1, 1);
			return;
		case 1:
			nums_to_arr(p, 0, -1, 0, 0, -1, 0, -1, 1);
			return;
		case 2:
			nums_to_arr(p, -1, 0, 0, 0, 0, 1, 1, 1);
			return;
		case 3:
			nums_to_arr(p, 0, -1, 0, 0, -1, 0, -1, 1);
			return;
		}
	case 4:
		switch (spinvalue)
		{
		case 0:
			nums_to_arr(p, 0, 0, 0, 1, -1, 1, 1, 0);
			return;
		case 1:
			nums_to_arr(p, -1, -1, -1, 0, 0, 0, 0, 1);
			return;
		case 2:
			nums_to_arr(p, 0, 0, 0, 1, -1, 1, 1, 0);
			return;
		case 3:
			nums_to_arr(p, -1, -1, -1, 0, 0, 0, 0, 1);
			return;
		}
	case 5:
		switch (spinvalue)
		{
		case 0:
			nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
			return;
		case 1:
			nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
			return;
		case 2:
			nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
			return;
		case 3:
			nums_to_arr(p, 0, 0, 0, 1, 1, 0, 1, 1);
			return;
		}
	}
}
//좌표, 블록점좌표배열, 기준점을 받으면 블럭을 그래픽에 찍음
void put_block(char*** p, int** q, int a, int b)
{
	int i, tempi, tempj;
	for (i = 0; i < 4; i++)
	{
		tempi = a + q[i][0];
		tempj = b + q[i][1];
		p[tempi][tempj] = "■";
	}
}
//좌표, 블록점좌표배열, 기준점을 받으면 블럭을 그래픽에서 지움
void del_block(char*** p, int** q, int a, int b)
{
	int i, tempi, tempj;
	for (i = 0; i < 4; i++)
	{
		tempi = a + q[i][0];
		tempj = b + q[i][1];
		p[tempi][tempj] = "  ";
	}
}
//기준점, 방향키를 입력받으면 기준점을 변환
void move_coors(int* location, int key)
{
	int i;
	switch (key)
	{
	case 0:
		location[0] -= 1;
		return;
	case 1:
		location[1] -= 1;
		return;
	case 2:
		location[0] += 1;
		return;
	case 3:
		location[1] += 1;
		return;
	}
}
//블럭상대좌표, 기준점을 입력받으면 그래픽에 찍을 수 있는지를 판단
int can_put(char*** graphic, int** block_coors, int* location)
{
	int a, b, i;
	for (i = 0; i < 4; i++)
	{
		a = location[0] + block_coors[i][0];
		b = location[1] + block_coors[i][1];//a,b가 각각의 사각형좌표에 대응
		if ((b < 10) || (b > 19)) return 0;
		if (graphic[a][b] != "  ") return 0;
	}
	return 1;
}


/*******게임진행******/
//그래픽, 행을 입력받으면 해당 행이 꽉찼는지를 판단
int is_row_full(char*** graphic, int r)
{
	int j;
	for (j = 10; j < 20; j++) if (graphic[r][j] == "  ") return 0;
	return 1;
}
//그래픽을 받으면 줄지워주며 그래픽도 보여줌
void row_clear(char*** graphic)
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
			show_graphic(graphic);
			graphic[i][13] = "▣";
			graphic[i][14] = "▣";
			graphic[i][15] = "▣";
			system("cls");
			show_graphic(graphic);
			graphic[i][16] = "▣";
			graphic[i][17] = "▣";
			system("cls");
			show_graphic(graphic);
			graphic[i][18] = "▣";
			graphic[i][19] = "▣";
			system("cls");
			show_graphic(graphic);
			for (k = i; k > high; k--)//i행부터 위로 쭉
			{
				for (j = 10; j < 20; j++)//모든 열에
				{
					graphic[k][j] = graphic[k - 1][j];
				}
			}
			i++;
			high++;
			point += 1000;
			g1_point += 1000;

		}
	}
}


//□■▩▣

