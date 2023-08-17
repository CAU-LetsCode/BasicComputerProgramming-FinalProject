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
	printf("> �� �� �� ��");
	gotoxy(x, y + 1);
	printf("�� �� �� ��");
	gotoxy(x, y + 2);
	printf("  ����  ");
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
	printf("\t\t       [ �� �� �� �� ]");

	gotoxy(x - 2, y);
	printf("> No 1. �������� �ܿ���! \n");
	gotoxy(x, y + 1);
	printf("No 2. Ÿ�Ӿ��� ��� \n");
	gotoxy(x, y + 2);
	printf("No 3. ���� �����۸�� \n");
	gotoxy(x, y + 3);
	printf("�ڷ�");

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
	printf("\t\t       [ �� �� ��]\n\n");
	printf("\t\t     ��   : Hard Drop\n");
	printf("\t\t   ��  �� : Left / Right\n");
	printf("\t\t     ��   : Soft Drop\n");
	printf("\t     ȭ��ǥŰ�� ������ ��� Ű: Shift\n\n");
	printf("          ============ �� 3���� ��� ============\n");
	printf("                   No 1. �������� �ܿ���! \n");
	printf("                   No 2. Ÿ�Ӿ��� ��� \n");
	printf("                   No 3. ���� �����۸�� \n");
	printf("          =======================================\n\n");
	printf("\t������: 8�� ������ ����ȣ �̽��� ������\n\n");
	printf("\t�����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.\n");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}