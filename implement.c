#include"标头.h"

void init()
{
	x = 0; y = 4;
	left = 0; right = 15;
	top = 0; bottom = 20;
	velocity_x = 1;
	velocity_y = 1;
	i = 0; j = 0;
	position_x = bottom - 1; position_y = right / 2;
	r = 4; score = 0;
	srand(time(0));
	target_x = rand() % (bottom - 12);
	target_y = rand() % (right + 1);
}

void show()
{

	gotoxy(0, 0);
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//取消光标显示
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	
	
	for (i = 0; i <= bottom; i++)//对于高度方向，当到最低端时输出底部边界
	{
		for (j = 0; j <= right; j++)//对于宽度的方向，只有到了小球的方向才输出小球，并且在最右边输出边界
		{
			if (i == x && j == y)
				printf("o");
			else if (j == right)
				printf(" |");
			else if (i == bottom)
				printf("-");
			else if (i == position_x && position_y - r <= j
				&& j <= position_y + r)
				printf("*");
			else if (i == target_x && j == target_y)
				printf("@");
			else
				printf(" ");
		}
		printf("\n");
	}

	printf("得分数：%d\n", score);
}

void WithOutInput()
{
	x += velocity_x;
	y += velocity_y;

	if (x == top) velocity_x = -velocity_x;
	if (y == right || y == left) velocity_y = -velocity_y;
	if (x == position_x - 1&& position_y - r <= y
		&& y <= position_y + r) velocity_x = -velocity_x;

	if (x == target_x && y == target_y)
	{
		target_x = rand() % (bottom - 12);
		target_y = rand() % (right + 1);

	}

	if (x == bottom)
	{
		printf("游戏结束！您共得分%d\n", score);
		system("pause");
		exit(0);
	}

	Sleep(50);
}

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void WithInput()
{
	if (_kbhit())
	{
		char ch = _getch();//不必输入回车
		if (ch == 'a')
		{
			if (position_y - r > left)
				position_y--;
		}
		if (ch == 'd')
		{
			if (position_y + r < right)
				position_y++;
		}
	}
}
