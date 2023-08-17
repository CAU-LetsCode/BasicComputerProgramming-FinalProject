#include "main.h"

int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			int n = maplistDraw();

			if (n == 0) {
				gLoop(0);

			}
			else if (n == 1) {
				gLoop(1);
			}
			else if (n == 2) {
				gLoop(2);
			}
		}
		else if (menuCode == 1) {
			infoDraw();
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

