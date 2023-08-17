#include "main.h"
#include "game2.h"

int g2_point;
int tempPoint;
int g2_timetic;
int stage;

int game2main()
{
	int i = 0, j = 0, key, a, b;
	int blocktype, spinvalue, next_blocktype, next_spinvalue;
	char*** graphic;//���ڿ��� ���ҷ� ���� 2���� �迭
	int** block_coors;//���� �����ǥ��
	int** next_block_coors;
	int* location;//���߽��� ��ġ
	int* tl;
	clock_t starttime = clock();
	clock_t start;

	//graphic �����Ҵ�
	graphic = (char***)malloc(sizeof(char**) * 30);
	for (i = 0; i < 30; i++)
	{
		graphic[i] = (char**)malloc(sizeof(char*) * 30);//30���� �� Ȯ��
	}

	//block_coors �����Ҵ�
	block_coors = (int**)malloc(sizeof(int*) * 4);
	for (i = 0; i < 4; i++)	block_coors[i] = (int*)malloc(sizeof(int) * 2);
	next_block_coors = (int**)malloc(sizeof(int*) * 4);
	for (i = 0; i < 4; i++)	next_block_coors[i] = (int*)malloc(sizeof(int) * 2);

	//location �����Ҵ�
	location = (int*)malloc(sizeof(int) * 2);
	tl = (int*)malloc(sizeof(int) * 2);
	tl[0] = 7;
	tl[1] = 24;

	//�⺻����
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (i == 25 && j > 8 && j < 21) graphic[i][j] = "��";
			else if (j == 9 && i > 4 && i < 26) graphic[i][j] = "��";
			else if (j == 20 && i > 4 && i < 26) graphic[i][j] = "��";
			else graphic[i][j] = "  ";
		}
	}

	location[0] = 4;
	location[1] = 14;//�������� �����Ǵ� ��
	srand(time(NULL));
	blocktype = rand() % 6;
	spinvalue = rand() % 4;
	next_blocktype = rand() % 6;
	next_spinvalue = rand() % 4;
	block_type_to_coors(block_coors, blocktype, spinvalue);
	block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);
	put_block(graphic, block_coors, location[0], location[1]);
	put_block(graphic, next_block_coors, 7, 24);
	system("cls");
	g2show_graphic(graphic);
	start = clock();
	while (1)
	{
		//Ű�� ���� ���
		if (kbhit())
		{
			key = getch();

			//����Ű�� �������
			if (key == 224)
			{
				key = getch();

				//�� Ű�� �������
				if (arrow(key) == 0)
				{
					del_block(graphic, block_coors, location[0], location[1]);//���� �����
					while (1)
					{
						move_coors(location, 2);//�������� ��ĭ ����
						if (can_put(graphic, block_coors, location))//����� �������� ���� �� �ִٸ�
						{
							continue;
						}
						else//����� �������� ���� �� ���ٸ�
						{
							move_coors(location, 0); //������ ���󺹱�
							put_block(graphic, block_coors, location[0], location[1]);//������
							g2row_clear(graphic);
							location[0] = 4;
							location[1] = 14;//�������� �����Ǵ� ��
							del_block(graphic, next_block_coors, 7, 24);
							coor_to_coor(block_coors, next_block_coors);
							blocktype = next_blocktype;
							spinvalue = next_spinvalue;
							next_blocktype = rand() % 6;
							next_spinvalue = rand() % 4;//�����������Է�
							block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);//����ǥ �ľ�
							if (can_put(graphic, block_coors, location))//�� ���� ���� �� �ִٸ�
							{
								put_block(graphic, block_coors, location[0], location[1]);//������
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g2show_graphic(graphic);//������
							}
							else//�� �� ������ �ڸ��� ����
							{
								put_block(graphic, block_coors, location[0], location[1]);//������
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g2show_graphic(graphic);//������
								printf("\n                  G A M E  O V E R");
								printf("\n                  �� ���ӽð� : %ld��", (clock() - starttime) / 1000);
								printf("\n                  �ִ� �������� : %d", stage);
								return 0;
							}
							break;
						}
					}
				}
				//��,��,��
				else
				{
					del_block(graphic, block_coors, location[0], location[1]);//���� �����
					move_coors(location, arrow(key));//�������� ������
					if (can_put(graphic, block_coors, location))//����� �������� ���� �� �ִٸ�
					{
						put_block(graphic, block_coors, location[0], location[1]);
						system("cls");
						g2show_graphic(graphic);

					}
					else//����� �������� ���� �� ���ٸ�
					{
						if (arrow(key) == 2)//�Ʒ��ΰ� ���� ���
						{
							move_coors(location, 0); //������ ���󺹱�
							put_block(graphic, block_coors, location[0], location[1]);//������
							g2row_clear(graphic);
							location[0] = 4;
							location[1] = 14;//�������� �����Ǵ� ��
							del_block(graphic, next_block_coors, 7, 24);
							coor_to_coor(block_coors, next_block_coors);
							blocktype = next_blocktype;
							spinvalue = next_spinvalue;
							next_blocktype = rand() % 6;
							next_spinvalue = rand() % 4;//�����������Է�
							block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);//����ǥ �ľ�

							if (can_put(graphic, block_coors, location))//�� ���� ���� �� �ִٸ�
							{
								put_block(graphic, block_coors, location[0], location[1]);//������
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g2show_graphic(graphic);//������
							}
							else//�� �� ������ �ڸ��� ����
							{
								put_block(graphic, block_coors, location[0], location[1]);//������
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g2show_graphic(graphic);//������
								printf("\n                  ���ӿ���.");
								printf("\n                  �� ���ӽð� : %ld��", (clock() - starttime) / 1000);
								printf("\n                  �ִ� �������� : %d", stage);
								return 0;
							}
						}
						else//�¿찡 ���� ���
						{
							move_coors(location, anti_arrow(key)); //������ ���󺹱�
							put_block(graphic, block_coors, location[0], location[1]);
							system("cls");
							g2show_graphic(graphic);//�ٽ� ��� ������
						}
					}
				}

			}

			//ȸ��Ű�� �Էµ� ���
			else
			{
				del_block(graphic, block_coors, location[0], location[1]);//���� �����
				spinvalue = spin(spinvalue);//��ȸ������� Ű���
				block_type_to_coors(block_coors, blocktype, spinvalue);//�׿����� ����ǥ���� ��ȯ�� ��
				if (can_put(graphic, block_coors, location))//���� �� �ִٸ�
				{
					put_block(graphic, block_coors, location[0], location[1]);//�����
					system("cls");
					g2show_graphic(graphic);//�����ֱ�
				}
				else //���� �� ���ٸ�
				{
					spinvalue = anti_spin(spinvalue);//��ȸ������� 1 ���̰�(���󺹱�)
					block_type_to_coors(block_coors, blocktype, spinvalue);
					put_block(graphic, block_coors, location[0], location[1]);//�����
					system("cls");
					g2show_graphic(graphic);//�����ֱ�
				}

			}
		}

		//�����ð����� ���� ����߸�
		if ((clock() - start) > g2_timetic)
		{
			start = clock();
			del_block(graphic, block_coors, location[0], location[1]);//���� �����
			move_coors(location, 2);//�������� ������
			if (can_put(graphic, block_coors, location))//����� �������� ���� �� �ִٸ�
			{
				put_block(graphic, block_coors, location[0], location[1]);
				system("cls");
				g2show_graphic(graphic);
			}
			else//����� �������� ���� �� ���ٸ�
			{
				move_coors(location, 0); //������ ���󺹱�
				put_block(graphic, block_coors, location[0], location[1]);//������
				g2row_clear(graphic);
				location[0] = 4;
				location[1] = 14;//�������� �����Ǵ� ��
				del_block(graphic, next_block_coors, 7, 24);
				coor_to_coor(block_coors, next_block_coors);
				blocktype = next_blocktype;
				spinvalue = next_spinvalue;
				next_blocktype = rand() % 6;
				next_spinvalue = rand() % 4;//�����������Է�
				block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);//����ǥ �ľ�
				if (can_put(graphic, block_coors, location))//�� ���� ���� �� �ִٸ�
				{
					put_block(graphic, block_coors, location[0], location[1]);//������
					put_block(graphic, next_block_coors, 7, 24);
					system("cls");
					g2show_graphic(graphic);//������
				}
				else//�� �� ������ �ڸ��� ����
				{
					put_block(graphic, block_coors, location[0], location[1]);//������
					put_block(graphic, next_block_coors, 7, 24);
					system("cls");
					g2show_graphic(graphic);//������
					printf("\n                  G A M E  O V E R");
					printf("\n                  �� ���ӽð� : %ld��", (clock() - starttime) / 1000);
					printf("\n                  �ִ� �������� %d", stage);
					return 0;
				}
			}
		}
	}

	//g2show_graphic(graphic);
	return 0;
}