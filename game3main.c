#include "main.h"

int g3_point = 0;
int g3_timetic;

int game3main()
{
	int i = 0, j = 0, key, a, b;
	int blocktype, spinvalue, next_blocktype, next_spinvalue;
	char*** graphic;//문자열을 원소로 갖는 2차원 배열
	int** block_coors;//블럭의 상대좌표들
	int** next_block_coors;
	int* location;//블럭중심의 위치
	int* tl;
	clock_t starttime = clock();
	clock_t start;

	//graphic 동적할당
	graphic = (char***)malloc(sizeof(char**) * 30);
	for (i = 0; i < 30; i++)
	{
		graphic[i] = (char**)malloc(sizeof(char*) * 30);//30개의 열 확보
	}

	//block_coors 동적할당
	block_coors = (int**)malloc(sizeof(int*) * 4);
	for (i = 0; i < 4; i++)	block_coors[i] = (int*)malloc(sizeof(int) * 2);
	next_block_coors = (int**)malloc(sizeof(int*) * 4);
	for (i = 0; i < 4; i++)	next_block_coors[i] = (int*)malloc(sizeof(int) * 2);

	//location 동적할당
	location = (int*)malloc(sizeof(int) * 2);
	tl = (int*)malloc(sizeof(int) * 2);
	tl[0] = 7;
	tl[1] = 24;

	//기본세팅
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (i == 25 && j > 8 && j < 21) graphic[i][j] = "▩";
			else if (j == 9 && i > 4 && i < 26) graphic[i][j] = "▩";
			else if (j == 20 && i > 4 && i < 26) graphic[i][j] = "▩";
			else graphic[i][j] = "  ";
		}
	}

	location[0] = 4;
	location[1] = 14;//기준점이 생성되는 점
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

		//시간 도달시 아이템 타입 결정
		int a = istimeto_item(starttime);
		//타입에 따라 아이템 함수 실행
		if (a != -1)
		{
			item_type(a, graphic, block_coors, location[0], location[1]);
		}
		int game_time = (clock() - starttime);
		//아이템 사용후 10초 지나면 내려오는 속도 원상 복귀
		if (game_time % 20000 == 10000 && game_time > 20000)
		{
			item_exit(a);
		}

		//키가 눌린 경우
		if (kbhit())
		{
			key = getch();

			//방향키가 눌린경우
			if (key == 224)
			{
				key = getch();

				//상 키가 눌린경우
				if (arrow(key) == 0)
				{
					del_block(graphic, block_coors, location[0], location[1]);//블럭을 지우고
					while (1)
					{
						move_coors(location, 2);//기준점을 한칸 내림
						if (can_put(graphic, block_coors, location))//변경된 기준점에 놓을 수 있다면
						{
							continue;
						}
						else//변경된 기준점에 놓을 수 없다면
						{
							move_coors(location, 0); //기준점 원상복귀
							put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
							g3row_clear(graphic, a);
							location[0] = 4;
							location[1] = 14;//기준점이 생성되는 점
							del_block(graphic, next_block_coors, 7, 24);
							coor_to_coor(block_coors, next_block_coors);
							blocktype = next_blocktype;
							spinvalue = next_spinvalue;
							next_blocktype = rand() % 6;
							next_spinvalue = rand() % 4;//랜덤블럭정보입력
							block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);//블럭좌표 파악
							if (can_put(graphic, block_coors, location))//새 블럭을 놓을 수 있다면
							{
								put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g3show_graphic(graphic, a);//보여줌
							}
							else//새 블럭 생성할 자리가 없음
							{
								put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g3show_graphic(graphic, a);//보여줌
								printf("\nG A M E  O V E R");
								return 0;
							}
							break;
						}
					}
				}
				//좌,하,우
				else
				{
					del_block(graphic, block_coors, location[0], location[1]);//블럭을 지우고
					move_coors(location, arrow(key));//기준점을 움직임
					if (can_put(graphic, block_coors, location))//변경된 기준점에 놓을 수 있다면
					{

						put_block(graphic, block_coors, location[0], location[1]);
						system("cls");
						g3show_graphic(graphic, a);

					}
					else//변경된 기준점에 놓을 수 없다면
					{
						if (arrow(key) == 2)//아래로가 막힌 경우
						{
							move_coors(location, 0); //기준점 원상복귀
							put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
							g3row_clear(graphic, a);

							location[0] = 4;
							location[1] = 14;//기준점이 생성되는 점
							del_block(graphic, next_block_coors, 7, 24);
							coor_to_coor(block_coors, next_block_coors);
							blocktype = next_blocktype;
							spinvalue = next_spinvalue;
							next_blocktype = rand() % 6;
							next_spinvalue = rand() % 4;//랜덤블럭정보입력
							block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);//블럭좌표 파악

							if (can_put(graphic, block_coors, location))//새 블럭을 놓을 수 있다면
							{
								put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g3show_graphic(graphic, a);//보여줌
							}
							else//새 블럭 생성할 자리가 없음
							{
								put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
								put_block(graphic, next_block_coors, 7, 24);
								system("cls");
								g3show_graphic(graphic, a);//보여줌
								printf("\n\t\tG A M E  O V E R");
								return 0;
							}
						}
						else//좌우가 막힌 경우
						{
							move_coors(location, anti_arrow(key)); //기준점 원상복귀
							put_block(graphic, block_coors, location[0], location[1]);
							system("cls");
							g3show_graphic(graphic, a);//다시 찍고 보여줌
						}
					}
				}

			}

			//회전키가 입력된 경우
			else
			{
				del_block(graphic, block_coors, location[0], location[1]);//블럭을 지우고
				spinvalue = spin(spinvalue);//블럭회전상수를 키우고
				block_type_to_coors(block_coors, blocktype, spinvalue);//그에맞춰 블럭좌표들을 변환한 뒤
				if (can_put(graphic, block_coors, location))//놓을 수 있다면
				{
					put_block(graphic, block_coors, location[0], location[1]);//블럭찍고
					system("cls");
					g3show_graphic(graphic, a);//보여주기
				}
				else //놓을 수 없다면
				{
					spinvalue = anti_spin(spinvalue);//블럭회전상수를 1 줄이고(원상복귀)
					block_type_to_coors(block_coors, blocktype, spinvalue);
					put_block(graphic, block_coors, location[0], location[1]);//블럭찍고
					system("cls");
					g3show_graphic(graphic, a);//보여주기
				}

			}
		}

		//단위시간마다 블럭을 떨어뜨림
		if ((clock() - start) > g3_timetic)
		{
			start = clock();
			del_block(graphic, block_coors, location[0], location[1]);//블럭을 지우고
			move_coors(location, 2);//기준점을 움직임
			if (can_put(graphic, block_coors, location))//변경된 기준점에 놓을 수 있다면
			{
				put_block(graphic, block_coors, location[0], location[1]);
				system("cls");
				g3show_graphic(graphic, a);
			}
			else//변경된 기준점에 놓을 수 없다면
			{
				move_coors(location, 0); //기준점 원상복귀
				put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
				g3row_clear(graphic, a);

				location[0] = 4;
				location[1] = 14;//기준점이 생성되는 점
				del_block(graphic, next_block_coors, 7, 24);
				coor_to_coor(block_coors, next_block_coors);
				blocktype = next_blocktype;
				spinvalue = next_spinvalue;
				next_blocktype = rand() % 6;
				next_spinvalue = rand() % 4;//랜덤블럭정보입력
				block_type_to_coors(next_block_coors, next_blocktype, next_spinvalue);//블럭좌표 파악
				if (can_put(graphic, block_coors, location))//새 블럭을 놓을 수 있다면
				{
					put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
					put_block(graphic, next_block_coors, 7, 24);
					system("cls");
					g3show_graphic(graphic, a);//보여줌
				}
				else//새 블럭 생성할 자리가 없음
				{
					put_block(graphic, block_coors, location[0], location[1]);//블럭놓음
					put_block(graphic, next_block_coors, 7, 24);
					system("cls");
					g3show_graphic(graphic, a);//보여줌
					printf("\nG A M E  O V E R");
					return 0;
				}
			}
		}
	}

	//g3show_graphic(graphic);
	return 0;
}