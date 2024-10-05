#include "Head.h"
#include "GlobalValue.h"

//输出表格
void PrintGrid()
{
	system("cls");

	//打印分数
	cout << "目前分数：" << game.CurScore << endl;
	cout << "最高分数：" << statis.HighestScore << endl << endl;

	string Side{ "+" };
	for (uint i = 0; i < 4 * statis.size + 3; ++i)
		Side += ' ';

	//输出4行
	for (int x = 0; x < 4; ++x)
	{
		//顶部边框
		PrintLoop(Side, 4);
		cout << '+' << endl;

		//数字上方
		PrintLoop('\n', statis.size);

		//数字
		for (int y = 0; y < 4; ++y)
		{
			PrintLoop(' ', GetSpaceLeft(game.grid[x][y]));
			if (game.grid[x][y] != 0)
				cout << game.grid[x][y];
			else
				cout << ' ';
			PrintLoop(' ', GetSpaceRight(game.grid[x][y]));
		}

		//数字下方
		cout << endl;
		PrintLoop('\n', statis.size);
	}
	//底部边框
	PrintLoop(Side, 4);
	cout << '+' << endl << endl;
}

//重复cout
void PrintLoop(string str, int time)
{
	for (int i = 1; i <= time; ++i)
		cout << str;
}
void PrintLoop(char letter, int time)
{
	for (int i = 1; i <= time; ++i)
		cout << letter;
}

//获取位数
//其中0的位数为0
int GetDigit(block x)
{
	if (x == 0)
		return 0;
	else
	{
		for (int n = 1;; ++n)
		{
			int digit_bas = (int)pow(10, n);
			if (x == (x % digit_bas))
			{
				return n;
			}
			else if (x % digit_bas == 0)
			{
				return n + 1;
			}
		}
	}
}

//左侧空格数获取
int GetSpaceLeft(block x)
{
	if (GetDigit(x) == 1 || GetDigit(x) == 0)//一位数
		return 2 * statis.size + 2;
	else if (x % 2 == 0)//偶数
		return 2 * statis.size + 2 - ((int)(0.5 * GetDigit(x)) - 1);
	else//奇数
		return 2 * statis.size + 2 - (int)(0.5 * (GetDigit(x) - 1));
}

//右侧空格数获取
int GetSpaceRight(block x)
{
	if (GetDigit(x) == 1 || GetDigit(x) == 0)//一位数
		return 2 * statis.size + 2;
	else if (x % 2 == 0)//偶数
		return 2 * statis.size + 1 - (int)(0.5 * GetDigit(x));
	else//奇数
		return 2 * statis.size + 1 - ((int)(0.5 * (GetDigit(x)) - 1));
}

