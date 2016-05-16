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

	SetConsoleTitle(L"테스트");		// 창 타이틀 설정
	system("mode con:cols=50 lines=10");	// 화면 크기 지정

											//system("color 6B");		// 앞 : 배경색, 뒤 : 글자색		(cmd에서  color /?를 입력하면 정보가 나옴)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6B); // 앞 : 배경색, 뒤 : 글자색		(cmd에서  color /?를 입력하면 정보가 나옴)

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
			if (chr == 72) { //상
				y -= 1;
				if (y<1) y = 1;
			}
			else if (chr == 80) { //하
				y += 1;
			}
			else if (chr == 75) { //좌
				x -= 2;
				if (x<1)x = 1;
			}
			else if (chr == 77) { //우
				x += 2;
			}
			system("cls");
			gotoxy(x - 1, y - 1);
			printf("■");
		}

	}


	return 0;
}