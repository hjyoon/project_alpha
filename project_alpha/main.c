#include "custom.h"

#define START_X 3
#define START_Y 3
#define WIDTH 4
#define HEIGHT 4

int main(void)
{
	int i, j;
	int cnt = 1;
	int timer = 0;
	int x = 1;
	int y = 1;

	/*for (i = 0; i <= 255; i++)
	{*/
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6B);
	//printf("COLOR TESTING~\a\n");
	//}

	SetConsoleTitle(L"�׽�Ʈ");		// â Ÿ��Ʋ ����
	system("mode con:cols=50 lines=10");	// ȭ�� ũ�� ����

											//system("color 6B");		// �� : ����, �� : ���ڻ�		(cmd����  color /?�� �Է��ϸ� ������ ����)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6B); // �� : ����, �� : ���ڻ�		(cmd����  color /?�� �Է��ϸ� ������ ����)

	setcursortype(NOCURSOR);

	/*for (i = START_X; i < START_X + WIDTH; i++) {
	for (j = START_Y; j < START_Y + HEIGHT; j++) {
	gotoxy(3, 3);
	printf("%d", cnt);
	cnt++;
	delay(200);
	}
	}*/

	while (1) {
		int chr;

		chr = _getch();

		if (chr == 0 || chr == 0xe0) {
			chr = _getch();
			if (chr == 72) { //��
				y -= 1;
				if (y<1) y = 1;
			}
			else if (chr == 80) { //��
				y += 1;
			}
			else if (chr == 75) { //��
				x -= 2;
				if (x<1)x = 1;
			}
			else if (chr == 77) { //��
				x += 2;
			}
			system("cls");
			gotoxy(x - 1, y - 1);
			printf("��");
		}

	}


	return 0;
}