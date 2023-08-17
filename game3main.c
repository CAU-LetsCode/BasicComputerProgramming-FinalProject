#include "main.h"

int g3_point = 0;
int g3_timetic;

int game3main()
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
	g3show_graphic(graphic, -1);
	start = clock();
	while (1)
	{

		//�ð� ���޽� ������ Ÿ�� ����
		int a = istimeto_item(starttime);
		//Ÿ�Կ� ���� ������ �Լ� ����
		if (a != -1)
		{
			item_type(a, graphic, block_coors, location[0], location[1]);
		}
		int game_time = (clock() - starttime);
		//������ ����� 10�� ������ �������� �ӵ� ���� ����
		if (game_time % 20000 == 10000 && game_time > 20000)
		{
			item_exit(a);
		}

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
							g3row_clear(graphic, a);
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
								g3show_graphic(graphic, a);//������
							}
							else//�� �� ������ �ڸ��� ����
							{
								put_block(graphic, block_coors, location[0], location[1]);//������
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g3show_graphic(graphic, a);//������
								printf("\nG A M E  O V E R");
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
						g3show_graphic(graphic, a);

					}
					else//����� �������� ���� �� ���ٸ�
					{
						if (arrow(key) == 2)//�Ʒ��ΰ� ���� ���
						{
							move_coors(location, 0); //������ ���󺹱�
							put_block(graphic, block_coors, location[0], location[1]);//������
							g3row_clear(graphic, a);

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
								g3show_graphic(graphic, a);//������
							}
							else//�� �� ������ �ڸ��� ����
							{
								put_block(graphic, block_coors, location[0], location[1]);//������
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g3show_graphic(graphic, a);//������
								printf("\n\t\tG A M E  O V E R");
								return 0;
							}
						}
						else//�¿찡 ���� ���
						{
							move_coors(location, anti_arrow(key)); //������ ���󺹱�
							put_block(graphic, block_coors, location[0], location[1]);
							system("cls");
							g3show_graphic(graphic, a);//�ٽ� ��� ������
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
					g3show_graphic(graphic, a);//�����ֱ�
				}
				else //���� �� ���ٸ�
				{
					spinvalue = anti_spin(spinvalue);//��ȸ������� 1 ���̰�(���󺹱�)
					block_type_to_coors(block_coors, blocktype, spinvalue);
					put_block(graphic, block_coors, location[0], location[1]);//�����
					system("cls");
					g3show_graphic(graphic, a);//�����ֱ�
				}

			}
		}

		//�����ð����� ���� ����߸�
		if ((clock() - start) > g3_timetic)
		{
			start = clock();
			del_block(graphic, block_coors, location[0], location[1]);//���� �����
			move_coors(location, 2);//�������� ������
			if (can_put(graphic, block_coors, location))//����� �������� ���� �� �ִٸ�
			{
				put_block(graphic, block_coors, location[0], location[1]);
				system("cls");
				g3show_graphic(graphic, a);
			}
			else//����� �������� ���� �� ���ٸ�
			{
				move_coors(location, 0); //������ ���󺹱�
				put_block(graphic, block_coors, location[0], location[1]);//������
				g3row_clear(graphic, a);

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
					g3show_graphic(graphic, a);//������
				}
				else//�� �� ������ �ڸ��� ����
				{
					put_block(graphic, block_coors, location[0], location[1]);//������
					put_block(graphic, next_block_coors, 7, 24);
					system("cls");
					g3show_graphic(graphic, a);//������
					printf("\nG A M E  O V E R");
					return 0;
				}
			}
		}
	}

	//g3show_graphic(graphic);
	return 0;
}