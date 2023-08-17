#include "game.h"
#include "util.h"

void gLoop(int mapCode) {
	int playing = 1;

	if (mapCode == 0) {

		game1main();
	}
	else if (mapCode == 1) {

		game2main();
	}
	else if (mapCode == 2) {

		game3main();
	}

	while (playing) {
		switch (keyControl()) {
		case UP:
			break;

		case DOWN:
			break;

		case RIGHT:
			break;

		case LEFT:
			break;

		case QUIT:
			playing = 0;
		}
	}
}

int keyControl() {
	char temp = getch();

	if (temp == 72)
		return UP;
	else if (temp == 75)
		return LEFT;
	else if (temp == 77)
		return RIGHT;
	else if (temp == 80)
		return DOWN;
	else if (temp == ' ')
		return SUBMIT;
}
void titleDraw() {
	printf("\n\n\n\n");
	gotoxy(23, 5);
	printf("Tetris start.");
}

int menuDraw() {
	int x = 24;
	int y = 12;
	gotoxy(x - 2, y);
	printf("> 게 임 시 작");
	gotoxy(x, y + 1);
	printf("게 임 정 보");
	gotoxy(x, y + 2);
	printf("  종료  ");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 12;
		}
		}
	}
}

int maplistDraw() {
	int x = 20;
	int y = 11;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t       [ 모 드 선 택 ]");

	gotoxy(x - 2, y);
	printf("> No 1. 구구단을 외우자! \n");
	gotoxy(x, y + 1);
	printf("No 2. 타임어택 모드 \n");
	gotoxy(x, y + 2);
	printf("No 3. 랜덤 아이템모드 \n");
	gotoxy(x, y + 3);
	printf("뒤로");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 11) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 11;

		}
		}
	}
}
void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("\t\t       [ 조 작 법]\n\n");
	printf("\t\t     △   : Hard Drop\n");
	printf("\t\t   ◁  ▷ : Left / Right\n");
	printf("\t\t     ▽   : Soft Drop\n");
	printf("\t     화살표키를 제외한 모든 키: Shift\n\n");
	printf("          ============ 총 3가지 모드 ============\n");
	printf("                   No 1. 구구단을 외우자! \n");
	printf("                   No 2. 타임어택 모드 \n");
	printf("                   No 3. 랜덤 아이템모드 \n");
	printf("          =======================================\n\n");
	printf("\t개발자: 8조 임지민 이주호 이승준 최정우\n\n");
	printf("\t스페이스바를 누르면 메인화면으로 이동합니다.\n");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}