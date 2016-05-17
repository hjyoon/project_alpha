#include "custom.h"

#define CENTER 8
#define HIGH 30
#define WIDTH 20

void map();

int main(void)
{
	int i, j;
	int cnt = 1;
	int timer = 0;
	int x = CENTER;
	int y = 0;
	int chr;
	int oldX = x;
	int oldY = y;
	/*for (i = 0; i <= 255; i++)
	{*/
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6B);
	//printf("COLOR TESTING~\a\n");
	//}

	SetConsoleTitle(L"테스트");		// 창 타이틀 설정
	system("mode con:cols=80 lines=40");	// 화면 크기 지정

											//system("color 6B");		// 앞 : 배경색, 뒤 : 글자색		(cmd에서  color /?를 입력하면 정보가 나옴)
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x3A); // 앞 : 배경색, 뒤 : 글자색		(cmd에서  color /?를 입력하면 정보가 나옴)

	setcursortype(NOCURSOR);
	map();
	while (1) {
		
		chr = _getch();

		if (chr == 0 || chr == 0xe0) {
			chr = _getch();
			if (chr == 72) { //상
				y -= 1;
				if (y<1) y = 1;
			}
			else if (chr == 80) { //하
				y += 1;
				if (y > HIGH-1) {
					y = HIGH-1;
				}
			}
			else if (chr == 75) { //좌
				x -= 2;
				if (x<CENTER) x = CENTER;
			}
			else if (chr == 77) { //우
				x += 2;
				if (x > (WIDTH)+CENTER) {
					x = WIDTH+CENTER;
				}
			}
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
			gotoxy(oldX, oldY);
			printf("　");
			//system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
			gotoxy(x, y);
			printf("■");
			oldX = x;
			oldY = y;
		}
	}


	return 0;
}

void map() {
	int i, k;
	int map[HIGH][WIDTH] = { 0, };
	
	for (i = 0; i < 31; i++) {
		for (k = 0; k < 22; k+=2) {
			
			if (k == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
				gotoxy(CENTER - 2 , i);
				printf("｜");
			}else if (k == 18) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
				gotoxy(CENTER + WIDTH + 2, i);
				printf("｜");
			}
			if (i == 30) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
				gotoxy(CENTER + k, i);
				printf("―");
			} else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
				gotoxy(CENTER + k, i);
				printf("　");
			}
			if (i == 30 && k == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
				gotoxy(CENTER - 2, i);
				printf("└");
			} else if (i==30 && k== 18) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
				gotoxy(CENTER + WIDTH + 2, i);
				printf("┘");
			}
		}
	}

}